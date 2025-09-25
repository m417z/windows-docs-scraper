# _DEVICE_DESCRIPTOR structure

## Description

The DEVICE_DESCRIPTOR structure is used as a parameter to [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol), when the specified I/O control code is [IOCTL_GET_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbscan/ni-usbscan-ioctl_get_device_descriptor).

## Members

### `usVendorId`

Vendor identifier.

### `usProductId`

Device product identifier.

### `usBcdDevice`

BCD-encoded device version number.

### `usLanguageId`

*Not used*.