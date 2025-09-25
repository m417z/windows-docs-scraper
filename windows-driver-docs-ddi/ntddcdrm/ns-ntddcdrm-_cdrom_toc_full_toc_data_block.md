# _CDROM_TOC_FULL_TOC_DATA_BLOCK structure

## Description

The CDROM_TOC_FULL_TOC_DATA_BLOCK structure contains track descriptor data used in conjunction with the data from the [CDROM_TOC_FULL_TOC_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_toc_full_toc_data) structure.

## Members

### `SessionNumber`

Contains the number of the session that the track belongs to.

### `Control`

Indicates the attributes of the track. Can be a combination of the following values.

| Attribute | Description |
| --------- | ----------- |
| AUDIO_WITH_PREEMPHASIS | Two audio channels with preemphasis of 50/15 microseconds have been added. |
| DIGITAL_COPY_PERMITTED | Digital copying is allowed. |
| AUDIO_DATA_TRACK | The track contains nonaudio data. |
| TWO_FOUR_CHANNEL_AUDIO | The track contains four channels of audio data. |

### `Adr`

Indicates the type of information encoded in the Q subchannel of the block where this table of contents entry was found. Can be one of the following values.

| Type | Description |
| ---- | ----------- |
| ADR_NO_MODE_INFORMATION | Q subchannel mode information not supplied. |
| ADR_ENCODES_CURRENT_POSITION | Q subchannel encodes current position data. |
| ADR_ENCODES_MEDIA_CATALOG | Q subchannel encodes media catalog number. |
| ADR_ENCODES_ISRC | Q subchannel encodes ISRC. |

### `Reserved1`

Reserved.

### `Point`

Defines various types of information within the table of contents lead-in area. For information about the permissible values for this member, see specification *T10/1363-D*, by National Committee for Information Technology Standards (NCITS).

### `MsfExtra`

See specification *T10/1363-D*, by National Committee for Information Technology Standards (NCITS) For information about the permissible values for this member.

### `Zero`

Contains the value of the zero bit.

### `Msf`

Contains the minute, second, and frame. Msf[0] contains the minutes field. Msf[1] contains the seconds field, and Msf[2] contains the frames field. MSF is a format similar to logical block addressing.

## See also

[CDROM_READ_TOC_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_read_toc_ex)

[CDROM_TOC_FULL_TOC_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_toc_full_toc_data)

[IOCTL_CDROM_READ_TOC_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_read_toc_ex)