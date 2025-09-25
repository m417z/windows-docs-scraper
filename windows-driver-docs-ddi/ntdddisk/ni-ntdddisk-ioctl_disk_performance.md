# IOCTL_DISK_PERFORMANCE IOCTL

## Description

Increments a reference counter that enables the collection of disk performance statistics, such as the numbers of bytes read and written since the driver last processed this request, for a corresponding disk monitoring application. In Microsoft Windows 2000 this IOCTL is handled by the filter driver diskperf. In Windows XP and later operating systems, the partition manager handles this request for disks and *ftdisk.sys* and *dmio.sys* handle this request for volumes.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The driver returns the [DISK_PERFORMANCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_performance) data in the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the buffer, which must be at least **sizeof**(DISK_PERFORMANCE).

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to **sizeof**(DISK_PERFORMANCE) when the **Status** field is set to STATUS_SUCCESS. Otherwise, the **Status** field can be set to STATUS_INVALID_PARAMETER or STATUS_BUFFER_TOO_SMALL.

## See also

[IOCTL_DISK_PERFORMANCE_OFF](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_performance_off)