#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/pid.h>
#include <linux/path.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Himanshu_2021464");
MODULE_DESCRIPTION("A kernel module that prints the PID, UID, PGID, and command path of a given process");

static int pid = 0;
module_param(pid, int, 0);
MODULE_PARM_DESC(pid, "Process ID of the process to print information for");

static int __init print_process_info_init(void)
{
struct task_struct *task;
struct pid *pid_struct;
struct path *path;
char *command_path;

printk(KERN_INFO "print_process_info: Initializing module\n");

pid_struct = find_get_pid(pid);
task = pid_task(pid_struct, PIDTYPE_PID);

if (task == NULL)
{
    printk(KERN_INFO "print_process_info: Could not find task with PID %d\n", pid);
    return -1;
}

get_task_comm(command_path, task);
get_task_exe_path(task, &path);
d_path(&path->dentry, &path->mnt, command_path, PATH_MAX);
printk(KERN_INFO "Process UID: %d\n", task->pid);
printk(KERN_INFO "Process UID: %d\n", task->cred->uid);
printk(KERN_INFO "Process PGID: %d\n", task->group_leader->pgrp);
printk(KERN_INFO "Process command path: %s\n", command_path);

return 0;
}

static void __exit print_process_info_exit(void)
{
printk(KERN_INFO "print_process_info: Removing module\n");
}

module_init(print_process_info_init);
module_exit(print_process_info_exit);
