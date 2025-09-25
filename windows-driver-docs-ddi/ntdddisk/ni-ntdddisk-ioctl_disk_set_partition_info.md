# IOCTL_DISK_SET_PARTITION_INFO IOCTL

## Description

Changes the partition type of the specified disk partition. (Floppy drivers need not handle this request.)

## Parameters

### Major code

### Input buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains the [SET_PARTITION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_set_partition_information) to be set.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the buffer, which must be >= **sizeof**(SET_PARTITION_INFORMATION).

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to zero. The **Status** field can be set to STATUS_SUCCESS, or possibly to STATUS_INVALID_PARAMETER, STATUS_INVALID_DEVICE_REQUEST, STATUS_UNSUCCESSFUL, STATUS_INFO_LENGTH_MISMATCH, STATUS_INSUFFICIENT_RESOURCES, or STATUS_BUFFER_TOO_SMALL.

## See also

[SET_PARTITION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_set_partition_information)