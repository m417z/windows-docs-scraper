# IOCTL_TAPE_GET_POSITION IOCTL

## Description

Returns the current absolute, logical, or pseudological partition and offset position on the tape.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The driver returns the [TAPE_GET_POSITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ns-ntddtape-_tape_get_position) data in the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location indicates the size, in bytes, of the parameter buffer, which must be >= **sizeof**(TAPE_GET_POSITION).

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the number of bytes returned. The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_INFO_LENGTH_MISMATCH, STATUS_IO_DEVICE_ERROR, STATUS_DEVICE_DATA_ERROR, STATUS_NO_SUCH_DEVICE, STATUS_IO_TIMEOUT, STATUS_DEVICE_NOT_READY, STATUS_NO_MEDIA_IN_DEVICE, or STATUS_VERIFY_REQUIRED.

## See also

[TAPE_GET_POSITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ns-ntddtape-_tape_get_position)

[TAPE_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ne-minitape-_tape_status)

[TapeMiniGetPosition](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_process_command_routine)