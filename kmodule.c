#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/syscalls.h>
#include <linux/unistd.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/syscalls.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Shriya");
MODULE_DESCRIPTION("Kernel Module");
MODULE_VERSION("0.01");

int pid = 0;
module_param(pid,int,0);

static int __init kmodule_init(void)
{
    
 
 pid_t p1_pid ;
 uid_t p1_uid ;
 struct task_struct *p1;
 pid_t p1_pgid;
 
 p1 = pid_task(find_vpid(pid), PIDTYPE_PID);
  if(!p1){
        return -ESRCH;
    }

 
 p1_pid = p1->pid;
 p1_uid = p1->cred->uid.val;
 p1_pgid = p1->group_leader->pid;
 printk(KERN_INFO "comm: %s\n",p1->comm);
 printk(KERN_INFO "pid: %d\n",p1_pid);
 printk(KERN_INFO "uid: %d\n",p1_uid);
 printk(KERN_INFO "pgid: %d\n",p1_pgid);
 return 0;
}
static void __exit kmodule_exit(void) {
 printk(KERN_INFO "Module finished successfully\n");
}
module_init(kmodule_init);
module_exit(kmodule_exit);
