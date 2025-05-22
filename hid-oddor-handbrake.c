// SPDX-License-Identifier: GPL-2.0-or-later
/*
 *  HID driver for ODDOR handbrake
 *
 *  Copyright (c) 2025 Oleg Makarenko
 */

#include <linux/device.h>
#include <linux/input.h>
#include <linux/hid.h>
#include <linux/module.h>
#include <linux/usb.h>

#define USB_VENDOR_ID_ODDOR               0x1021
#define USB_PRODUCT_ID_ODDOR_HANDBRAKE    0x1888

static int oddor_input_mapping(struct hid_device *hdev, struct hid_input *hi,
		struct hid_field *field, struct hid_usage *usage,
		unsigned long **bit, int *max)
{
    if ((usage->hid & HID_USAGE_PAGE) == HID_UP_BUTTON) {
        return -1;
    }
    return 0;
}

static const struct hid_device_id oddor_devices[] = {
	{ HID_USB_DEVICE(USB_VENDOR_ID_ODDOR, USB_PRODUCT_ID_ODDOR_HANDBRAKE) },
	{ }
};
MODULE_DEVICE_TABLE(hid, oddor_devices);

static struct hid_driver oddor_driver = {
	.name = "hid-oddor",
	.id_table = oddor_devices,
	.input_mapping = oddor_input_mapping,
};
module_hid_driver(oddor_driver);

MODULE_DESCRIPTION("HID driver for ODDOR handbrake");
MODULE_LICENSE("GPL");
