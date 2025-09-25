# IOCTL_USB_GET_HUB_CAPABILITIES IOCTL

## Description

The **IOCTL_USB_GET_HUB_CAPABILITIES** I/O control request retrieves the capabilities of a USB hub. **Note** This request is replaced by [IOCTL_USB_GET_HUB_CAPABILITIES_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_hub_capabilities_ex) in Windows Vista.

**IOCTL_USB_GET_HUB_CAPABILITIES** is a user-mode I/O control request. This request targets the USB hub device (GUID_DEVINTERFACE_USB_HUB).

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The **AssociatedIrp.SystemBuffer** member points to a user-allocated [USB_HUB_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_hub_capabilities) structure that describes the hub capabilities.

### Output buffer length

The **Parameters.DeviceIoControl.OutputBufferLength** member indicates the size, in bytes, of the output buffer in **SystemBuffer**. The output buffer size must be `>= sizeof(USB_HUB_CAPABILITIES)`.

### Input/output buffer

### Input/output buffer length

### Status block

The USB stack sets **Irp->IoStatus.Status** to STATUS_SUCCESS if the request is successful. Otherwise, the USB stack sets **Status** to the appropriate error condition, such as STATUS_INVALID_PARAMETER or STATUS_INSUFFICIENT_RESOURCES.

## See also

[IOCTL_USB_GET_HUB_CAPABILITIES_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_hub_capabilities_ex)

[USB_HUB_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_hub_capabilities)