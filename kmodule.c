#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/syscalls.h>
#include <linux/sched.h>
#include <linux/uaccess.h>

#define __NR_read_task_struct 356

struct task_struct_data {
  pid_t pid;
  uid_t uid;
  pid_t pgid;
  char comm[TASK_COMM_LEN];
};

asmlinkage long sys_read_task_struct(pid_t pid, struct task_struct_data *data)
{
  struct task_struct *task;

  task = pid_task(find_vpid(pid), PIDTYPE_PID);
  if (!task)
    return -EINVAL;

  data->pid = task->pid;
  data->uid = task->cred->uid;
  data->pgid = task->tgid;
  get_task_comm(data->comm, task);

  return 0;
}

static int __init init_sys_read_task_struct(void)
{
  printk("installed new sys_read_task_struct module\n");
  if (sysptr_read_task_struct == NULL)
    sysptr_read_task_struct = sys_read_task_struct;
  return 0;
}
static void  __exit exit_sys_read_task_struct(void)
{
  if (sysptr_read_task_struct != NULL)
    sysptr_read_task_struct = NULL;
  printk("removed sys_read_task_struct module\n");
}

module_init(init_sys_read_task_struct);
module_exit(exit_sys_read_task_struct);

MODULE_LICENSE("GPL");
