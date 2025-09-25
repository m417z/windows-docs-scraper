# IOCTL_DISK_VERIFY IOCTL

## Description

Performs verification for a specified extent on a disk.

## Parameters

### Major code

### Input buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains the [VERIFY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_verify_information) data specifying the starting offset and length to be verified.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** indicates the size, in bytes, of the buffer, which must be >= **sizeof**(VERIFY_INFORMATION).

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to zero to prevent the I/O manager from copying data from **SystemBuffer** back into the user area.

If the request is successful, then the **Status** field is set to STATUS_SUCCESS. Otherwise, the **Status** field can be set to STATUS_BUFFER_TOO_SMALL, STATUS_INFO_LENGTH_MISMATCH, STATUS_INVALID_PARAMETER, STATUS_INSUFFICIENT_RESOURCES, STATUS_NONEXISTENT_SECTOR, STATUS_DEVICE_DATA_ERROR, STATUS_INVALID_DEVICE_REQUEST, STATUS_IO_TIMEOUT, or STATUS_DEVICE_NOT_CONNECTED.

## See also

[VERIFY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_verify_information)