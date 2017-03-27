#include <linux/module.h>
#include <linux/kernel.h>

int init_module(void){
	printk(KERN_INFO "Installing module from file 'start'\n");
	return 0;
}