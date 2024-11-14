#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include "hello1.h"

MODULE_AUTHOR("IO-24 Sots Ivan");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training - Module 2");
MODULE_LICENSE("Dual BSD/GPL");

static uint param = 1;
module_param(param, uint, 0444);
MODULE_PARM_DESC(param, "Number of times to print 'Hello, world!' message");

static int __init hello2_init(void)
{
	pr_info("Hello2 module loaded\n");

	if (param == 0 || (param >= 5 && param <= 10)) {
		pr_warn("Warning: param parameter is 0 or between 5 and 10. Continuing.\n");
	} else if (param > 10) {
		pr_err("Error: param parameter is greater than 10. Module not loaded.\n");
		return -EINVAL;
	}

	print_hello(param);
	return 0;
}

static void __exit hello2_exit(void)
{
	pr_info("Hello2 module unloaded\n");
}

module_init(hello2_init);
module_exit(hello2_exit);
