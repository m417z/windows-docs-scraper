# IOCTL_USB_GET_HUB_INFORMATION_EX IOCTL

## Description

The **IOCTL_USB_GET_HUB_INFORMATION_EX** I/O control request is sent by an application to retrieve information about a USB hub in a [USB_HUB_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_hub_information_ex) structure.

The request retrieves the highest port number on the hub. For USB 2.0 and SuperSpeed hubs (non-root hubs), the request also retrieves the associated hub descriptors, as defined in USB 2.0 and 3.0 Specifications, respectively.

**IOCTL_USB_GET_HUB_INFORMATION_EX** is a user-mode I/O control request. This request targets the USB hub device (GUID_DEVINTERFACE_USB_HUB).

## Parameters

### Major code

### Input buffer

**AssociatedIrp.SystemBuffer** points to a caller-allocated [USB_HUB_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_hub_information_ex) structure.

### Input buffer length

The **Parameters.DeviceIoControl.InputBufferLength** member indicates the size, in bytes, of the caller-allocated buffer whose size equals `sizeof(USB_HUB_INFORMATION_EX)`.

### Output buffer

 On output, the [USB_HUB_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_hub_information_ex) structure that is pointed to by **AssociatedIrp.SystemBuffer** is filled with information about the hub.

### Output buffer length

The **Parameters.DeviceIoControl.OutputBufferLength** member indicates the size, in bytes, of the output buffer **SystemBuffer**.

### Input/output buffer

### Input/output buffer length

### Status block

The USB stack sets **Irp->IoStatus.Status** to STATUS_SUCCESS if the request is successful. Otherwise, the USB driver stack sets **Status** to the appropriate error condition, such as STATUS_INVALID_PARAMETER or STATUS_INSUFFICIENT_RESOURCES.

## See also

[USB_HUB_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_hub_information_ex)