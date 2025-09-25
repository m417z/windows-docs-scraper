# _USB_NODE_CONNECTION_ATTRIBUTES structure

## Description

The **USB_NODE_CONNECTION_ATTRIBUTES** structure is used with the [IOCTL_USB_GET_NODE_CONNECTION_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_node_connection_attributes) I/O control request to retrieve the attributes of a connection.

## Members

### `ConnectionIndex`

On input to the [IOCTL_USB_GET_NODE_CONNECTION_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_node_connection_attributes) I/O control request, this member contains the number of the port.

### `ConnectionStatus`

On output from the [IOCTL_USB_GET_NODE_CONNECTION_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_node_connection_attributes) I/O control request, this member contains a [USB_CONNECTION_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ne-usbioctl-_usb_connection_status) enumerator that indicates the connection status.

### `PortAttributes`

On output from the [IOCTL_USB_GET_NODE_CONNECTION_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_node_connection_attributes) I/O control request, this member contains the Microsoft-extended port attributes.

For Windows Vista, Windows Server 2008, and Windows 7 the Microsoft-extended port attributes field will always be zero.

For Windows XP and Windows Server 2003, **PortAttributes** value might be set to the Microsoft-extended port attributes, USB_PORTATTR_NO_OVERCURRENT_UI. This attribute indicates that no user-visible interface will be displayed when overcurrent occurs on the port.

## See also

[IOCTL_USB_GET_NODE_CONNECTION_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_node_connection_attributes)

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)

[USB_CONNECTION_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ne-usbioctl-_usb_connection_status)