/* 内核模块必须包含的头文件 */
#include<linux/module.h>
#include <linux/notifier.h>
#include <linux/reboot.h>

/* 加载函数：__init表示该函数只能在初始化期间使用，模块装载完后内核就会空间回收，释放内存*/
static int your_handler (struct notifier_block *self, unsigned long val, void *data)
{
    switch (val) {
        case SYS_HALT:
            printk(KERN_INFO "HELLO SYS HALT\n");
            break;
        case SYS_RESTART:
            printk(KERN_INFO "HELLO SYS RESTART\n");
            break;
        case SYS_POWER_OFF:
            printk(KERN_INFO "HELLO SYS POWER OFF\n");
            break;
    }
    return 0;
}

static struct notifier_block your_notifier = {
    .notifier_call = your_handler,
};


static int __init hello_init(void){
    printk(KERN_INFO "HELLO LINUX MODULE\n");
    register_reboot_notifier(&your_notifier);
    return 0;
}
 
/* 卸载函数 */
static void __exit hello_exit(void){
    printk(KERN_INFO "GOODBYE LINUX MODULE\n");
}


 
/* 宏：指明初始化函数和清除函数 */
module_init(hello_init);
module_exit(hello_exit);
 
/* 描述性定义*/
MODULE_LICENSE("Dual BSD/GPL");  /* 许可协议 */
MODULE_AUTHOR("LJM");  /* 作者 */
MODULE_VERSION("V1.0");