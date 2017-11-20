//
//  define.h
//  AntiRootkit
//
//  Created by AloneMonkey on 2017/11/17.
//  Copyright © 2017年 AloneMonkey. All rights reserved.
//

#ifndef define_h
#define define_h

#define LOG_ERROR(fmt, ...) printf("[ERROR] " fmt "\n", ## __VA_ARGS__)
#define LOG_INFO(fmt, ...) printf("[INFO] " fmt "\n", ## __VA_ARGS__)

#endif /* define_h */
