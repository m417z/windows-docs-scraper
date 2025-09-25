# _TAPE_ERASE structure (minitape.h)

## Description

The TAPE_ERASE structure is used in conjunction with the [IOCTL_TAPE_ERASE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ni-ntddtape-ioctl_tape_erase) request to erase the current tape partition.

## Members

### `Type`

Indicates the type of erasure to perform. When this member is set to TAPE_ERASE_LONG, the tape partition is overwritten with a filler pattern. When it is set to TAPE_ERASE_SHORT, an end-of-recorded-data mark is written to the current position.

### `Immediate`

Indicates that the target device should return status immediately, when set to **TRUE**. When this member is set to **FALSE**, the device should return status after the operation is complete.

## See also

[IOCTL_TAPE_ERASE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ni-ntddtape-ioctl_tape_erase)