# IOCTL_GENERICUSBFN_CONTROL_STATUS_HANDSHAKE_IN IOCTL

## Description

This I/O control code (IOCTL) is sent by a user mode service or application to request a zero-length control status handshake on endpoint 0 in the IN direction.

## Parameters

### Input buffer

A **USBFNPIPEID** that specifies the pipe ID of endpoint 0.

### Input buffer length

The size of a **USBFNPIPEID**.

### Output buffer

NULL.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code.

## Remarks

If this I/O control code (IOCTL) is being called synchronously, set the *lpOverlapped* parameter to NULL. If this IOCTL is called asynchronously, assign the *lpOverlapped* parameter to a pointer to an [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure that contains a handle to an event object. The event objects signal when the operation is completed.

The return value is a BOOL value that indicates success or failure of the operation. TRUE indicates success, FALSE otherwise.

## See also

[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol)

[IOCTL_GENERICUSBFN_CONTROL_STATUS_HANDSHAKE_OUT](https://learn.microsoft.com/windows/desktop/api/genericusbfnioctl/ni-genericusbfnioctl-ioctl_genericusbfn_control_status_handshake_out)