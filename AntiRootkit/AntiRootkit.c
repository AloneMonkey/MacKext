//
//  AntiRootkit.c
//  AntiRootkit
//
//  Created by AloneMonkey on 2017/11/15.
//  Copyright © 2017年 AloneMonkey. All rights reserved.
//

#include <mach/mach_types.h>
#include <IOKit/IOLib.h>
#include "cpu_protections.h"
#include "sysent.h"
#include "syscall.h"
#include "anti.h"

kern_return_t AntiRootkit_start(kmod_info_t * ki, void *d);
kern_return_t AntiRootkit_stop(kmod_info_t *ki, void *d);

kern_return_t AntiRootkit_start(kmod_info_t * ki, void *d)
{
    asm("int $3");
    IOLog("HelloWorld_start by IOLog\n");
    printf("HelloWorld_start...\n");
    
    kprintf("HelloWorld_start by kprintf\n");
    
    if(!find_sysent_table()){
        return KERN_FAILURE;
    }

    set_hooked_sysent();
    
    return KERN_SUCCESS;
}

kern_return_t AntiRootkit_stop(kmod_info_t *ki, void *d)
{
    IOLog("HelloWorld_stop by IOLog\n");
    printf("HelloWorld_stop...\n");
    
    set_orig_sysent();
    
    return KERN_SUCCESS;
}
