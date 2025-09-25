# IOCTL_TAPE_SET_MEDIA_PARAMS IOCTL

## Description

Resets the block size of the media in the drive.

## Parameters

### Major code

### Input buffer

 The buffer at **Irp->AssociatedIrp.SystemBuffer** contains a [TAPE_SET_MEDIA_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ns-ntddtape-_tape_set_media_parameters) structure containing the block size to be set.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location indicates the size, in bytes, of the parameter buffer, which must be >= **sizeof**(TAPE_SET_MEDIA_PARAMETERS).

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to zero. The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_IO_DEVICE_ERROR, STATUS_MEDIA_WRITE_PROTECTED, STATUS_DEVICE_DATA_ERROR, STATUS_NO_SUCH_DEVICE, STATUS_IO_TIMEOUT, STATUS_DEVICE_NOT_READY, STATUS_INFO_LENGTH_MISMATCH, STATUS_NO_MEDIA_IN_DEVICE, or STATUS_VERIFY_REQUIRED.

## See also

[TAPE_SET_MEDIA_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ns-ntddtape-_tape_set_media_parameters)

[TAPE_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ne-minitape-_tape_status)

[TapeMiniSetMediaParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_process_command_routine)