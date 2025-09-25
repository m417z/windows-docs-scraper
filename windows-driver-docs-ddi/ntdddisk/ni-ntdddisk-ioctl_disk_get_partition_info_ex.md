# IOCTL_DISK_GET_PARTITION_INFO_EX IOCTL

## Description

Returns information about the type, size, and nature of a disk partition. (Floppy drivers need not handle this request.)

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The driver returns the [PARTITION_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_partition_information_ex) data in the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the buffer, which must be >= **sizeof**(PARTITION_INFORMATION_EX).

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the size, in bytes, of the returned data. The **Status** field can be set to STATUS_SUCCESS, or possibly to STATUS_INVALID_PARAMETER, STATUS_INFO_LENGTH_MISMATCH, STATUS_INSUFFICIENT_RESOURCES, STATUS_INVALID_DEVICE_REQUEST, or STATUS_BUFFER_TOO_SMALL.

## See also

[PARTITION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_partition_information)