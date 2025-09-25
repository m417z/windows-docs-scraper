# IOCTL_INTERNAL_USB_UNREGISTER_COMPOSITE_DEVICE IOCTL

## Description

The **IOCTL_INTERNAL_USB_UNREGISTER_COMPOSITE_DEVICE**
I/O request unregisters the driver of a USB multi-function device (composite driver) and releases all resources that are associated with registration. The request is successful only if the composite driver was previously registered with the underlying USB driver stack through the [IOCTL_INTERNAL_USB_REGISTER_COMPOSITE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_internal_usb_register_composite_device) request.

**IOCTL_INTERNAL_USB_UNREGISTER_COMPOSITE_DEVICE** is a kernel-mode I/O control request. This request targets the Universal Serial Bus (USB) hub physical device object (PDO). This request must be sent at an interrupt request level (IRQL) of PASSIVE_LEVEL.

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

None.

### Input buffer length

None.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The USB driver stack sets **Irp->IoStatus.Status** to STATUS_SUCCESS or the appropriate error status.

## Remarks

You must send the **IOCTL_INTERNAL_USB_UNREGISTER_COMPOSITE_DEVICE** request in the composite driver's remove-device ([IRP_MN_REMOVE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-remove-device)) routine.

## See also

[How to Register a Composite Device](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[IOCTL_INTERNAL_USB_REGISTER_COMPOSITE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_internal_usb_register_composite_device)