# IOCTL_GENERICUSBFN_BUS_EVENT_NOTIFICATION IOCTL

## Description

This I/O control code (IOCTL) is sent by a user-mode service or application to register for Universal Serial Bus (USB) event. After this request completes, notifications about events such as a change in the port type or the receipt of a non-standard setup packet can be received. The **USBFN_NOTIFICATION** structure contained in the output buffer specifies which event has occurred and any associated data.

## Parameters

### Input buffer

NULL.

### Input buffer length

None.

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