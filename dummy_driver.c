#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/stddef.h>
#include<linux/pci.h>
#include<linux/init.h>

///< The license type -- this affects runtime behavior
MODULE_LICENSE("GPL");

///< The author -- visible when you use modinfo
MODULE_AUTHOR("Mushahid Hussain");

///< The description -- see modinfo
MODULE_DESCRIPTION("A simple kernel moduel to look for a device given vendor id and the device id.\n");

///< The version of the module
MODULE_VERSION("0.1");


#define VENDOR_ID 0x10ec 
#define DEVICE_ID 0x8168 

static int __init dummy_driver_init_module(void)
{
	struct pci_dev * dev =NULL;
	if((dev = pci_get_device(VENDOR_ID,DEVICE_ID,dev)))
	   {
	   	printk("Found the device!\n");
	   }	   
	   else
	   {
	   	printk("Coudn't find the device");
	   }
	return 0;
}


static void __exit dummy_driver_cleanup_module(void)
{
	printk("Unloading the module.\n");

}


module_init(dummy_driver_init_module);
module_exit(dummy_driver_cleanup_module);

