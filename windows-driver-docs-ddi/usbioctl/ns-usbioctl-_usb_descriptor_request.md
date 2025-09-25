# _USB_DESCRIPTOR_REQUEST structure

## Description

The **USB_DESCRIPTOR_REQUEST** structure is used with the [IOCTL_USB_GET_DESCRIPTOR_FROM_NODE_CONNECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_descriptor_from_node_connection) I/O control request to retrieve one or more descriptors for the device that is associated with the indicated connection index. The fields in this structure are described in the Universal Serial Bus 3.1 Specification available at [USB Document Library](https://www.usb.org/documents).

## Members

### `ConnectionIndex`

The port whose descriptors are retrieved.

### `SetupPacket`

The members of the **SetupPacket** structure defined as per the official specification. See section 9.3.

### `SetupPacket.bmRequest`

The type of USB device request (standard, class, or vendor), the direction of the data transfer, and the type of data recipient (device, interface, or endpoint). On input to the [IOCTL_USB_GET_DESCRIPTOR_FROM_NODE_CONNECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_descriptor_from_node_connection) I/O control request, the USB stack ignores the value of **bmRequest** and inserts a value of 0x80. This value indicates a standard USB device request and a device-to-host data transfer.

### `SetupPacket.bRequest`

The request number. On input to the [IOCTL_USB_GET_DESCRIPTOR_FROM_NODE_CONNECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_descriptor_from_node_connection) I/O control request, the USB stack ignores the value of **bRequest** and inserts a value of 0x06. This value indicates a request of **GET_DESCRIPTOR**.

### `SetupPacket.wValue`

On input to the [IOCTL_USB_GET_DESCRIPTOR_FROM_NODE_CONNECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_descriptor_from_node_connection) I/O control request, the caller should specify the type of descriptor to retrieve in the high byte of **wValue** and the descriptor index in the low byte. The following table lists the possible descriptor types. These constant types are defined in the Usbspec.h header included in the Windows Driver Kit.

| Descriptor type | Meaning |
| --- | --- |
| USB_DEVICE_DESCRIPTOR_TYPE | Instructs the USB stack to return the device descriptor. |
| USB_CONFIGURATION_DESCRIPTOR_TYPE | Instructs the USB stack to return the configuration descriptor and all interface, endpoint, class-specific, and vendor-specific descriptors associated with the current configuration. |
| USB_STRING_DESCRIPTOR_TYPE | Instructs the USB stack to return the indicated string descriptor. |
| USB_INTERFACE_DESCRIPTOR_TYPE | Instructs the USB stack to return the indicated interface descriptor. |
| USB_ENDPOINT_DESCRIPTOR_TYPE | Instructs the USB stack to return the indicated endpoint descriptor. |

### `SetupPacket.wIndex`

The device-specific index of the descriptor that is to be retrieved.

### `SetupPacket.wLength`

The length of the data that is transferred during the second phase of the control transfer.

### `Data`

On output from the [IOCTL_USB_GET_DESCRIPTOR_FROM_NODE_CONNECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_descriptor_from_node_connection) I/O control request, this member contains the retrieved descriptors.

## Remarks

If the caller specifies a value of USB_CONFIGURATION_DESCRIPTOR_TYPE in the **wValue** member, the output buffer must be large enough to hold all of the descriptors that are associated with the current configuration, or the request will fail.

## See also

[IOCTL_USB_GET_DESCRIPTOR_FROM_NODE_CONNECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_descriptor_from_node_connection)

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)