# IOCTL_TAPE_SET_POSITION IOCTL

## Description

Moves the current position on the tape to the specified partition and offset, according to the given method.

## Parameters

### Major code

### Input buffer

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location indicates the size, in bytes, of the parameter buffer, which must be >= **sizeof**(TAPE_SET_POSITION).

The [TAPE_SET_POSITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ns-ntddtape-_tape_set_position) structure in the buffer at **Irp->AssociatedIrp.SystemBuffer** indicates the partition and offset to which the tape is to be moved.

If the **Immediate** member is **TRUE**, the operation should be asynchronous.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location indicates the size, in bytes, of the parameter buffer, which must be >= **sizeof**(TAPE_SET_POSITION).

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to zero. The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_INFO_LENGTH_MISMATCH, STATUS_IO_DEVICE_ERROR, STATUS_DEVICE_DATA_ERROR, STATUS_NO_SUCH_DEVICE, STATUS_IO_TIMEOUT, STATUS_DEVICE_NOT_READY, STATUS_NO_MEDIA_IN_DEVICE, or STATUS_VERIFY_REQUIRED.

## See also

[TAPE_SET_POSITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ns-ntddtape-_tape_set_position)

[TAPE_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ne-minitape-_tape_status)

[TapeMiniSetPosition](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_process_command_routine)