# IOCTL_INTERNAL_USB_GET_HUB_NAME IOCTL

## Description

The **IOCTL_INTERNAL_USB_GET_HUB_NAME** I/O request is used by drivers to retrieve the UNICODE symbolic name for the target PDO if the PDO is for a hub. Otherwise a **NULL** string is returned.

Drivers can use the symbolic name to retrieve additional information about the hub through user-mode I/O control requests and WMI calls.

**IOCTL_INTERNAL_USB_GET_HUB_NAME** is a kernel-mode I/O control request. This request targets the USB hub PDO. This request must be sent at an IRQL of PASSIVE_LEVEL.

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

**Irp->AssociatedIrp.SystemBuffer** points to a [USB_HUB_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_hub_name) structure.

### Input buffer length

**Parameters.DeviceIoControl.OutputBufferLength** is the length of the buffer (in bytes) passed in the **Irp->AssociatedIrp.SystemBuffer** field.

### Output buffer

**Irp->AssociatedIrp.SystemBuffer** is filled with the root hub's symbolic name.

### Output buffer length

The length of the root hub's symbolic name.

### Input/output buffer

### Input/output buffer length

### Status block

A lower-level driver sets **Irp->IoStatus.Status** to STATUS_SUCCESS or the appropriate error status. It will set **Irp->IoStatus.Information** to the number of bytes required to hold the USB_ROOT_HUB_NAME structure. If the request fails, the driver can use this information to resubmit the request with a big enough buffer.

## See also

[USB_ROOT_HUB_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_root_hub_name)