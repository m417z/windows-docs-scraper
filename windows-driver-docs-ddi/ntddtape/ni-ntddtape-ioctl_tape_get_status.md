# IOCTL_TAPE_GET_STATUS IOCTL

## Description

Returns the current status of the drive in the **Status** field of the I/O status block.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to zero. The **Status** field is set to one of the following NT status values:

* STATUS_SUCCESS
* STATUS_INSUFFICIENT_RESOURCES
* STATUS_NOT_IMPLEMENTED
* STATUS_INVALID_DEVICE_REQUEST
* STATUS_INVALID_PARAMETER
* STATUS_VERIFY_REQUIRED
* STATUS_BUS_RESET
* STATUS_SETMARK_DETECTED
* STATUS_FILEMARK_DETECTED
* STATUS_BEGINNING_OF_MEDIA
* STATUS_END_OF_MEDIA
* STATUS_BUFFER_OVERFLOW
* STATUS_NO_DATA_DETECTED
* STATUS_EOM_OVERFLOW
* STATUS_NO_MEDIA
* STATUS_IO_DEVICE_ERROR
* STATUS_UNRECOGNIZED_MEDIA
* STATUS_DEVICE_NOT_READY
* STATUS_MEDIA_WRITE_PROTECTED
* STATUS_DEVICE_DATA_ERROR
* STATUS_NO_SUCH_DEVICE
* STATUS_INVALID_BLOCK_LENGTH
* STATUS_IO_TIMEOUT
* STATUS_DEVICE_NOT_CONNECTED
* STATUS_DATA_OVERRUN
* STATUS_DEVICE_BUSY
* STATUS_DEVICE_REQUIRES_CLEANING
* STATUS_CLEANER_CARTRIDGE_INSTALLED

Each of these NT status values correspond to a value in the [TAPE_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ne-minitape-_tape_status) enumerator. For more information about the significance of these values and a mapping between the NT status values and the TAPE_STATUS values, see [Processing Tape Device Control Requests](https://learn.microsoft.com/windows-hardware/drivers/storage/processing-tape-device-control-requests).

## See also

[TAPE_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ne-minitape-_tape_status)