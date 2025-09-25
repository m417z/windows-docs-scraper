# _USB_NODE_CONNECTION_INFORMATION_EX_V2 structure

## Description

The **USB_NODE_CONNECTION_INFORMATION_EX_V2** structure is used with the [IOCTL_USB_GET_NODE_CONNECTION_INFORMATION_EX_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_node_connection_information_ex_v2) I/O control request to retrieve speed information about a Universal Serial Bus (USB) device that is attached to a particular port.

## Members

### `ConnectionIndex`

The port number. If there are *n* ports on the USB hub, the ports are numbered from 1 to *n*. To get the number of ports, send the [IOCTL_USB_GET_HUB_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_hub_information_ex) I/O control request. The request retrieves the highest port number on the hub.

### `Length`

The number of bytes that are required to hold the **USB_NODE_CONNECTION_INFORMATION_EX_V2** structure. The value must be set by the caller as input to the [IOCTL_USB_GET_NODE_CONNECTION_INFORMATION_EX_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_node_connection_information_ex_v2) request.

### `SupportedUsbProtocols`

The USB signaling protocols that are supported by the port.

In the caller's [IOCTL_USB_GET_NODE_CONNECTION_INFORMATION_EX_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_node_connection_information_ex_v2) request, the caller can set **SupportedUsbProtocols** to a bitwise **OR** of one or more flags defined in [USB_PROTOCOLS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_protocols).

Upon completion of the request, **SupportedUsbProtocols** contains flags, which indicate the protocols that are actually supported by the port.

### `Flags`

A bitmask that indicates the properties and capabilities of the attached device or port. For more information, see [USB_NODE_CONNECTION_INFORMATION_EX_V2_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_information_ex_v2_flags).

## See also

[IOCTL_USB_GET_NODE_CONNECTION_INFORMATION_EX_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_node_connection_information_ex_v2)

[USB_NODE_CONNECTION_INFORMATION_EX_V2_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_information_ex_v2_flags)