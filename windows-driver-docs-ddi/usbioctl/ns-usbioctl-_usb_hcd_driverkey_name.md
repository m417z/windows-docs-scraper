# _USB_HCD_DRIVERKEY_NAME structure

## Description

The **USB_HCD_DRIVERKEY_NAME** structure is used with the [IOCTL_GET_HCD_DRIVERKEY_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_get_hcd_driverkey_name) I/O control request to retrieve the driver key in the registry for the USB host controller driver.

## Members

### `ActualLength`

The length, in bytes, of the string in the **DriverKeyName** member.

### `DriverKeyName`

A NULL-terminated Unicode driver key name for the USB host controller.

## See also

[IOCTL_GET_HCD_DRIVERKEY_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_get_hcd_driverkey_name)

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)