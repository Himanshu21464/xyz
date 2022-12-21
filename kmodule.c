#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/syscalls.h>
#include <linux/unistd.h>

#define __NR_printk_syscall 452

asmlinkage long sys_printk(char *string)
{
    printk(KERN_INFO "%s\n", string);
    return 0;
}

static int __init syscall_init(void)
{
    sys_call_table[__NR_printk_syscall] = (unsigned long)sys_printk;
    return 0;
}

static void __exit syscall_exit(void)
{
    sys_call_table[__NR_printk_syscall] = (unsigned long)NULL;
}

module_init(syscall_init);
module_exit(syscall_exit);

MODULE_LICENSE("GPL");
