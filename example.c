/* 内核模块必须包含的头文件 */
#include<linux/module.h>
 
/* 加载函数：__init表示该函数只能在初始化期间使用，模块装载完后内核就会空间回收，释放内存*/
static int __init hello_init(void){
    printk(KERN_INFO "HELLO LINUX MODULE\n");
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
MODULE_VERSION("V1.0")  /* 版本号 */