# _TAPE_GET_MEDIA_PARAMETERS structure (minitape.h)

## Description

The TAPE_GET_MEDIA_PARAMETERS structure is used in conjunction with the [TapeMiniGetMediaParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_process_command_routine) routine to retrieve tape media parameters.

## Members

### `Capacity`

Indicates the total number of bytes of user data the tape can hold.

### `Remaining`

Indicates the number of bytes from the current position to the end of the tape.

### `BlockSize`

Indicates the block size, in bytes, or zero if the drive is using variable block size.

### `PartitionCount`

Indicates the number of partitions on the tape. If the tape is not partitioned, **PartitionCount** is 1.

### `WriteProtected`

Is set to **TRUE** if the tape is write-protected.

## See also

[TapeMiniGetMediaParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_process_command_routine)