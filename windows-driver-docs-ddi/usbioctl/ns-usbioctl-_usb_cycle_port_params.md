# _USB_CYCLE_PORT_PARAMS structure

## Description

The **USB_CYCLE_PORT_PARAMS** structure is used with the [IOCTL_USB_HUB_CYCLE_PORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_hub_cycle_port) I/O control request to power cycle the port that is associated with the PDO that receives the request.

## Members

### `ConnectionIndex`

Specifies the port number starting at 1.

### `StatusReturned`

On return, contains the USBD status of the operation.

## See also

[IOCTL_USB_HUB_CYCLE_PORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_hub_cycle_port)