# IOCTL_DISK_REASSIGN_BLOCKS IOCTL

## Description

Maps defective blocks to new location on disk. This request instructs the device to reassign the bad block address to a good block from its spare-block pool.

## Parameters

### Major code

### Input buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains the [REASSIGN_BLOCKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_reassign_blocks) values to be set. Note that this structure contains a variable-sized array of block numbers. It is the caller's responsibility to make sure that the array of block numbers is sorted in ascending order.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the buffer, which must be >= **sizeof**(REASSIGN_BLOCKS).

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to zero. The **Status** field can be set to STATUS_SUCCESS, or possibly to STATUS_INFO_LENGTH_MISMATCH, STATUS_INSUFFICIENT_RESOURCES, or STATUS_BUFFER_TOO_SMALL.

## See also

[REASSIGN_BLOCKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_reassign_blocks)