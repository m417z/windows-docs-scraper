# IOCTL_GENERICUSBFN_SET_PIPE_STATE IOCTL

## Description

This I/O control code (IOCTL) is sent by a user-mode service or application to set the state of the specified Universal Serial Bus (USB) pipe.

## Parameters

### Input buffer

A **USBFNPIPEID** that specifies the ID of the pipe to configure.

### Input buffer length

The size of a **USBFNPIPEID**.

### Output buffer

Contains a boolean value that specifies whether the specified pipe is stalled. A value of TRUE if the specified pipe is stalled; FALSE if otherwise.

### Output buffer length

The size of the output buffer in bytes.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code.

## Remarks

The pipe will send STALL transaction packets to the host when stalled. For more information, see the USB specification.

If this I/O control code (IOCTL) is being called synchronously, set the *lpOverlapped* parameter to NULL. If this IOCTL is called asynchronously, assign the *lpOverlapped* parameter to a pointer to an [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure that contains a handle to an event object. The event objects signal when the operation is completed.

The return value is a BOOL value that indicates success or failure of the operation. TRUE indicates success, FALSE otherwise.

## See also

[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol)

[IOCTL_GENERICUSBFN_GET_PIPE_STATE](https://learn.microsoft.com/windows/desktop/api/genericusbfnioctl/ni-genericusbfnioctl-ioctl_genericusbfn_get_pipe_state)