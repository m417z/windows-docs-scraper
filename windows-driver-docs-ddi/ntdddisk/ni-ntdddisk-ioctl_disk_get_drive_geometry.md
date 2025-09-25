# IOCTL_DISK_GET_DRIVE_GEOMETRY IOCTL

## Description

Returns information about the physical disk's geometry (media type, number of cylinders, tracks per cylinder, sectors per track, and bytes per sector).

## Parameters

### Major code

### Input buffer

None

### Input buffer length

None

### Output buffer

The driver returns the [DISK_GEOMETRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_geometry) data in the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the buffer, which must be >= **sizeof**(DISK_GEOMETRY).

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the size, in bytes, of the returned data. The **Status** field can be set to STATUS_SUCCESS, or possibly to STATUS_UNRECOGNIZED_MEDIA, STATUS_INVALID_PARAMETER, STATUS_INVALID_DEVICE_REQUEST, STATUS_INFO_LENGTH_MISMATCH, STATUS_INSUFFICIENT_RESOURCES, or STATUS_BUFFER_TOO_SMALL.

## See also

[DISK_GEOMETRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_geometry)