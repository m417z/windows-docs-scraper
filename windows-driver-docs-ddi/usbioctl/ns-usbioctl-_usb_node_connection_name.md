# _USB_NODE_CONNECTION_NAME structure

## Description

The **USB_NODE_CONNECTION_NAME** structure is used with the [IOCTL_USB_GET_NODE_CONNECTION_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_node_connection_name) I/O control request to retrieve the symbolic link of the downstream hub that is attached to the port.

## Members

### `ConnectionIndex`

A value that is greater than or equal to 1 that specifies the number of the port to which the hub is attached.

### `ActualLength`

The length, in bytes, of the attached hub's symbolic link.

### `NodeName`

A Unicode symbolic link for the downstream hub that is attached to the port that is indicated by **ConnectionIndex**. If there is no attached device, the attached device does not have a symbolic link, or if the device is not a hub, **NodeName**[0] will contain a value of UNICODE_NULL.

## See also

[IOCTL_USB_GET_NODE_CONNECTION_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_node_connection_name)

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)