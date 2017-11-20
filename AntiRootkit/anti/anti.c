//
//  anti.c
//  AntiRootkit
//
//  Created by AloneMonkey on 2017/11/16.
//  Copyright © 2017年 AloneMonkey. All rights reserved.
//

#include <mach/mach_types.h>
#include <pexpert/pexpert.h>
#include "anti.h"
#include "sysent.h"
#include "syscall.h"
#include "cpu_protections.h"
#include <sys/attr.h>
#include "proc.h"
#include "define.h"

/* ptrace request */
#define PT_ATTACH               10
#define PT_DENY_ATTACH          31

/* flags for checking which functions has been hooked */
#define    HK_PTRACE        0x0001
#define    HK_SYSCTL        0x0002
#define    HK_KILL          0x0004

extern struct sysent *g_sysent_table;

uint16_t g_hooked_functions;

int (*sys_ptrace)(struct proc *, struct ptrace_args *, int *);
int (*sys_sysctl)(struct proc *, struct __sysctl_args *, int *);
static int ar_ptrace(struct proc *, struct ptrace_args *, int *);
static int ar_sysctl(struct proc *, struct __sysctl_args *, int *);

#pragma mark Functions to install and remove sysent hooks

kern_return_t anti_ptrace(int cmd){
    /* Mountain Lion (10.8+) moved sysent[] to read-only section */
    kwrite_on();
    
    /*
     * we check if the syscalls had been already assigned, because we get kernel panic if we overwrite the syscall with same function
     */
    if(cmd == DISABLE && g_sysent_table[SYS_ptrace].sy_call != (sy_call_t *)sys_ptrace){
        if(sys_ptrace != NULL){
            /* restore pointer to the original function */
            g_sysent_table[SYS_ptrace].sy_call = (sy_call_t *)sys_ptrace;
            
            /* remove the flag that indicates the hooked status */
            g_hooked_functions &= ~HK_PTRACE;
        }
    }else if(cmd == ENABLE && !(g_hooked_functions & HK_PTRACE)){
        /* save address of the real function */
        sys_ptrace = (void *)g_sysent_table[SYS_ptrace].sy_call;
        
        /* hook the syscall by replacing the pointer in sysent */
        g_sysent_table[SYS_ptrace].sy_call = (sy_call_t *)ar_ptrace;
        
        /* we set our global variable g_hooked_functions to know this function has been hooked */
        g_hooked_functions |= HK_PTRACE;
    }
    
    kwrite_off();
    
    return KERN_SUCCESS;
}

kern_return_t anti_sysctl(int cmd)
{
    kwrite_on();
    
    if(cmd == DISABLE && g_sysent_table[SYS___sysctl].sy_call != (sy_call_t *)sys_sysctl) {
        if(sys_sysctl != NULL) {
            g_sysent_table[SYS___sysctl].sy_call = (sy_call_t *)sys_sysctl;
            
            g_hooked_functions &= ~HK_SYSCTL;
        } else {
            return KERN_FAILURE;
        }
    } else if(cmd == ENABLE && !(g_hooked_functions & HK_SYSCTL)) {
        sys_sysctl = (void *)g_sysent_table[SYS___sysctl].sy_call;
        
        g_sysent_table[SYS___sysctl].sy_call = (sy_call_t *)ar_sysctl;
        
        g_hooked_functions |= HK_SYSCTL;
    }
    
    kwrite_off();
    
    return KERN_SUCCESS;
}

#pragma mark ar functions

/*
 *    This will allow to bypass the PT_DENY_ATTACH and P_LNOATTACH (flag that denies dtrace tracing)
 */
static int ar_ptrace(struct proc *p, struct ptrace_args *uap, int *retv)
{
    /* retrieve pid using exported functions so we don't need definition of struct proc */
    pid_t pid = proc_pid(p);
    char processname[MAXCOMLEN+1] = {0};
    /* verify if it's a PT_DENY_ATTACH request and fix for all processes that call it */
    if(uap->req == PT_DENY_ATTACH) {
        proc_name(pid, processname, sizeof(processname));
        LOG_INFO("Blocked PT_DENY_ATTACH/P_LNOATTACH in PID %d (%s)", pid, processname);
        return 0;
    } // for the extra tricky ones : simulate exact behavior
    else if (uap->req == PT_ATTACH && uap->pid == pid){
        proc_signal(pid, SIGSEGV);
        return 22;
    }
    
    return sys_ptrace(p, uap, retv);
}

/*
 *    Hooked sysctl so we can intercept a debug call
 *    "Q:  How do I determine if I'm being run under the debugger?" http://developer.apple.com/library/mac/qa/qa1361/_index.html
 *
 *    It also hides the process specified by g_pid from 'ps', 'top' and 'Activity Monitor'
 *
 *    From http://thc.org/papers/bsdkern.html#II.3.1.
 *
 */
static int ar_sysctl(struct proc *p, struct __sysctl_args *uap, int *retv)
{
    int mib[4];
    char processname[MAXCOMLEN+1] = {0};
    int ret = sys_sysctl(p, uap, retv);
    int err = 0;
    
    err = copyin(uap->name, &mib, sizeof(mib));
    if (err != 0){
        LOG_ERROR("Copyin failed: %d.", err);
        return ret;
    }
    
    if(mib[0] == CTL_KERN && mib[1] == KERN_PROC && mib[2] == KERN_PROC_PID) {
        // copy process name
        pid_t pid = proc_pid(p);
        proc_name(pid, processname, sizeof(processname));
        if(uap->old != USER_ADDR_NULL) {
            // is it a 64bits process?
            if (proc_is64bit(p) == 1){
                struct user64_kinfo_proc kpr = {0};
                // then copy the result from the destination buffer ( *oldp from sysctl call) to kernel space so we can edit
                err = copyin(uap->old, &kpr, sizeof(kpr));
                if (err != 0 ){
                    LOG_ERROR("Copyin failed: %d.", err);
                    return ret;
                }
                if ( (kpr.kp_proc.p_flag & P_TRACED) != 0 ) {
                    LOG_INFO("Detected sysctl anti-debug trick requested by 64 bits process with PID %d (%s)! Patching...", pid, processname);
                    kpr.kp_proc.p_flag = kpr.kp_proc.p_flag & ~P_TRACED;
                    // copy back to user space the modified structure
                    // int copyout(const void *kaddr, void *uaddr, size_t len);
                    // copyout() Copies len bytes of data from the kernel-space address kaddr to the user-space address uaddr.
                    err = copyout(&kpr, uap->old, sizeof(kpr));
                    if (err != 0){
                        LOG_ERROR("Copyout failed: %d.", err);
                        return ret;
                    }
                }
            }
        }
    }
    
    return ret;
}

kern_return_t set_orig_sysent(void)
{
    if(g_hooked_functions & HK_PTRACE) {
        anti_ptrace(DISABLE);
    }
    
    if(g_hooked_functions & HK_SYSCTL) {
        anti_sysctl(DISABLE);
    }
    
    return KERN_SUCCESS;
}

kern_return_t set_hooked_sysent(void)
{
    if(!(g_hooked_functions & HK_PTRACE)) {
        anti_ptrace(ENABLE);
    }
    
    if(!(g_hooked_functions & HK_SYSCTL)) {
        anti_sysctl(ENABLE);
    }
    
    return KERN_SUCCESS;
}
