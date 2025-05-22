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
    // Map all buttons to BTN_JOYSTICK, for detection
    if ((usage->hid & HID_USAGE_PAGE) == HID_UP_BUTTON ) {
        hid_map_usage_clear(hi, usage, bit, max, EV_KEY, BTN_JOYSTICK);
        return 1;
    }
    return 0;
}

static int oddor_event(struct hid_device *hdev, struct hid_field *field,
		struct hid_usage *usage, __s32 value)
{
	if (usage->type == EV_KEY) {
        // Ignore all button inputs
		return 1;
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
    .event = oddor_event,
};
module_hid_driver(oddor_driver);

MODULE_DESCRIPTION("HID driver for ODDOR handbrake");
MODULE_LICENSE("GPL");
