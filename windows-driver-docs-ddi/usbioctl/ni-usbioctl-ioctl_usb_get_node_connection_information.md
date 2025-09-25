# IOCTL_USB_GET_NODE_CONNECTION_INFORMATION IOCTL

## Description

The **IOCTL_USB_GET_NODE_CONNECTION_INFORMATION** request retrieves information about the indicated USB port and the device that is attached to the port, if there is one.

Client drivers must send this IOCTL at an IRQL of PASSIVE_LEVEL.

**IOCTL_USB_GET_NODE_CONNECTION_INFORMATION** is a user-mode I/O control request. This request targets the USB hub device (GUID_DEVINTERFACE_USB_HUB).

## Parameters

### Major code

### Input buffer

The **AssociatedIrp.SystemBuffer** member points to a user-allocated [USB_NODE_CONNECTION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_information) structure that describes the connection. On input, the **ConnectionIndex** member of this structure contains the port number.

### Input buffer length

The size of a [USB_NODE_CONNECTION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_information) structure.

### Output buffer

On output, the **Parameters.DeviceIoControl.OutputBufferLength** member contains the size of the output data. This size is variable, because it depends on the number of pipes that are associated with the port.

**AssociatedIrp.SystemBuffer** points to a user-allocated [USB_NODE_CONNECTION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_information) structure that contains the output data.

### Output buffer length

The size of a [USB_NODE_CONNECTION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_information) structure.

### Input/output buffer

### Input/output buffer length

### Status block

The USB stack sets **Irp->IoStatus.Status** to STATUS_SUCCESS if the request is successful. Otherwise, the USB stack sets **Status** to the appropriate error condition, such as STATUS_INVALID_PARAMETER or STATUS_INSUFFICIENT_RESOURCES.

## Remarks

The [IOCTL_USB_GET_NODE_CONNECTION_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_node_connection_information_ex) request is an extended version of **IOCTL_USB_GET_NODE_CONNECTION_INFORMATION**. The two requests are identical, except that the extended version of the request can report low, full, and high speed connections and the older **IOCTL_USB_GET_NODE_CONNECTION_INFORMATION** request reports only low and full speed connections. For more information about the difference between these two requests, see [USB_NODE_CONNECTION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_information) and [USB_NODE_CONNECTION_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_information_ex).

## See also

[IOCTL_USB_GET_NODE_CONNECTION_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_node_connection_information_ex)

[USB_NODE_CONNECTION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_information)

[USB_NODE_CONNECTION_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_information_ex)