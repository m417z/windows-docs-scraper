# TRACK_DATA structure

## Description

The TRACK_DATA structure is used in conjunction with [CDROM_TOC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_toc) and [CDROM_TOC_SESSION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_toc_session_data).

## Members

### `Reserved`

Reserved.

### `Control`

Indicates the attributes of the track. For information about the permissible values for this member, see specification *T10/1363-D*, by National Committee for Information Technology Standards (NCITS).

### `Adr`

Indicates the type of information encoded in the Q subchannel of the block where this table of contents entry was found. For information about the permissible values for this member, see specification *T10/1363-D*, by National Committee for Information Technology Standards (NCITS).

### `TrackNumber`

Indicates the number of the track.

### `Reserved1`

Reserved.

### `Address`

Indicates the starting address of the track.

## Remarks

This structure contains table of contents information for a track.

## See also

[CDROM_TOC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_toc)

[CDROM_TOC_SESSION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_toc_session_data)

[IOCTL_CDROM_READ_TOC_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_read_toc_ex)