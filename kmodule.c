#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/syscalls.h>

asmlinkage long custom_syscall(void)
{
printk(KERN_INFO "Custom syscall called!\n");
return 0;
}

static unsigned long **find_sys_call_table(void)
{
unsigned long **sys_call_table;
unsigned long int i;

for (i = (unsigned long int) sys_close; i < (unsigned long int) &loops_per_jiffy; i += sizeof(void *))
{
sys_call_table = (unsigned long **) i;

if (sys_call_table[__NR_close] == (unsigned long *) sys_close)
  return sys_call_table;
}

return NULL;
}

static void disable_page_protection(void)
{
unsigned long value;
asm volatile("mov %%cr0, %0" : "=r" (value));

if(!(value & 0x00010000))
return;

asm volatile("mov %0, %%cr0" : : "r" (value & ~0x00010000));
}

static void enable_page_protection(void)
{
unsigned long value;
asm volatile("mov %%cr0, %0" : "=r" (value));

if((value & 0x00010000))
return;

asm volatile("mov %0, %%cr0" : : "r" (value | 0x00010000));
}

static int __init custom_syscall_init(void)
{
unsigned long **sys_call_table;

sys_call_table = find_sys_call_table();
if (!sys_call_table)
return -1;

disable_page_protection();
sys_call_table[__NR_custom_syscall] = (unsigned long *) custom_syscall;
enable_page_protection();

printk(KERN_INFO "Custom syscall installed!\n");
return 0;
}

static void __exit custom_syscall_exit(void)
{
unsigned long **sys_call_table;

sys_call_table = find_sys_call_table();
if (!sys_call_table)
return;

disable_page_protection();
sys_call_table[__NR_custom_syscall] = (unsigned long *) NULL;
enable_page_protection();

printk(KERN_INFO "Custom syscall removed!\n");
}

module_init(custom_syscall_init);
module_exit(custom_syscall_exit);
MODULE_LICENSE("GPL");



