# IOCTL_TAPE_GET_MEDIA_PARAMS IOCTL

## Description

Returns information about the media's total and remaining capacity, its block size, the number of partitions, and whether it is write-protected.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The driver returns the [TAPE_GET_MEDIA_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ns-ntddtape-_tape_get_media_parameters) data in the buffer at **Irp->AssociatedIrp.SystemBuffer**. For a description of the TAPE_GET_MEDIA_PARAMETERS structure, see [TapeMiniGetMediaParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_process_command_routine).

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location indicates the size, in bytes, of the parameter buffer, which must be >= **sizeof**(TAPE_GET_MEDIA_PARAMETERS).

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the number of bytes returned. The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_IO_DEVICE_ERROR, STATUS_DEVICE_DATA_ERROR, STATUS_DATA_OVERRUN, STATUS_NO_SUCH_DEVICE, STATUS_IO_TIMEOUT, STATUS_DEVICE_NOT_READY, STATUS_INFO_LENGTH_MISMATCH, STATUS_NO_MEDIA_IN_DEVICE, or STATUS_VERIFY_REQUIRED.

## See also

[TAPE_GET_MEDIA_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ns-ntddtape-_tape_get_media_parameters)

[TAPE_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ne-minitape-_tape_status)

[TapeMiniGetMediaParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_process_command_routine)