# IOCTL_DISK_CONTROLLER_NUMBER IOCTL

## Description

Retrieves the controller number and disk number for an IDE disk.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains the [DISK_CONTROLLER_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_controller_number) data.

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** in the IO_STACK_LOCATION structure of the IRP indicates the size, in bytes, of the output buffer, which must be >= **sizeof**(DISK_CONTROLLER_NUMBER).

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to **sizeof**(DISK_CONTROLLER_NUMBER).

The **Status** field is set to STATUS_SUCCESS if the operation is successful. One possible status value is STATUS_BUFFER_TOO_SMALL if the output buffer provided by the caller is too small.

## See also

[DISK_CONTROLLER_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_controller_number)