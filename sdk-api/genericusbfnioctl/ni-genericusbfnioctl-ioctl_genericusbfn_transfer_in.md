# IOCTL_GENERICUSBFN_TRANSFER_IN IOCTL

## Description

This I/O control code (IOCTL) is sent by a user-mode service or application to issue an IN direction transfer on the endpoint that corresponds to the specified pipe ID in the input buffer.

## Parameters

### Input buffer

A **USBFNPIPEID** that specifies the ID of the pipe to conduct the transfer on.

### Input buffer length

The size of a **USBFNPIPEID**.

### Output buffer

The data to send to the host. From the host perspective the data is sent from the IN direction, representing an outbound transfer from the device to the host.

### Output buffer length

The size of the output buffer in bytes.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code.

## Remarks

If this I/O control code (IOCTL) is being called synchronously, set the *lpOverlapped* parameter to NULL. If this IOCTL is called asynchronously, assign the *lpOverlapped* parameter to a pointer to an [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure that contains a handle to an event object. The event objects signal when the operation is completed.

The return value is a BOOL value that indicates success or failure of the operation. TRUE indicates success, FALSE otherwise.

## See also

[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol)

[IOCTL_GENERICUSBFN_TRANSFER_IN_APPEND_ZERO_PKT](https://learn.microsoft.com/windows/desktop/api/genericusbfnioctl/ni-genericusbfnioctl-ioctl_genericusbfn_transfer_in_append_zero_pkt)

[IOCTL_GENERICUSBFN_TRANSFER_OUT](https://learn.microsoft.com/windows/desktop/api/genericusbfnioctl/ni-genericusbfnioctl-ioctl_genericusbfn_transfer_out)