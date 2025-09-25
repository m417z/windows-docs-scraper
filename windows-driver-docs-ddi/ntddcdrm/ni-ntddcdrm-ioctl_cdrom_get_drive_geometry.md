# IOCTL_CDROM_GET_DRIVE_GEOMETRY IOCTL

## Description

Returns information about the CD-ROM's geometry (media type, number of cylinders, tracks per cylinder, sectors per track, and bytes per sector).

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The driver returns the [DISK_GEOMETRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_geometry)-type information in the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the buffer, which must be >= **sizeof**(DISK_GEOMETRY).

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code.

## See also

[DISK_GEOMETRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_geometry)

[IOCTL_CDROM_GET_DRIVE_GEOMETRY_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_get_drive_geometry_ex)