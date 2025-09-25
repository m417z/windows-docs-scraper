# _TAPE_SET_MEDIA_PARAMETERS structure (ntddtape.h)

## Description

The TAPE_SET_MEDIA_PARAMETERS structure is used in conjunction with the [IOCTL_TAPE_SET_MEDIA_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ni-ntddtape-ioctl_tape_set_media_params) request to reset the block size of the media in a tape drive.

## Members

### `BlockSize`

Indicates the requested block size, in bytes, or zero for variable block size in a drive that supports it.

## See also

[IOCTL_TAPE_SET_MEDIA_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ni-ntddtape-ioctl_tape_set_media_params)

[TapeMiniSetMediaParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_process_command_routine)