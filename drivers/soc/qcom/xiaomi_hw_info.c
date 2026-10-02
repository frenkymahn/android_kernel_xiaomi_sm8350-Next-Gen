#include <linux/types.h>
#include <linux/notifier.h>
#include <linux/export.h>
#include <linux/init.h>

static BLOCKING_NOTIFIER_HEAD(mi_disp_notifier_list);

int get_hw_version_platform(void)
{
	return 1;
}
EXPORT_SYMBOL(get_hw_version_platform);

int get_hw_country_version(void)
{
	return 1;
}
EXPORT_SYMBOL(get_hw_country_version);

int get_hw_version_build(void)
{
	return 0;
}
EXPORT_SYMBOL(get_hw_version_build);

int get_hw_version_major(void)
{
	return 1;
}
EXPORT_SYMBOL(get_hw_version_major);

int get_hw_version_minor(void)
{
	return 0;
}
EXPORT_SYMBOL(get_hw_version_minor);

int get_hw_id_value(void)
{
	return 1;
}
EXPORT_SYMBOL(get_hw_id_value);

int mi_disp_register_client(struct notifier_block *nb)
{
	return blocking_notifier_chain_register(&mi_disp_notifier_list, nb);
}
EXPORT_SYMBOL(mi_disp_register_client);

int mi_disp_unregister_client(struct notifier_block *nb)
{
	return blocking_notifier_chain_unregister(&mi_disp_notifier_list, nb);
}
EXPORT_SYMBOL(mi_disp_unregister_client);

int mi_disp_notifier_call_chain(unsigned long val, void *v)
{
	return blocking_notifier_call_chain(&mi_disp_notifier_list, val, v);
}
EXPORT_SYMBOL(mi_disp_notifier_call_chain);
