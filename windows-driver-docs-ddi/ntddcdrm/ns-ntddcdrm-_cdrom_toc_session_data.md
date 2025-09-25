# _CDROM_TOC_SESSION_DATA structure

## Description

Device control IRPs with a control code of [IOCTL_CDROM_READ_TOC_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_read_toc_ex) and a format of CDROM_READ_TOC_EX_FORMAT_SESSION return their output data in this structure followed by a series of [TRACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_track_data) structures.

## Members

### `Length`

Indicates the length, in bytes, of the table of contents data. This length value does not include the length of the **Length** member itself.

### `FirstCompleteSession`

Contains the number of the first complete session.

### `LastCompleteSession`

Contains the number of the last complete session.

### `TrackData`

Contains data for the first track of the last finished session. This data includes the starting address and number of the track.

## See also

[CDROM_READ_TOC_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_read_toc_ex)

[IOCTL_CDROM_READ_TOC_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_read_toc_ex)

[TRACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_track_data)