# _DISK_COPY_DATA_PARAMETERS structure

## Description

DISK_COPY_DATA_PARAMETERS is used with IOCTL_DISK_COPY_DATA to copy data from one area of the disk to another.

## Members

### `SourceOffset`

Contains the byte offset of the source for the copy. This number must be sector-aligned.

### `DestinationOffset`

Contains the byte offset of the destination of the copy. This number must be sector-aligned.

### `CopyLength`

Contains the number of bytes to copy. This number must be sector-aligned.

### `Reserved`

Must be zero.

## Remarks

The source and destination areas must not overlap.

## See also

[IOCTL_DISK_COPY_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_copy_data)