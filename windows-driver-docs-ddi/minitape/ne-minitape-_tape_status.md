# _TAPE_STATUS enumeration

## Description

The TAPE_STATUS enumeration provides a list of the status codes that the tape class driver uses to report the status of a tape device.

## Constants

### `TAPE_STATUS_SEND_SRB_AND_CALLBACK`

Directs the tape class driver to send the SRB to the device. A tape miniclass routine usually returns this status after filling in the SRB passed by the tape class driver. If the operation is successful, the class driver increments a counter called a "call number" and calls the miniclass routine again. If the SRB fails, the class driver might call the miniclass routine again. For more information about how and when tape miniclass drivers should report this status value, see [Processing Tape Device Control Requests](https://learn.microsoft.com/windows-hardware/drivers/storage/processing-tape-device-control-requests).

### `TAPE_STATUS_CALLBACK`

Directs the tape class driver to increment the call number counter without sending an SRB to the device. For more information about how tape miniclass drivers should make use of this status value, see [Processing Tape Device Control Requests](https://learn.microsoft.com/windows-hardware/drivers/storage/processing-tape-device-control-requests).

### `TAPE_STATUS_CHECK_TEST_UNIT_READY`

Directs the tape class driver to create an SRB for the TEST UNIT READY command and to send the SRB to the device.

### `TAPE_STATUS_SUCCESS`

Indicates that the operation was successful.

### `TAPE_STATUS_INSUFFICIENT_RESOURCES`

Indicates that there were not enough resources available to the miniclass driver for it to complete the operation.

### `TAPE_STATUS_NOT_IMPLEMENTED`

Indicates that the requested operation is not supported.

### `TAPE_STATUS_INVALID_DEVICE_REQUEST`

Indicates that the requested operation is invalid.

### `TAPE_STATUS_INVALID_PARAMETER`

Indicates that one or more of the parameter values provided with the request are invalid.

### `TAPE_STATUS_MEDIA_CHANGED`

Indicates that the media in the drive might have changed.

### `TAPE_STATUS_BUS_RESET`

Indicates that the bus has been reset.

### `TAPE_STATUS_SETMARK_DETECTED`

Indicates that a setmark was encountered during a tape operation.

### `TAPE_STATUS_FILEMARK_DETECTED`

Indicates that a filemark was encountered during a tape operation.

### `TAPE_STATUS_BEGINNING_OF_MEDIA`

Indicates that the beginning of the media was encountered during a tape operation.

### `TAPE_STATUS_END_OF_MEDIA`

Indicates that the end of the media was encountered during a tape operation.

### `TAPE_STATUS_BUFFER_OVERFLOW`

Indicates that a buffer overflow occurred.

### `TAPE_STATUS_NO_DATA_DETECTED`

Indicates that no data was detected.

### `TAPE_STATUS_EOM_OVERFLOW`

Indicates that an attempt was made to exceed the physical end of the media during a tape operation.

### `TAPE_STATUS_NO_MEDIA`

Indicates that the tape operation failed, because there is no media in the drive.

### `TAPE_STATUS_IO_DEVICE_ERROR`

Indicates that an I/O error occurred during a tape operation.

### `TAPE_STATUS_UNRECOGNIZED_MEDIA`

Indicates that the type of the media is not supported.

### `TAPE_STATUS_DEVICE_NOT_READY`

Indicates that the device is not ready.

### `TAPE_STATUS_MEDIA_WRITE_PROTECTED`

Indicates that the media is write protected.

### `TAPE_STATUS_DEVICE_DATA_ERROR`

Indicates that a cyclic redundancy check (CRC) error occurred.

### `TAPE_STATUS_NO_SUCH_DEVICE`

Indicates that no such device exists.

### `TAPE_STATUS_INVALID_BLOCK_LENGTH`

Indicates that the block length is invalid.

### `TAPE_STATUS_IO_TIMEOUT`

Indicates that the I/O operation timed out.

### `TAPE_STATUS_DEVICE_NOT_CONNECTED`

Indicates that the device is disconnected.

### `TAPE_STATUS_DATA_OVERRUN`

Indicates that the tape operation could not be performed because of a data overrun.

### `TAPE_STATUS_DEVICE_BUSY`

Indicates that the tape operation could not be performed, because the device is busy.

### `TAPE_STATUS_REQUIRES_CLEANING`

Indicates that the tape operation could not be performed because the device requires cleaning.

### `TAPE_STATUS_CLEANER_CARTRIDGE_INSTALLED`

Indicates that the media currently in the drive is a cleaner cartridge.

## See also

[IOCTL_TAPE_GET_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ni-ntddtape-ioctl_tape_get_status)