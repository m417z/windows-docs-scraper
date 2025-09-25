# _VOLUME_READ_PLEX_INPUT structure

## Description

This structure is used in conjunction with [IOCTL_VOLUME_READ_PLEX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvol/ni-ntddvol-ioctl_volume_read_plex) to read data from a specific [plex](https://learn.microsoft.com/windows-hardware/drivers/) in a volume.

## Members

### `ByteOffset`

Supplies the start offset, in bytes, relative to the beginning of the volume. This member must be aligned on a 512-byte boundary.

### `Length`

Supplies the length, in bytes, of the block to be read. This member must be an integer multiple of 512 bytes.

### `PlexNumber`

Supplies the zero-based plex number.

## See also

[IOCTL_VOLUME_READ_PLEX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvol/ni-ntddvol-ioctl_volume_read_plex)