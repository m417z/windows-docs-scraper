# IOCTL_TAPE_ERASE IOCTL

## Description

Erases the current tape partition, either as a TAPE_ERASE_LONG (in other words, a "secure") operation that overwrites data with a pattern or as a TAPE_ERASE_SHORT (in other words, a "quick") operation that writes an end-of-recorded-data mark at the current position.

## Parameters

### Major code

### Input buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains a structure of type [TAPE_ERASE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ns-ntddtape-_tape_erase).

If the **Immediate** member is **TRUE**, the operation should be asynchronous.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location indicates the size, in bytes, of the parameter buffer, which must be >= **sizeof**(TAPE_ERASE).

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the number of bytes transferred. The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_INFO_LENGTH_MISMATCH, STATUS_DEVICE_DATA_ERROR, STATUS_NO_SUCH_DEVICE, STATUS_IO_TIMEOUT, STATUS_IO_DEVICE_ERROR, STATUS_MEDIA_WRITE_PROTECTED, STATUS_INSUFFICIENT_RESOURCES, STATUS_NOT_IMPLEMENTED, STATUS_NO_MEDIA_IN_DEVICE, or STATUS_VERIFY_REQUIRED.

## See also

[TAPE_ERASE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ns-ntddtape-_tape_erase)

[TAPE_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ne-minitape-_tape_status)

[TapeMiniErase](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_process_command_routine)