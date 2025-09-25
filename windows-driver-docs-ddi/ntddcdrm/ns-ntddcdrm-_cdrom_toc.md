# _CDROM_TOC structure

## Description

Device control IRPs with a control code of [IOCTL_CDROM_READ_TOC_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_read_toc_ex) and a format of CDROM_READ_TOC_EX_FORMAT_TOC return their output data in this structure followed by a series of [TRACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_track_data) structures.

## Members

### `Length`

Indicates the length, in bytes, of the table of contents data. This length value does not include the length of the **Length** member itself.

### `FirstTrack`

Indicates the first track number of the table of contents of the first complete session.

### `LastTrack`

Indicates the last track number of the table of contents of the last complete session.

### `TrackData`

Array of structures of type [TRACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_track_data) that contain table of contents information for all the sessions on the disc.

## Remarks

The output data contains table of contents information for one or more of the specified sessions.

## See also

[CDROM_READ_TOC_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_read_toc_ex)

[IOCTL_CDROM_READ_TOC_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_read_toc_ex)

[TRACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_track_data)