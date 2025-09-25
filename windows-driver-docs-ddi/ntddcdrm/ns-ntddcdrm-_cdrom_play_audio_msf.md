# _CDROM_PLAY_AUDIO_MSF structure

## Description

Device control IRPs with a control code of [IOCTL_CDROM_PLAY_AUDIO_MSF](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_play_audio_msf) use this structure to play an audio CD.

## Members

### `StartingM`

Contains an integer between 0 and 74 that indicates the starting minute.

### `StartingS`

Contains an integer between 0 and 59 that indicates the starting second.

### `StartingF`

Contains an integer between 0 and 74 that indicates the starting frame.

### `EndingM`

Contains an integer between 0 and 74 that indicates the ending minute.

### `EndingS`

Contains an integer between 0 and 59 that indicates the ending second.

### `EndingF`

Contains an integer between 0 and 74 that indicates the ending frame.

## Remarks

Device control IRPs with a control code of IOCTL_CDROM_PLAY_AUDIO_MSF use this structure to play an audio CD and to indicate where to begin playing and where to stop. Starting and ending points are indicated in terms of minutes, seconds, and frames.

## See also

[IOCTL_CDROM_PLAY_AUDIO_MSF](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_play_audio_msf)