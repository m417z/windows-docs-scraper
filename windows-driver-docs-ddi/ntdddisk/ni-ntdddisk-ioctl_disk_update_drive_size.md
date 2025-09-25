# IOCTL_DISK_UPDATE_DRIVE_SIZE IOCTL

## Description

Updates device extension with drive size information for current media.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

 Otherwise, the driver returns with an error status of STATUS_BUFFER_TOO_SMALL.

The device driver returns the [DISK_GEOMETRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_geometry) structure in the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the buffer made available to the driver, which must be >= **sizeof**(DISK_GEOMETRY).

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code.

## See also

[DISK_GEOMETRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_geometry)