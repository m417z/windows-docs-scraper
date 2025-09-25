# IOCTL_PAR_QUERY_LOCATION IOCTL

## Major Code:

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

## Description

The IOCTL_PAR_QUERY_LOCATION request returns the "LPT*n*" or "LPT*n.m*" symbolic link name associated with a parallel device. This request is only supported by Windows XP and later.

For more information, see [Device Stacks for ParallelPorts and Devices](https://learn.microsoft.com/previous-versions/ff543949(v=vs.85)) and [Parallel Device Interfaces, Internal Names, and Symbolic Links](https://learn.microsoft.com/previous-versions/ff544284(v=vs.85)).

## Parameters

### Major code

### Input buffer

The client sets the **AssociatedIrp.SystemBuffer** member to a pointer to a character buffer for the location information.

### Input buffer length

The length of the character buffer.

### Output buffer

The parallel port bus driver outputs the location information in the buffer pointed to by **AssociatedIrp.SystemBuffer** as a **NULL**-terminated character string.

### Output buffer length

The client sets the **Parameters.DeviceIoControl.OutputBufferLength** member to the length of the output buffer that the system-supplied bus driver for parallel ports uses to output the device location information.

### Input/output buffer

### Input/output buffer length

### Status block

If the request succeeds, the **Information** member is set to the length, in bytes, of the symbolic link name plus the **NULL** terminator. Otherwise, **Information** is set to zero.

The **Status** member is set to one of the generic status values returned by device control requests for parallel devices or to the following value:

**STATUS_BUFFER_TOO_SMALL**

The **Parameters.DeviceIoControl.OutputBufferLength** member is less than size, in bytes, of the location information and the **NULL** terminator.

## See also

[IOCTL_PAR_QUERY_DEVICE_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ni-ntddpar-ioctl_par_query_device_id)