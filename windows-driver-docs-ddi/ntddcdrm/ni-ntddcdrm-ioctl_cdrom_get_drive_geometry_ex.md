# IOCTL_CDROM_GET_DRIVE_GEOMETRY_EX IOCTL

## Description

Returns information about a CD-ROM's geometry (media type, number of cylinders, tracks per cylinder, sectors per track, and bytes per sector).

The IOCTL_CDROM_GET_DRIVE_GEOMETRY_EX request differs from the older [IOCTL_CDROM_GET_DRIVE_GEOMETRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_get_drive_geometry) request. The IOCTL_CDROM_GET_DRIVE_GEOMETRY_EX request can retrieve information from both Master Boot Record (MBR) and GUID Partition Table (GPT) partitioned media. However, IOCTL_CDROM_GET_DRIVE_GEOMETRY can read only MBR-style media.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The driver returns the [DISK_GEOMETRY_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_geometry_ex)-type information in the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** in the IO_STACK_LOCATION structure of the IRP indicates the size, in bytes, of the buffer, which must be >= **sizeof**(DISK_GEOMETRY_EX).

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the size, in bytes, of the returned data. The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_UNRECOGNIZED_MEDIA, STATUS_INVALID_PARAMETER, STATUS_INFO_LENGTH_MISMATCH, or STATUS_BUFFER_TOO_SMALL.

## Remarks

## See also

[DISK_GEOMETRY_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_geometry_ex)

[IOCTL_DISK_GET_DRIVE_GEOMETRY_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_get_drive_geometry_ex)