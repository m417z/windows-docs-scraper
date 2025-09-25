# IOCTL_PAR_QUERY_DEVICE_ID IOCTL

## Major Code:

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

## Description

The IOCTL_PAR_QUERY_DEVICE_ID request returns the IEEE 1284 device ID of a parallel device assigned by the system-supplied function driver for parallel ports.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The **AssociatedIrp.SystemBuffer** member points to a buffer that the client allocates to output the device ID. The buffer contains the device ID and a **NULL** terminator.

### Output buffer length

The **Parameters.DeviceIoControl.OutputBufferLength** member specifies the size, in bytes, of the output buffer that can hold both the device ID and a **NULL** terminator. A client can use an [IOCTL_PAR_QUERY_DEVICE_ID_SIZE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ni-ntddpar-ioctl_par_query_device_id_size) request to determine the required buffer size. A device ID can be up to 64 KB in size.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the **Information** member is set to the size, in bytes, of a buffer that holds both the device ID and a **NULL** terminator. Otherwise, the **Information** member is set to zero.

The **Status** member is set to one of the generic status values returned by device control requests for parallel devices or to one of the following values:

**STATUS_BUFFER_TOO_SMALL**

The output buffer that **AssociatedIrp.SystemBuffer** points to is less than the size, in bytes, of the device ID and a **NULL** terminator.

**STATUS_IO_DEVICE_ERROR**

A device I/O error occurred.

## See also

[IOCTL_PAR_QUERY_DEVICE_ID_SIZE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ni-ntddpar-ioctl_par_query_device_id_size)