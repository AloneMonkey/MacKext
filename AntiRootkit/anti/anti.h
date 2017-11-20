//
//  anti.h
//  AntiRootkit
//
//  Created by AloneMonkey on 2017/11/16.
//  Copyright © 2017年 AloneMonkey. All rights reserved.
//

#ifndef anti_h
#define anti_h

#include "sysproto.h"

#define DISABLE    0
#define ENABLE    1

kern_return_t set_hooked_sysent(void);
kern_return_t set_orig_sysent(void);

#endif /* anti_h */
