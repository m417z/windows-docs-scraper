# _SUB_Q_TRACK_ISRC structure

## Description

The SUB_Q_TRACK_ISC contains position information and is used in conjunction with the [SUB_Q_CHANNEL_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_sub_q_channel_data) structure.

## Members

### `Header`

Indicates, among other things, the length of the Q subchannel data that was retrieved. See [SUB_Q_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_sub_q_header) for further details.

### `FormatCode`

Should have a value of IOCTL_CDROM_TRACK_ISRC.

### `Reserved0`

Reserved.

### `Track`

Contains the number for the track for which the ISRC value was requested.

### `Reserved1`

Reserved.

### `Reserved2`

Reserved.

### `Tcval`

Indicates that ISRC data was detected, if set to 1. Otherwise, if set to zero, indicates that **TrackIsrc** is invalid.

### `TrackIsrc`

Contains an array that holds the tracking ISRC data.

## See also

[CDROM_SUB_Q_DATA_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_sub_q_data_format)

[IOCTL_CDROM_READ_Q_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_read_q_channel)

[SUB_Q_CHANNEL_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_sub_q_channel_data)

[SUB_Q_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_sub_q_header)