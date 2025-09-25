# IOCTL_STORAGE_READ_CAPACITY IOCTL

## Description

The **IOCTL_STORAGE_READ_CAPACITY** request returns the read capacity information for the target storage device.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The buffer at *Irp->AssociatedIrp.SystemBuffer* contains a [STORAGE_READ_CAPACITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_read_capacity) structure.

### Output buffer length

*Parameters.DeviceIoControl.OutputBufferLength* in the I/O stack location of the IRP indicates the size, in bytes, of the buffer, which must be at least **sizeof**(STORAGE_READ_CAPACITY).

### Input/output buffer

### Input/output buffer length

### Status block

The **Status** field can be set to STATUS_SUCCESS, or possibly to STATUS_INVALID_DEVICE_REQUEST, STATUS_BUFFER_TOO_SMALL, STATUS_BUFFER_OVERFLOW, or some other error status.

## Remarks

A **IOCTL_STORAGE_READ_CAPACITY** request returns the disk capacity information retrieved during disk initialization. The capacity information is obtained by the system with the SCSI READ CAPACITY command.

## See also

[STORAGE_READ_CAPACITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_read_capacity)