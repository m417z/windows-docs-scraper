# DISK_EXTENT structure

## Description

Represents a disk extent.

## Members

### `DiskNumber`

The number of the disk that contains this extent.

This is the same number that is used to construct the name of the disk, for example, the *X* in "\\\\?\\PhysicalDrive*X*" or "\\\\?\\\Harddisk*X*".

### `StartingOffset`

The offset from the beginning of the disk to the extent, in bytes.

### `ExtentLength`

The number of bytes in this extent.

## See also

* [IOCTL_VOLUME_GET_VOLUME_DISK_EXTENTS](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_volume_get_volume_disk_extents)
* [LARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-large_integer-r1)
* [VOLUME_DISK_EXTENTS](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-volume_disk_extents)