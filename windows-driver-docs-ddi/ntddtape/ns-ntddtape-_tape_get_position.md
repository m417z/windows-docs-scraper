# _TAPE_GET_POSITION structure (ntddtape.h)

## Description

The TAPE_GET_POSITION structure is used in conjunction with the [IOCTL_TAPE_GET_POSITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ni-ntddtape-ioctl_tape_get_position) request to retrieve the current absolute, logical, or pseudological partition and offset position on the tape.

## Members

### `Type`

Indicates the type of position requested. This member can be TAPE_ABSOLUTE_POSITION, TAPE_LOGICAL_POSITION, or TAPE_PSEUDO_LOGICAL_POSITION.

### `Partition`

Indicates the number of the partition where the current position is located.

### `Offset`

Indicates the number of bytes from the beginning of the partition to the current position.

## See also

[IOCTL_TAPE_GET_POSITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ni-ntddtape-ioctl_tape_get_position)