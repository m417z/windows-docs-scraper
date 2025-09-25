# _SUB_Q_MEDIA_CATALOG_NUMBER structure

## Description

The SUB_Q_MEDIA_CATALOG_NUMBER structure contains position information and is used in conjunction with the [SUB_Q_CHANNEL_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_sub_q_channel_data) structure.

## Members

### `Header`

Indicates, among other things, the length of the Q subchannel data that was retrieved. See [SUB_Q_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_sub_q_header) for further details.

### `FormatCode`

Should have a value of IOCTL_CDROM_MEDIA_CATALOG.

### `Reserved`

Reserved.

### `Reserved1`

Reserved.

### `Mcval`

Indicates that the media catalog number (MCN) data is valid if set to 1; set to zero otherwise.

### `MediaCatalog`

Contains the catalog number if **Mcval** is set to 1.

## See also

[CDROM_SUB_Q_DATA_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_sub_q_data_format)

[IOCTL_CDROM_READ_Q_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_read_q_channel)

[SUB_Q_CHANNEL_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_sub_q_channel_data)

[SUB_Q_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_sub_q_header)