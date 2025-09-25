# _CDROM_SEEK_AUDIO_MSF structure

## Description

The CDROM_SEEK_AUDIO_MSF structure contains the minute, second, and frame that the device must seek to upon receipt of a device control IRP with a control code of [IOCTL_CDROM_SEEK_AUDIO_MSF](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_seek_audio_msf).

## Members

### `M`

Contains an integer between 0 and 74 that indicates the minute to seek to.

### `S`

Contains an integer between 0 and 59 that indicates the second to seek to.

### `F`

Contains an integer between 0 and 74 that indicates the frame to seek to.

## See also

[IOCTL_CDROM_SEEK_AUDIO_MSF](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_seek_audio_msf)