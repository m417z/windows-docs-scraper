# PLEX_READ_DATA_REQUEST structure

## Description

Indicates the range of the read operation to perform and the plex from which to read.

## Members

### `ByteOffset`

The offset of the range to be read. The offset can be the virtual offset to a file or volume. File offsets should be cluster aligned and volume offsets should be sector aligned.

### `ByteLength`

The length of the range to be read. The maximum value is 64 KB.

### `PlexNumber`

The plex from which to read. A value of zero indicates the primary copy, a value of one indicates the secondary copy, and so on.

## See also

[FSCTL_READ_FROM_PLEX](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_read_from_plex)