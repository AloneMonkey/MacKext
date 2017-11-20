//
//  version.c
//  HelloWorld
//
//  Created by AloneMonkey on 2017/11/15.
//  Copyright © 2017年 AloneMonkey. All rights reserved.
//

#include "version.h"
#include <libkern/libkern.h>
#include <libkern/sysctl.h>
#include <IOKit/IOLib.h>

char *gOSVersionString = NULL;
size_t gOSVersionStringLength = 0;

extern int atoi(const char *str);

int32_t OSX_Version()
{
    static int32_t version = -1;
    if (version != -1) {
        return version;
    }
    
    version = 0;
    sysctlbyname("kern.osrelease", NULL, &gOSVersionStringLength, NULL, 0);
    gOSVersionString = (char *) IOMalloc(gOSVersionStringLength);
    char *version_string = (char *) IOMalloc(gOSVersionStringLength);
    if (!gOSVersionString || !version_string) {
        return version;
    }
    if (sysctlbyname("kern.osrelease", gOSVersionString,
                     &gOSVersionStringLength, NULL, 0) < 0)
    {
        IOFree(version_string, gOSVersionStringLength);
        return version;
    }
    strncpy(version_string, gOSVersionString, gOSVersionStringLength);
    
    char *version_string_iterator = version_string;
    const char *part; int i;
    for (i = 0; i < 3; ++i) {
        //com.apple.kpi.dsep
        part = strsep(&version_string_iterator, ".");
        if (!part) {
            break;
        }
        version += (atoi(part) << ((2 - i) * 4));
    }
    
    IOFree(version_string, gOSVersionStringLength);
    return version;
}

bool OSX_Mavericks()
{
    return ((OSX_Version() & 0xFF00) == MAC_OS_X_VERSION_10_9_HEX);
}

bool OSX_ElCapitan()
{
    return ((OSX_Version() & 0xFF00) == MAC_OS_X_VERSION_10_11_HEX);
}

bool macOS_Sierra()
{
    return ((OSX_Version() & 0xFF00) == MAC_OS_X_VERSION_10_12_HEX);
}
