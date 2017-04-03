#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#define DRIVER_AUTHOR "Peter Salzman"
#define DRIVER_DESC "A basic driver"


static int __init hello_V2_init(void){
	printk(KERN_INFO "Installing helloV2\n");
	return 0;
}

static void __exit hello_V2_exit(void){
	printk(KERN_INFO "Uninstalling helloV2\n");
}

module_init(hello_V2_init);
module_exit(hello_V2_exit);

/*
* Get rid of taint message
*/
MODULE_LICENSE("GPL");

/*
* Provide data of author and module
*/
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);
