#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xbca7617b, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x7613cc26, __VMLINUX_SYMBOL_STR(usbnet_resume) },
	{ 0x90cedd53, __VMLINUX_SYMBOL_STR(usbnet_suspend) },
	{ 0xc753cb13, __VMLINUX_SYMBOL_STR(usbnet_disconnect) },
	{ 0x46b28377, __VMLINUX_SYMBOL_STR(usbnet_probe) },
	{ 0x33a16973, __VMLINUX_SYMBOL_STR(usb_deregister) },
	{ 0x2ce49fe2, __VMLINUX_SYMBOL_STR(usb_register_driver) },
	{ 0xa2547f4c, __VMLINUX_SYMBOL_STR(mii_nway_restart) },
	{ 0x6a94909c, __VMLINUX_SYMBOL_STR(usbnet_get_endpoints) },
	{ 0xfa2a45e, __VMLINUX_SYMBOL_STR(__memzero) },
	{ 0xe4a48145, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0x39aa72a, __VMLINUX_SYMBOL_STR(usb_submit_urb) },
	{ 0xd87357da, __VMLINUX_SYMBOL_STR(usb_alloc_urb) },
	{ 0xd0ef25d2, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0x53493e7a, __VMLINUX_SYMBOL_STR(usb_control_msg) },
	{ 0xec3a9034, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0xdb2e6e9e, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x8731782a, __VMLINUX_SYMBOL_STR(netif_carrier_off) },
	{ 0xf2d093b6, __VMLINUX_SYMBOL_STR(usbnet_defer_kevent) },
	{ 0x583574c7, __VMLINUX_SYMBOL_STR(netif_carrier_on) },
	{ 0x6eb1b593, __VMLINUX_SYMBOL_STR(dev_err) },
	{ 0x1a8bca44, __VMLINUX_SYMBOL_STR(skb_trim) },
	{ 0x4dd48fd0, __VMLINUX_SYMBOL_STR(skb_pull) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x65fde753, __VMLINUX_SYMBOL_STR(usb_free_urb) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xc3be17d4, __VMLINUX_SYMBOL_STR(mii_ethtool_gset) },
	{ 0xecc11826, __VMLINUX_SYMBOL_STR(mii_check_media) },
	{ 0x2e5810c6, __VMLINUX_SYMBOL_STR(__aeabi_unwind_cpp_pr1) },
	{ 0xbee88bbd, __VMLINUX_SYMBOL_STR(__dev_kfree_skb_any) },
	{ 0x1b1c347c, __VMLINUX_SYMBOL_STR(skb_copy_expand) },
	{ 0xb1ad28e0, __VMLINUX_SYMBOL_STR(__gnu_mcount_nc) },
	{ 0xf7802486, __VMLINUX_SYMBOL_STR(__aeabi_uidivmod) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("usb:v1A86pE091d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v1A86pE092d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v1A86p8339d*dc*dsc*dp*ic*isc*ip*in*");

MODULE_INFO(srcversion, "44C147B96247EFCF9379D6C");
