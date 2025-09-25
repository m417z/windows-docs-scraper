# IOCTL_USB_GET_NODE_CONNECTION_NAME IOCTL

## Description

The **IOCTL_USB_GET_NODE_CONNECTION_NAME** I/O control request is used with the [USB_NODE_CONNECTION_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_name) structure to retrieve the symbolic link name of the hub that is attached to the downstream port.

**IOCTL_USB_GET_NODE_CONNECTION_NAME** is a user-mode I/O control request. This request targets the USB hub device (GUID_DEVINTERFACE_USB_HUB).

## Parameters

### Major code

### Input buffer

The **AssociatedIrp.SystemBuffer** member points to a [USB_NODE_CONNECTION_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_name) structure. On input, the **ConnectionIndex** member of this structure must indicate the number of the port to check for an attached hub.

### Input buffer length

The size of a [USB_NODE_CONNECTION_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_name) structure.

### Output buffer

**AssociatedIrp.SystemBuffer** points to a [USB_NODE_CONNECTION_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_name) structure. On output, this structure contains the symbolic name of the attached hub in the **HubName** member. If no hub is attached, the hub does not have a symbolic link, or the attached device is not a hub, **HubName**[0] will contain a value of UNICODE_NULL.

### Output buffer length

The **Parameters.DeviceIoControl.OutputBufferLength** member contains the size, in bytes, of the entire [USB_NODE_CONNECTION_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_name) structure.

### Input/output buffer

### Input/output buffer length

### Status block

The USB stack sets **Irp->IoStatus.Status** to STATUS_SUCCESS if the request is successful. The request reports success, even if no hub is attached, the attached hub has no symbolic link, or the attached device is not a hub.

Otherwise, the USB stack sets **Status** to the appropriate error condition, such as STATUS_INVALID_PARAMETER or STATUS_INSUFFICIENT_RESOURCES.

## See also

[USB_NODE_CONNECTION_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_name)