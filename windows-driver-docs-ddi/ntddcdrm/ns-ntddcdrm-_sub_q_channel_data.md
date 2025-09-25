# _SUB_Q_CHANNEL_DATA structure

## Description

Device control IRPs with a control code of IOCTL_CDROM_READ_Q_CHANNEL return their output data in this union.

## Members

### `CurrentPosition`

Contains position information, such as the absolute and relative addresses, in a [SUB_Q_CURRENT_POSITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_sub_q_current_position) structure.

### `MediaCatalog`

Contains the media catalog number in a [SUB_Q_MEDIA_CATALOG_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_sub_q_media_catalog_number) structure.

### `TrackIsrc`

Contains the TrackIsrc code in a [SUB_Q_TRACK_ISRC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_sub_q_track_isrc) structure.

## Remarks

The value of the **Format** member of the CDROM_SUB_Q_DATA_FORMAT structure that is passed as input with IOCTL_CDROM_READ_Q_CHANNEL determines which member of this union is used to return the output data. See [CDROM_SUB_Q_DATA_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_sub_q_data_format) for a detailed explanation.

## See also

[CDROM_SUB_Q_DATA_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_sub_q_data_format)

[IOCTL_CDROM_READ_Q_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_read_q_channel)

[SUB_Q_CURRENT_POSITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_sub_q_current_position)

[SUB_Q_MEDIA_CATALOG_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_sub_q_media_catalog_number)

[SUB_Q_TRACK_ISRC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_sub_q_track_isrc)