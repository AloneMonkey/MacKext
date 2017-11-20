#import "macho_utils.h"
#include "version.h"

// /System/Library/Kernels TEXT vmaddr
#define KERNEL_HEADER_ADDR 0xFFFFFF8000200000

vm_offset_t g_kernel_slide = 0;

typedef struct pmap *pmap_t;
extern pmap_t kernel_pmap;
//com.apple.kpi.unsupported
extern ppnum_t pmap_find_phys(pmap_t pmap, addr64_t va);
extern void vm_kernel_unslide_or_perm_external(vm_offset_t addr,
                                                   vm_offset_t *up_addr);

mach_header_t *g_kernel_header = NULL;

load_cmd* macho_find_load_command(mach_header_t* header, uint32_t cmd){
    load_cmd *lc;
    vm_address_t cur = (vm_address_t)header + sizeof(mach_header_t);
    for (uint i = 0; i < header->ncmds; i++,cur += lc->cmdsize) {
        lc = (load_cmd*)cur;
        if(lc->cmd == cmd){
            return lc;
        }
    }
    return NULL;
}

segment_command_t* macho_find_segment(mach_header_t* header,const char *segname){
    segment_command_t *cur_seg_cmd;
    vm_address_t cur = (vm_address_t)header + sizeof(mach_header_t);
    for (uint i = 0; i < header->ncmds; i++,cur += cur_seg_cmd->cmdsize) {
        cur_seg_cmd = (segment_command_t*)cur;
        if(cur_seg_cmd->cmd == LC_SGMT){
            if(!strcmp(segname,cur_seg_cmd->segname)){
                return cur_seg_cmd;
            }
        }
    }
    return NULL;
}

section_t* macho_find_section(mach_header_t* header, const char *segname, const char *secname){
    segment_command_t *cur_seg_cmd;
    vm_address_t cur = (vm_address_t)header + sizeof(mach_header_t);
    for (uint i = 0; i < header->ncmds; i++,cur += cur_seg_cmd->cmdsize) {
        cur_seg_cmd = (segment_command_t*)cur;
        if(cur_seg_cmd->cmd == LC_SGMT){
            if(!strcmp(segname,cur_seg_cmd->segname)){
                for (uint j = 0; j < cur_seg_cmd->nsects; j++) {
                    section_t *sect = (section_t *)(cur + sizeof(segment_command_t)) + j;
                    if(!strcmp(secname, sect->sectname)){
                        return sect;
                    }
                }
            }
        }
    }
    return NULL;
}

// The running kernel contains a valid symbol table.  We can use this to find
// the address of any "external" kernel symbol, including those considered
// "private".  'symbol' should be exactly what's listed in the symbol table,
// including the "extra" leading underscore.
void* macho_find_symbol(mach_header_t* header, const char *name){
    segment_command_t* first = (segment_command_t*) macho_find_load_command(header, LC_SGMT);
    segment_command_t* linkedit_segment = macho_find_segment(header, SEG_LINKEDIT);
    struct symtab_command* symtab_cmd = (struct symtab_command*)macho_find_load_command(header, LC_SYMTAB);
    
    vm_address_t vmaddr_slide = (vm_address_t)header - (vm_address_t)first->vmaddr;
    
    uintptr_t linkedit_base = (uintptr_t)vmaddr_slide + linkedit_segment->vmaddr - linkedit_segment->fileoff;
    nlist_t *symtab = (nlist_t *)(linkedit_base + symtab_cmd->symoff);
    char *strtab = (char *)(linkedit_base + symtab_cmd->stroff);
    
    for (int i = 0; i < symtab_cmd->nsyms; i++) {
        if (symtab[i].n_value && !strcmp(name,&strtab[symtab[i].n_un.n_strx])) {
            return (void*) (uint64_t) (symtab[i].n_value + vmaddr_slide);
        }
    }
    
    return NULL;
}

void* kernel_find_symbol(const char* symbol){
    mach_header_t* kernel_header = find_kernel_header();
    return macho_find_symbol(kernel_header, symbol);
}

// Find the address of the kernel's Mach header.
mach_header_t* find_kernel_header(){
    
    if (g_kernel_header) {
        return g_kernel_header;
    }
    
#if (MAC_OS_X_VERSION_MAX_ALLOWED / 100) >= (MAC_OS_X_VERSION_10_11 / 100)
    // vm_kernel_unslide_or_perm_external() is only available on OS X 10.11 and up.
    if (OSX_ElCapitan() || macOS_Sierra()) {
        vm_offset_t func_address = (vm_offset_t) vm_kernel_unslide_or_perm_external;
        vm_offset_t func_address_unslid = 0;
        vm_kernel_unslide_or_perm_external(func_address, &func_address_unslid);
        g_kernel_slide = func_address - func_address_unslid;
    } else {
#endif
        bool kernel_header_found = false;
        vm_offset_t slide;
        // The 0x10000 increment was determined by trial and error.
        for (slide = 0; slide < 0x100000000; slide += 0x10000) {
            addr64_t addr = KERNEL_HEADER_ADDR + slide;
            // pmap_find_phys() returns 0 if 'addr' isn't a valid address.
            if (!pmap_find_phys(kernel_pmap, addr)) {
                continue;
            }
            struct mach_header_64 *header = (struct mach_header_64 *) addr;
            if ((header->magic != MH_MAGIC_64) ||
                (header->cputype != CPU_TYPE_X86_64 ) ||
                (header->cpusubtype != CPU_SUBTYPE_I386_ALL) ||
                (header->filetype != MH_EXECUTE) ||
                (header->flags != (MH_NOUNDEFS | MH_PIE)))
            {
                continue;
            }
            g_kernel_slide = slide;
            kernel_header_found = true;
            break;
        }
        if (!kernel_header_found) {
            return false;
        }
#if (MAC_OS_X_VERSION_MAX_ALLOWED / 100) >= (MAC_OS_X_VERSION_10_11 / 100)
    }
#endif
    
    g_kernel_header = (mach_header_t *) (KERNEL_HEADER_ADDR + g_kernel_slide);
    
    return g_kernel_header;
}
