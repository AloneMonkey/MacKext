//
//  version.h
//  HelloWorld
//
//  Created by AloneMonkey on 2017/11/15.
//  Copyright © 2017年 AloneMonkey. All rights reserved.
//

#ifndef version_h
#define version_h

#include <mach/mach_types.h>

#define MAC_OS_X_VERSION_10_9_HEX  0x00000D00
#define MAC_OS_X_VERSION_10_10_HEX 0x00000E00
#define MAC_OS_X_VERSION_10_11_HEX 0x00000F00
#define MAC_OS_X_VERSION_10_12_HEX 0x00001000

int32_t OSX_Version(void);

bool OSX_Mavericks(void);

bool OSX_ElCapitan(void);

bool macOS_Sierra(void);

#endif /* version_h */
