# IOCTL_CANCEL_IO IOCTL

## Description

Cancels activity on the specified USB transfer pipe that is associated with the specified device handle.

## Parameters

### Major code

### Input buffer

Pointer to a location containing a value of type [PIPE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbscan/ne-usbscan-pipe_type).

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

*hDevice*

Device handle, obtained by calling [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea).

*dwIoControlCode*

IOCTL_CANCEL_IO

*lpInBuffer*

Pointer to a location containing a value of type [PIPE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbscan/ne-usbscan-pipe_type).

*nInBufferSize*

Size of the input buffer.

*lpOutBuffer*

**NULL**

*nOutBufferSize*

Zero.

*lpBytesReturned*

Pointer to a location to receive the number of bytes returned.

*lpOverlapped*

Optional pointer to an OVERLAPPED structure (described in the Microsoft Windows SDK documentation).

When the **DeviceloControl** function is called with the IOCTL_CANCEL_IO I/O control code, the caller must specify one of the [PIPE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbscan/ne-usbscan-pipe_type)-typed values as the function's *lpInBuffer* parameter. This value indicates on which of the transfer pipes (interrupt, bulk IN, bulk OUT) the operation should be performed. For more information, see [Accessing Kernel-Mode Drivers for Still Image Devices](https://learn.microsoft.com/windows-hardware/drivers/image/accessing-kernel-mode-drivers-for-still-image-devices).