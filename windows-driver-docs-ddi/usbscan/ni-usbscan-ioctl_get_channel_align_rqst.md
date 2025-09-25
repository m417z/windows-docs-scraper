# IOCTL_GET_CHANNEL_ALIGN_RQST IOCTL

## Description

Returns a USB device's maximum packet size for the read, write, and interrupt transfer pipes associated with the specified device handle.

## Parameters

### Major code

### Input buffer

**NULL**.

### Input buffer length

Zero.

### Output buffer

Pointer to a [CHANNEL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbscan/ns-usbscan-_channel_info) structure.

### Output buffer length

Size of the output buffer.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) code.

## Remarks

### DeviceIoControl Parameters

When the **DeviceloControl** function is called with the IOCTL_GET_CHANNEL_ALIGN_RQST I/O control code, the caller must specify the address of a [CHANNEL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbscan/ns-usbscan-_channel_info) structure as the function's *lpOutBuffer* parameter. The kernel-mode driver fills in the structure.

For more information, see [Accessing Kernel-Mode Drivers for Still Image Devices](https://learn.microsoft.com/windows-hardware/drivers/image/accessing-kernel-mode-drivers-for-still-image-devices).