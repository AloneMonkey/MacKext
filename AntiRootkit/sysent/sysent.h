//
//  sysent.h
//  HelloWorld
//
//  Created by AloneMonkey on 2017/11/15.
//  Copyright © 2017年 AloneMonkey. All rights reserved.
//

#ifndef sysent_h
#define sysent_h

#include <libkern/libkern.h>

typedef int32_t sy_call_t(struct proc *, void *, int *);


typedef void sy_munge_t(void *); // For OS X 10.10 and above
typedef void sy_munge_t_mavericks(const void *, void *); // For OS X 10.9

struct sysent {          // system call table, OS X 10.10 and above
    sy_call_t *sy_call;    // implementing function
    sy_munge_t *sy_arg_munge32; // system call arguments munger for 32-bit process
    int32_t  sy_return_type; // system call return types
    int16_t  sy_narg;      // number of args
    uint16_t sy_arg_bytes; // Total size of args in bytes for 32-bit system calls
};

struct sysent_mavericks {// system call table, OS X 10.9
    sy_call_t *sy_call;    // implementing function
    sy_munge_t_mavericks *sy_arg_munge32; // arguments munger for 32-bit process
    sy_munge_t_mavericks *sy_arg_munge64; // arguments munger for 64-bit process
    int32_t  sy_return_type; // system call return types
    int16_t  sy_narg;      // number of args
    uint16_t sy_arg_bytes; // Total size of args in bytes for 32-bit system calls
};

struct sysent * find_sysent_table(void);

#endif /* sysent_h */
