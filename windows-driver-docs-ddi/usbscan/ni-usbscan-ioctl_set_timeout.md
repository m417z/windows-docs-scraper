## Description

Sets the time-out value for USB bulk IN, bulk OUT, or interrupt pipe access.

## Parameters

### Major code

### Input buffer

Pointer to a [USBSCAN_TIMEOUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbscan/ns-usbscan-_usbscan_timeout) structure.

### Input buffer length

Size of the input buffer.

### Output buffer

**NULL**.

### Output buffer length

Zero.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) code.

## Remarks

### DeviceIoControl Parameters

When the **DeviceloControl** function is called with the IOCTL_SET_TIMEOUT I/O control code, the caller must specify the address of a [USBSCAN_TIMEOUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbscan/ns-usbscan-_usbscan_timeout) structure as the function's *lpInBuffer* parameter.

Using the USBSCAN_TIMEOUT structure's contents, the kernel-mode driver resets the time-out value for each type of operation: bulk IN read, bulk OUT write, or interrupt.

For more information, see [Accessing Kernel-Mode Drivers for Still Image Devices](https://learn.microsoft.com/windows-hardware/drivers/image/accessing-kernel-mode-drivers-for-still-image-devices).

The default time-out value is 120 seconds. The maximum time-out value is 214 seconds. Values greater than 214 seconds will cause transfer time-outs.