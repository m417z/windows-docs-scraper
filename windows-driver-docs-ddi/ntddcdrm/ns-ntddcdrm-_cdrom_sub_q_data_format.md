# _CDROM_SUB_Q_DATA_FORMAT structure

## Description

The CDROM_SUB_Q_DATA_FORMAT structure is used with device control IRPs of type [IOCTL_CDROM_READ_Q_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_read_q_channel).

## Members

### `Format`

Specifies which subset of the Q data the read operation should return, as follows:

#### IOCTL_CDROM_CURRENT_POSITION

Indicates that the read operation should return position information such as the track number, the index number, the absolute address, and the track relative address. If the IOCTL_CDROM_Q_CHANNEL device control IRP specifies this format, the information is returned in the [SUB_Q_CURRENT_POSITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_sub_q_current_position) member of the [SUB_Q_CHANNEL_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_sub_q_channel_data) structure.

#### IOCTL_CDROM_MEDIA_CATALOG

Indicates that the read operation should return the media catalog number. If the IOCTL_CDROM_Q_CHANNEL device control IRP specifies this format, the information is returned in the [SUB_Q_MEDIA_CATALOG_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_sub_q_media_catalog_number) member of the [SUB_Q_CHANNEL_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_sub_q_channel_data) structure.

#### IOCTL_CDROM_TRACK_ISRC

Indicates that the read operation should return the ISO/IEC 3901 Track International Standard Recording Code (ISRC). This code gives a unique number to an audio track. If the IOCTL_CDROM_Q_CHANNEL device control IRP specifies this format, the information is returned in the [SUB_Q_TRACK_ISRC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_sub_q_track_isrc) member of the [SUB_Q_CHANNEL_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_sub_q_channel_data) structure.

### `Track`

Indicates the track number where the CD-ROM driver must read the Q subchannel data. If **Format** is set to IOCTL_CDROM_MEDIA_CATALOG, then the **Track** member must be set to zero.

## Remarks

The CDROM_SUB_Q_DATA_FORMAT structure indicates the track from which to read the Q part of the subchannel data and the format of the read.

## See also

[IOCTL_CDROM_READ_Q_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_read_q_channel)

[SUB_Q_CHANNEL_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_sub_q_channel_data)

[SUB_Q_CURRENT_POSITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_sub_q_current_position)

[SUB_Q_MEDIA_CATALOG_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_sub_q_media_catalog_number)

[SUB_Q_TRACK_ISRC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_sub_q_track_isrc)