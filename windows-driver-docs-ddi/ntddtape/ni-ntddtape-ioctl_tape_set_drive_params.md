# IOCTL_TAPE_SET_DRIVE_PARAMS IOCTL

## Description

Adjusts a tape drive's configurable parameters. The miniclass driver can ignore parameters that its device does not support. The calling application is responsible for determining whether a device supports a particular feature before attempting to set it.

## Parameters

### Major code

### Input buffer

 The [TAPE_SET_DRIVE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ns-ntddtape-_tape_set_drive_parameters) structure in the buffer at **Irp->AssociatedIrp.SystemBuffer** contains the values to be set.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location indicates the size, in bytes, of the parameter buffer, which must be >= **sizeof**(TAPE_SET_DRIVE_PARAMETERS).

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to zero. The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_IO_DEVICE_ERROR, STATUS_INVALID_DEVICE_REQUEST, STATUS_DEVICE_DATA_ERROR, STATUS_NO_SUCH_DEVICE, STATUS_IO_TIMEOUT, STATUS_INFO_LENGTH_MISMATCH, or STATUS_DEVICE_NOT_READY.

## See also

[TAPE_SET_DRIVE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ns-ntddtape-_tape_set_drive_parameters)

[TAPE_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ne-minitape-_tape_status)

[TapeMiniSetDriveParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_process_command_routine)