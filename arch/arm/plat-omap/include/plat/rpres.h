/*
 * Remote processor resources
 *
 * Copyright (C) 2011 Texas Instruments, Inc.
 * Copyright (C) 2011 Google, Inc.
 *
 * Fernando Guzman Lugo <fernando.lugo@ti.com>
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 */

#ifndef _PLAT_OMAP_RPRES_H
#define _PLAT_OMAP_RPRES_H

enum {
	RPRES_INACTIVE,
	RPRES_ACTIVE,
};

struct rpres_ops {
	int (*start)(struct platform_device *pdev);
	int (*stop)(struct platform_device *pdev);
	/* no PM for the momment */
	//int (*set_constraint)(struct device *dev, void *arg);
	//int (*remove_constraint)(struct device *dev);
};

struct rpres_platform_data {
	const char *name;
	const char *oh_name;
	struct omap_hwmod *oh;
	struct rpres_ops *ops;
	struct clk *opt_clk;
	const char *opt_clk_name;
};

struct rpres {
	struct list_head next;
	const char *name;
	struct platform_device *pdev;
	int state;
	struct mutex lock;
};

struct rpres *rpres_get(const char *);
void rpres_put(struct rpres *);
#endif /* _PLAT_OMAP_RPRES_H */
