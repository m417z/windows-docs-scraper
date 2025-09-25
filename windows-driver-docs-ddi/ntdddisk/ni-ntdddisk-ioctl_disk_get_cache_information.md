# IOCTL_DISK_GET_CACHE_INFORMATION IOCTL

## Description

Returns disk cache configuration data.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The device driver returns the [DISK_CACHE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_cache_information) in the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the buffer made available to the driver, which must be >= **sizeof**(DISK_CACHE_INFORMATION). Otherwise, the driver returns with an error status of STATUS_BUFFER_TOO_SMALL.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the size of the block of status information being returned, **sizeof**(DISK_CACHE_INFORMATION). The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_DEVICE_NOT_READY, STATUS_BUFFER_TOO_SMALL, STATUS_INSUFFICIENT_RESOURCES, STATUS_IO_DEVICE_ERROR, or STATUS_NOT_SUPPORTED.

## See also

[DISK_CACHE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_cache_information)