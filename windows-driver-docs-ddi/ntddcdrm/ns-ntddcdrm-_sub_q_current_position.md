# _SUB_Q_CURRENT_POSITION structure

## Description

The SUB_Q_CURRENT_POSITION structure contains position information and is used in conjunction with [SUB_Q_CHANNEL_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_sub_q_channel_data).

## Members

### `Header`

Indicates, among other things, the length of the Q subchannel data that was retrieved. See [SUB_Q_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_sub_q_header) for more details.

### `FormatCode`

Should have a value of IOCTL_CDROM_CURRENT_POSITION.

### `Control`

Defines various types of information within the table of contents lead-in area. For more information about the permissible values for this member, see specification *T10/1363-D*, by National Committee for Information Technology Standards (NCITS).

### `ADR`

Indicates the type of information encoded in the Q subchannel of the block. For information about the permissible values for this member, see specification *T10/1363-D*, by National Committee for Information Technology Standards (NCITS).

### `TrackNumber`

Contains the current track number.

### `IndexNumber`

Contains the current index number.

### `AbsoluteAddress`

Gives the current location relative to the logical beginning of the media. The bytes in this array are arranged in big-endian order. **AbsoluteAddress**[0] contains the most significant byte, and **AbsoluteAddress**[3] contains the least significant byte.

### `TrackRelativeAddress`

Gives the current location relative to the logical beginning of the current track. The bytes in this array are arranged in big-endian order. **TrackRelativeAddress**[0] contains the most significant byte, and **TrackRelativeAddress**[3] contains the least significant byte.

## See also

[CDROM_SUB_Q_DATA_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_sub_q_data_format)

[IOCTL_CDROM_READ_Q_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_read_q_channel)

[SUB_Q_CHANNEL_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_sub_q_channel_data)

[SUB_Q_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_sub_q_header)