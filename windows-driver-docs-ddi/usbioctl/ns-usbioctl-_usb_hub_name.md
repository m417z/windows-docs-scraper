# _USB_HUB_NAME structure

## Description

The **USB_HUB_NAME** structure stores the hub's symbolic device name.

## Members

### `ActualLength`

The size of the Unicode string pointed to by **HubName**. The **ActualLength** value indicates the length of the string and not the entire structure.

### `HubName`

A NULL-terminated Unicode string that contains the hub's symbolic device name.

## See also

[IOCTL_INTERNAL_USB_GET_CONTROLLER_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_internal_usb_get_controller_name)

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)