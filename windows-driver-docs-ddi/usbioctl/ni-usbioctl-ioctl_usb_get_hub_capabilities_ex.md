# IOCTL_USB_GET_HUB_CAPABILITIES_EX IOCTL

## Description

The **IOCTL_USB_GET_HUB_CAPABILITIES_EX** I/O control request retrieves the capabilities of a USB hub.

**IOCTL_USB_GET_HUB_CAPABILITIES_EX** is a user-mode I/O control request. This request targets the USB hub device (GUID_DEVINTERFACE_USB_HUB).

## Parameters

### Major code

### Input buffer

The **AssociatedIrp.SystemBuffer** member points to a user-allocated buffer.

### Input buffer length

 The buffer length equals `sizeof(USB_HUB_CAPABILITIES_EX)`.

### Output buffer

**AssociatedIrp.SystemBuffer** points to a user-allocated [USB_HUB_CAPABILITIES_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_hub_capabilities_ex) structure. On output, this structure describes the hub capabilities.

### Output buffer length

The **Parameters.DeviceIoControl.OutputBufferLength** member indicates the size, in bytes, of the data that is returned at **SystemBuffer**, or `sizeof(USB_HUB_CAPABILITIES_EX)`.

### Input/output buffer

### Input/output buffer length

### Status block

The USB stack sets **Irp->IoStatus.Status** to STATUS_SUCCESS if the request is successful. Otherwise, the USB stack sets **Status** to the appropriate error condition, such as STATUS_INVALID_PARAMETER or STATUS_INSUFFICIENT_RESOURCES. If the hub has not been started or is not functional, the request returns STATUS_UNSUCCESSFUL.

## See also

[USB_HUB_CAPABILITIES_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_hub_capabilities_ex)