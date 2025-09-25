# IOCTL_DISK_GET_DRIVE_GEOMETRY_EX IOCTL

## Description

Returns information about the physical disk's geometry (media type, number of cylinders, tracks per cylinder, sectors per track, and bytes per sector).

The difference between IOCTL_DISK_GET_DRIVE_GEOMETRY_EX and the older [IOCTL_DISK_GET_DRIVE_GEOMETRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_get_drive_geometry) request is that IOCTL_DISK_GET_DRIVE_GEOMETRY_EX can retrieve information from both Master Boot Record (MBR) and GUID Partition Table (GPT)-type partitioned media, whereas IOCTL_DISK_GET_DRIVE_GEOMETRY can only read MBR-style media.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The driver returns the [DISK_GEOMETRY_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_geometry_ex) data in the buffer at **Irp->AssociatedIrp.SystemBuffer**. The size of the output buffer may not be the same size as the input buffer.

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the buffer, which must be at least (**sizeof**(DISK_GEOMETRY) + **sizeof**(LARGE_INTEGER)) and up to (**sizeof**(DISK_GEOMETRY) + **sizeof**(LARGE_INTEGER) + **sizeof**(DISK_PARTITION_INFO) + **sizeof**(DISK_DETECTION_INFO)).

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the size, in bytes, of the returned data.

The **Status** field returns one of the following values:

* **STATUS_SUCCESS**
* **STATUS_UNRECOGNIZED_MEDIA**
* **STATUS_INVALID_PARAMETER**
* **STATUS_INVALID_DEVICE_REQUEST**
* **STATUS_INFO_LENGTH_MISMATCH**
* **STATUS_INSUFFICIENT_RESOURCES**
* **STATUS_BUFFER_TOO_SMALL**

## Remarks

Only callers above Partmgr.sys may call this IOCTL as it contains disk partition information.

This IOCTL uses [IOCTL_DISK_GET_DRIVE_GEOMETRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_get_drive_geometry) to get the [DISK_GEOMETRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_geometry) structure and [IOCTL_DISK_GET_LENGTH_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_get_length_info) to get the [GET_LENGTH_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_get_length_information) structure. Both of these IOCTL's are supported for use at the disk.sys level.