# IOCTL_DISK_GROW_PARTITION IOCTL

## Description

Increases the size of an existing partition. It is used in conjunction with [IOCTL_DISK_UPDATE_DRIVE_SIZE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_update_drive_size) to extend a disk, so that it will contain a new free space area, and then to extend an existing partition on the disk into the newly attached free space. It takes a [DISK_GROW_PARTITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_grow_partition) structure as the only parameter. For this operation to work, the space after the specified partition must be free. A partition cannot be extended over another existing partition.

## Parameters

### Major code

### Input buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains the [DISK_GROW_PARTITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_grow_partition) values - that will be used to increase the size of the partition.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the buffer made available to the driver, which must be >= **sizeof**(DISK_GROW_PARTITION). Otherwise, the driver returns with an error status of STATUS_BUFFER_TOO_SMALL.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_BUFFER_TOO_SMALL, STATUS_INVALID_PARAMETER, STATUS_UNSUCCESSFUL, or STATUS_DRIVER_INTERNAL_ERROR.

## See also

[DISK_GROW_PARTITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_grow_partition)