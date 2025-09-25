# _HID_DESCRIPTOR structure

## Description

The HID_DESCRIPTOR structure represents a HID descriptor for a HIDClass device.

## Members

### `bLength`

### `bDescriptorType`

### `bcdHID`

### `bCountry`

### `bNumDescriptors`

### `_HID_DESCRIPTOR_DESC_LIST`

### `_HID_DESCRIPTOR_DESC_LIST.bReportType`

### `_HID_DESCRIPTOR_DESC_LIST.wReportLength`

### `DescriptorList` [1]

## Remarks

The HID class driver uses an [IOCTL_HID_GET_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidport/ni-hidport-ioctl_hid_get_device_descriptor) request to obtain a device's HID descriptor from a HID minidriver.

For information about HID descriptors, see the Universal Serial Bus (USB) standard *Device Class Definition for Human Interface Devices (HID)* located at the [USB Implementers Forum website](https://www.usb.org/).

## See also

[IOCTL_HID_GET_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidport/ni-hidport-ioctl_hid_get_device_descriptor)