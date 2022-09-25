/*
 * Copyright (C) 2016-2017 Samsung Electronics Co. Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * for ptn36502 driver
 */

#ifndef __LINUX_PTN36502_H__
#define __LINUX_PTN36502_H__


#define Chip_ID						0x00
#define Chip_Rev					0x01
#define USB_TXRX_Control			0x04
#define DS_TXRX_Control				0x05
#define DP_Link_Control				0x06
#define DP_Lane0_Control			0x07
#define DP_Lane1_Control			0x08
#define DP_Lane2_Control			0x09
#define DP_Lane3_Control			0x0a
#define Mode_Control				0x0b
#define Squelch_Threshold			0x0c
#define Device_Control				0x0d

typedef union{
	uint8_t	data;
	 struct {
		uint8_t	RxEq:4,
				Swing:2,
				DeEmpha:2;
	} BITS;
} usb_Control;

struct ptn36502_data {
	struct device *dev;
	struct i2c_client *i2c;
	struct mutex i2c_mutex;
	int combo_redriver_en;
	int redriver_en;
	int con_sel;
	usb_Control usbControl_US;
	usb_Control usbControl_DS;
};

enum config_type {
	BOOTING_INIT = 0,
	INIT_MODE,
	USB3_ONLY_MODE,
	DP4_LANE_MODE,
	DP2_LANE_USB3_MODE,
};

enum data_type {
	UFP = 0,
	DFP,
};

extern void ptn36502_config(int config, int is_DFP);

#endif

