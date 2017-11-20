//
//  sysent.c
//  HelloWorld
//
//  Created by AloneMonkey on 2017/11/15.
//  Copyright © 2017年 AloneMonkey. All rights reserved.
//

#include "sysent.h"
#include <mach/mach_types.h>
#include <mach-o/loader.h>
#include <mach-o/nlist.h>
#include "version.h"
#include "macho_utils.h"

struct sysent *g_sysent_table = NULL;

struct sysent * find_sysent_table()
{
    if (g_sysent_table) {
        return g_sysent_table;
    }
    
    mach_header_t* kernel_header = find_kernel_header();
    
    if (!kernel_header) {
        return NULL;
    }
    
    // The first three entries of the sysent table point to these functions.
    sy_call_t *nosys = (sy_call_t *) kernel_find_symbol("_nosys");
    sy_call_t *exit = (sy_call_t *) kernel_find_symbol("_exit");
    sy_call_t *fork = (sy_call_t *) kernel_find_symbol("_fork");
    if (!nosys || !exit || !fork) {
        return NULL;
    }
    
    const char *data_segment_name;
    const char *const_section_name;
    if (macOS_Sierra()) {
        data_segment_name = "__CONST";
        const_section_name = "__constdata";
    } else {
        data_segment_name = "__DATA";
        const_section_name = "__const";
    }
    
    section_t* section = macho_find_section(kernel_header, data_segment_name, const_section_name);
    
    if(!section){
        return NULL;
    }
    
    vm_offset_t offset;
    for (offset = 0; offset < section->size; offset += 16) {
        struct sysent *table = (struct sysent *) (section->addr + offset);
        if (table->sy_call != nosys) {
            continue;
        }
        vm_offset_t next_entry_offset = sizeof(struct sysent);
        if (OSX_Mavericks()) {
            next_entry_offset = sizeof(struct sysent_mavericks);
        }
        struct sysent *next_entry = (struct sysent *)
        ((vm_offset_t)table + next_entry_offset);
        if (next_entry->sy_call != exit) {
            continue;
        }
        next_entry = (struct sysent *)
        ((vm_offset_t)next_entry + next_entry_offset);
        if (next_entry->sy_call != fork) {
            continue;
        }
        
        g_sysent_table = table;
        return g_sysent_table;
    }
    
    return NULL;
}
