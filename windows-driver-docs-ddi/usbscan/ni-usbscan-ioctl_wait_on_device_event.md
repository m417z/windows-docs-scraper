# IOCTL_WAIT_ON_DEVICE_EVENT IOCTL

## Description

Returns information about an event occurring on a USB interrupt pipe.

## Parameters

### Major code

### Input buffer

**NULL**

### Input buffer length

Zero.

### Output buffer

Pointer to a buffer that is large enough to receive the largest packet the device is capable of sending on the interrupt pipe.

### Output buffer length

Size of the output buffer.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) code.

## Remarks

### DeviceIoControl Parameters

When the **DeviceloControl** function is called with the IOCTL_WAIT_ON_DEVICE_EVENT control code, the caller must specify a buffer pointer as the function's *lpOutBuffer* parameter. The buffer must be large enough to hold the largest packet the device can send on its interrupt pipe.

The type and size of information returned are device-specific. For example, a still image device might issue an interrupt when a user presses one of its buttons, and the return packet might indicate which button was pressed.

For more information, see [Accessing Kernel-Mode Drivers for Still Image Devices](https://learn.microsoft.com/windows-hardware/drivers/image/accessing-kernel-mode-drivers-for-still-image-devices).