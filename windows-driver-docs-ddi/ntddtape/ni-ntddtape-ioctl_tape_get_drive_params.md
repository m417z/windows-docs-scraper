# IOCTL_TAPE_GET_DRIVE_PARAMS IOCTL

## Description

Returns information about the tape drive's capabilities, such as its default block size, maximum and minimum block sizes, maximum partition count, whether the drive has EEC, compression, data padding, and report-setmark capabilities, that is, which configurable features the drive supports, including the EOT warning zone size.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The driver returns the [TAPE_GET_DRIVE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ns-ntddtape-_tape_get_drive_parameters) data in the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location indicates the size, in bytes, of the parameter buffer, which must be >= **sizeof**(TAPE_GET_DRIVE_PARAMETERS).

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the number of bytes returned. The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_INFO_LENGTH_MISMATCH, STATUS_IO_DEVICE_ERROR, STATUS_DEVICE_DATA_ERROR, STATUS_NO_SUCH_DEVICE, STATUS_IO_TIMEOUT, or STATUS_DEVICE_NOT_READY.

## See also

[TAPE_GET_DRIVE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ns-ntddtape-_tape_get_drive_parameters)

[TAPE_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ne-minitape-_tape_status)

[TapeMiniGetDriveParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_process_command_routine)