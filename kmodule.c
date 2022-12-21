#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/syscalls.h>

static unsigned long **aquire_sys_call_table(void) {
    unsigned long int offset = PAGE_OFFSET;
    unsigned long **sct;

    while (offset < ULLONG_MAX) {
        sct = (unsigned long **)offset;

        if (sct[__NR_close] == (unsigned long *) sys_close)
            return sct;

        offset += sizeof(void *);
    }

    return NULL;
}

static void disable_page_protection(void) {
    unsigned long value;
    asm volatile("mov %%cr0, %0" : "=r" (value));

    if(!(value & 0x00010000))
        return;

    asm volatile("mov %0, %%cr0" : : "r" (value & ~0x00010000));
}

static void enable_page_protection(void) {
    unsigned long value;
    asm volatile("mov %%cr0, %0" : "=r" (value));

    if((value & 0x00010000))
        return;

    asm volatile("mov %0, %%cr0" : : "r" (value | 0x00010000));
}

static int __init syscall_module_init(void) {
    sys_call_table = aquire_sys_call_table();

    if (!sys_call_table) {
        return -1;
    }

    disable_page_protection();
    ref_sys_call_table = (void *)sys_call_table[__NR_close];
    sys_call_table[__NR_close] = (unsigned long *)new_sys_call_table;
    enable_page_protection();

    return 0;
}

static void __exit syscall_module_exit(void) {
    if (!sys_call_table) {
        return;
    }

    disable_page_protection();
    sys_call_table[__NR_close] = (unsigned long *)ref_sys_call_table;
    enable_page_protection();
}

module_init(syscall_module_init);
module_exit(syscall_module_exit);


