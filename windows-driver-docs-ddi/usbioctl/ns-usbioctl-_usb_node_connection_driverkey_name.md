# _USB_NODE_CONNECTION_DRIVERKEY_NAME structure

## Description

The **USB_NODE_CONNECTION_DRIVERKEY_NAME** structure is used with the [IOCTL_USB_GET_NODE_CONNECTION_DRIVERKEY_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_node_connection_driverkey_name) I/O control request to retrieve the driver key name for the device that is connected to the indicated port.

## Members

### `ConnectionIndex`

On input, the port number that the device is connected to.

### `ActualLength`

On output, the length of this structure, in bytes.

### `DriverKeyName`

On output, the driver key name for the device that is attached to the port that is indicated by **ConnectionIndex**. This name is represented as a Unicode string.

## See also

- [IOCTL_USB_GET_NODE_CONNECTION_DRIVERKEY_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_node_connection_driverkey_name)
- [USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)