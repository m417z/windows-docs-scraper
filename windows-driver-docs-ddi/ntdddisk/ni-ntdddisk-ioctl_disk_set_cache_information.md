# IOCTL_DISK_SET_CACHE_INFORMATION IOCTL

## Description

Sets disk cache configuration data.

## Parameters

### Major code

### Input buffer

The input buffer.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the buffer made available to the driver, which must be >= **sizeof**(DISK_CACHE_INFORMATION). Otherwise, the driver returns with an error status of STATUS_INFO_LENGTH_MISMATCH.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to zero. The **Status** field can be set to STATUS_SUCCESS or STATUS_INFO_LENGTH_MISMATCH if the input buffer is not large enough.

## See also

[DISK_CACHE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_cache_information)