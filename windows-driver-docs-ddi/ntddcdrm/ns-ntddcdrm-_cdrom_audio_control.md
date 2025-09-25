# _CDROM_AUDIO_CONTROL structure

## Description

The CDROM_AUDIO_CONTROL structure is used in conjunction with the IOCTL_CDROM_GET_CONTROL request to report the audio playback mode.

## Members

### `LbaFormat`

Contains the logical block address (LBA) format.

### `LogicalBlocksPerSecond`

Contains the number of logical blocks per second.

## See also

[IOCTL_CDROM_GET_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_get_control)