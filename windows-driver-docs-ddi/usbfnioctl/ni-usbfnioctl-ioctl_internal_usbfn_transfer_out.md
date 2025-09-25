# IOCTL_INTERNAL_USBFN_TRANSFER_OUT IOCTL

## Description

 The class driver sends this request to initiate a data transfer from the host on the specified pipe.

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

A pointer to a **USBFNPIPEID** type that specifies the pipe ID.

### Input buffer length

The size of a **USBFNPIPEID** type.

### Output buffer

A data buffer to receive data from the host.

### Output buffer length

The length of the buffer.

### Input/output buffer

### Input/output buffer length

### Status block

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful.

Otherwise, Status to the appropriate error condition as a NTSTATUS code.

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

This request must be sent after sending the [IOCTL_INTERNAL_USBFN_ACTIVATE_USB_BUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnioctl/ni-usbfnioctl-ioctl_internal_usbfn_activate_usb_bus) request.