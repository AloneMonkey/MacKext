//
//  MachOUtils.h
//  MachOParser
//
//  Created by AloneMonkey on 2017/10/24.
//  Copyright © 2017年 AloneMonkey. All rights reserved.
//

#import <mach/vm_types.h>
#import <sys/types.h>
#import <sys/stat.h>
#import <sys/mman.h>
#import <mach-o/loader.h>
#import <mach-o/fat.h>
#import <mach-o/nlist.h>
#include <libkern/libkern.h>

#ifdef __LP64__
typedef struct mach_header_64 mach_header_t;
typedef struct segment_command_64 segment_command_t;
typedef struct section_64 section_t;
typedef struct nlist_64 nlist_t;
#define LC_SGMT LC_SEGMENT_64
#define MH_MAGIC_ MH_MAGIC_64
#else
typedef struct mach_header mach_header_t;
typedef struct segment_command segment_command_t;
typedef struct section section_t;
typedef struct nlist nlist_t;
#define LC_SGMT LC_SEGMENT
#define MH_MAGIC_ MH_MAGIC
#endif

#define load_cmd struct load_command

typedef struct _section_info_t{
    section_t *section;
    vm_address_t addr;
}section_info_t;

typedef struct _segment_info_t{
    segment_command_t *segment;
    vm_address_t addr;
}segment_info_t;


/**
 查找load_command

 @param header macho头部地址
 @param cmd cmd
 @return 返回结构
 */
load_cmd* macho_find_load_command(mach_header_t* header, uint32_t cmd);


/**
 查找segment

 @param header macho头部地址
 @param segname segment名字
 @return 返回结构
 */
segment_command_t* macho_find_segment(mach_header_t* header,const char *segname);


/**
  查找section

 @param header macho头部地址
 @param segname segment名字
 @param secname section名字
 @return 返回结构
 */
section_t* macho_find_section(mach_header_t* header, const char *segname, const char *secname);


/**
 查找符号

 @param header macho头部地址
 @param name 符号名
 @return 返回地址
 */
void* macho_find_symbol(mach_header_t* header, const char *name);

/**
 查找内核模块加载的基地址

 @return 加载的基地址
 */
mach_header_t* find_kernel_header(void);

void* kernel_find_symbol(const char* symbol);
