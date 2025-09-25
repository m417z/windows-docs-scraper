# IOCTL_USB_GET_NODE_CONNECTION_DRIVERKEY_NAME IOCTL

## Description

The **IOCTL_USB_GET_NODE_CONNECTION_DRIVERKEY_NAME** I/O control request retrieves the driver registry key name that is associated with the device that is connected to the indicated port.

**IOCTL_USB_GET_NODE_CONNECTION_DRIVERKEY_NAME** is a user-mode I/O control request. This request targets the USB hub device (GUID_DEVINTERFACE_USB_HUB).

## Parameters

### Major code

### Input buffer

The **AssociatedIrp.SystemBuffer** member points to a user-allocated [USB_NODE_CONNECTION_DRIVERKEY_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_driverkey_name) structure. On input, the **ConnectionIndex** member of this structure contains the number of the port that the device is connected to.

### Input buffer length

The size of a [USB_NODE_CONNECTION_DRIVERKEY_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_driverkey_name) structure.

### Output buffer

On output, the **DriverKeyName** member of the [USB_NODE_CONNECTION_DRIVERKEY_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_driverkey_name) structure at **AssociatedIrp.SystemBuffer** contains the driver key name that is associated with the device that is connected to the port that is indicated by **ConnectionIndex**.

The **ActualLength** member indicates the length, in bytes, of the driver key name. The **Parameters.DeviceIoControl.OutputBufferLength** member indicates the size, in bytes, of the entire [USB_NODE_CONNECTION_DRIVERKEY_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_driverkey_name) structure.

### Output buffer length

The size of a [USB_NODE_CONNECTION_DRIVERKEY_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_driverkey_name) structure.

### Input/output buffer

### Input/output buffer length

### Status block

The USB stack sets **Irp->IoStatus.Status** to STATUS_SUCCESS if the request is successful. Otherwise, the USB stack sets **Status** to the appropriate error condition, such as STATUS_INVALID_PARAMETER or STATUS_INSUFFICIENT_RESOURCES.

If the caller allocates an output buffer that is large enough to hold all of the output data, **IoStatus.Information** will be equal to the value of **ActualLength**. If the output buffer is large enough to hold all of the output data, **IoStatus.Information** will be equal to `sizeof(USB_NODE_CONNECTION_DRIVERKEY_NAME)`.

## See also

[USB_NODE_CONNECTION_DRIVERKEY_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_driverkey_name)