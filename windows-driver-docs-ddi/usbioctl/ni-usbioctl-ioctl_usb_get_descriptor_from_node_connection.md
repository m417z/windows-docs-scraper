# IOCTL_USB_GET_DESCRIPTOR_FROM_NODE_CONNECTION IOCTL

## Description

The **IOCTL_USB_GET_DESCRIPTOR_FROM_NODE_CONNECTION** I/O control request retrieves one or more descriptors for the device that is associated with the indicated port index.

**IOCTL_USB_GET_DESCRIPTOR_FROM_NODE_CONNECTION** is a user-mode I/O control request. This request targets the USB hub device ([GUID_DEVINTERFACE_USB_HUB](https://learn.microsoft.com/windows-hardware/drivers/install/guid-devinterface-usb-hub)).

## Parameters

### Major code

### Input buffer

The **AssociatedIrp.SystemBuffer** member points to a [USB_DESCRIPTOR_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_descriptor_request) structure that describes the descriptor request.

### Input buffer length

The **Parameters.DeviceIoControl.OutputBufferLength** member indicates the size, in bytes, of the user-allocated output buffer in the **Data** member of the [USB_DESCRIPTOR_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_descriptor_request) structure.

### Output buffer

The **Data** member of the [USB_DESCRIPTOR_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_descriptor_request) structure at **AssociatedIrp.SystemBuffer** points to the output buffer.

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

The USB stack sets **Irp->IoStatus.Status** to STATUS_SUCCESS if the request is successful. Otherwise, the USB stack sets **Status** to the appropriate error condition, such as STATUS_INVALID_PARAMETER or STATUS_INSUFFICIENT_RESOURCES.

## See also

[USB_DESCRIPTOR_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_descriptor_request)
[GUID_DEVINTERFACE_USB_HUB](https://learn.microsoft.com/windows-hardware/drivers/install/guid-devinterface-usb-hub)