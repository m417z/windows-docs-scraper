# IOCTL_GET_PIPE_CONFIGURATION IOCTL

## Description

Returns a description of every transfer pipe supported for a device.

## Parameters

### Major code

### Input buffer

**NULL**.

### Input buffer length

Zero.

### Output buffer

Pointer to a [USBSCAN_PIPE_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbscan/ns-usbscan-_usbscan_pipe_configuration) structure.

### Output buffer length

Size of the output buffer.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) code.

## Remarks

### DeviceIoControl Parameters

When the **DeviceloControl** function is called with the IOCTL_GET_PIPE_CONFIGURATION I/O control code, the caller must specify the address of a [USBSCAN_PIPE_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbscan/ns-usbscan-_usbscan_pipe_configuration) structure as the function's *lpOutbuffer* parameter. The kernel-mode driver fills in the structure.

For more information, see [Accessing Kernel-Mode Drivers for Still Image Devices](https://learn.microsoft.com/windows-hardware/drivers/image/accessing-kernel-mode-drivers-for-still-image-devices).