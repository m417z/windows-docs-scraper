# IOCTL_USB_GET_NODE_CONNECTION_ATTRIBUTES IOCTL

## Description

The **IOCTL_USB_GET_NODE_CONNECTION_ATTRIBUTES** I/O control request retrieves the Microsoft-extended port attributes for a specific port.

**IOCTL_USB_GET_NODE_CONNECTION_ATTRIBUTES** is a user-mode I/O control request. This request targets the USB hub device (GUID_DEVINTERFACE_USB_HUB).

## Parameters

### Major code

### Input buffer

The **AssociatedIrp.SystemBuffer** member points to a user-allocated [USB_NODE_CONNECTION_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_attributes) structure. On input, the caller specifies the port number in the **ConnectionIndex** member of a **USB_NODE_CONNECTION_ATTRIBUTES** structure.

### Input buffer length

The size of a [USB_NODE_CONNECTION_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_attributes) structure.

### Output buffer

On output, the [USB_NODE_CONNECTION_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_attributes) structure at **AssociatedIrp.SystemBuffer** describes the Microsoft-extended port attributes for the port. **Note** For Windows Vista, Windows Server 2008, and Windows 7, the Microsoft-extended port attributes field is set to zero.

For Windows XP and Windows Server 2003, the Microsoft-extended port attribute might be set to USB_PORTATTR_NO_OVERCURRENT_UI. This value indicates that user interface will be hidden when an overcurrent occurs on the port.

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** indicates the size, in bytes, of the data returned at **SystemBuffer**.

### Input/output buffer

### Input/output buffer length

### Status block

The USB stack sets **Irp->IoStatus.Status** to STATUS_SUCCESS if the request is successful. Otherwise, the USB stack sets **Status** to the appropriate error condition, such as STATUS_INVALID_PARAMETER or STATUS_INSUFFICIENT_RESOURCES. If the hub has not been started or is not functional, the request returns STATUS_UNSUCCESSFUL.

## See also

[USB_NODE_CONNECTION_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_attributes)