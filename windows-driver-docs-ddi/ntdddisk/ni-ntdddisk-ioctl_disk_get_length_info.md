# IOCTL_DISK_GET_LENGTH_INFO IOCTL

## Description

Returns the length, in bytes, of the disk, partition, or volume associated with the device object that is the target of the request.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The driver returns the [GET_LENGTH_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_get_length_information) data in the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the buffer, which must be >= **sizeof**(GET_LENGTH_INFORMATION).

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the size, in bytes, of the returned data. The **Status** field can be set to STATUS_SUCCESS, or to STATUS_BUFFER_TOO_SMALL if the buffer supplied by the caller is inadequate.

## See also

[GET_LENGTH_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_get_length_information)