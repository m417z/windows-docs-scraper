# IOCTL_STORAGE_GET_MEDIA_TYPES IOCTL

## Description

Returns information about the geometry of floppy drives.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The driver returns an array of [DISK_GEOMETRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_geometry) records for the types of media it supports in the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the buffer, which must be at least (*NumberOfSupportedMediaTypes* * **sizeof**(DISK_GEOMETRY)).

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the size, in bytes, of the returned data. The **Status** field can be set to STATUS_SUCCESS, or possibly to STATUS_INVALID_DEVICE_REQUEST, STATUS_BUFFER_TOO_SMALL, or STATUS_BUFFER_OVERFLOW.

## See also

[DISK_GEOMETRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_geometry)