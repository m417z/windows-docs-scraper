# _DISK_EXTENT structure

## Description

The DISK_EXTENT structure contains information defining the location and length of a volume extent on a disk.

## Members

### `DiskNumber`

Specifies the number of the disk that contains this extent. This is the same disk number that is used to construct the name of the disk (for example, *PhysicalDriveX* or *HarddiskX*, where X is the disk number).

### `StartingOffset`

Specifies the offset, in bytes, from the beginning of the disk.

### `ExtentLength`

Specifies the number of bytes of this extent.

## See also

[IOCTL_VOLUME_GET_VOLUME_DISK_EXTENTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvol/ni-ntddvol-ioctl_volume_get_volume_disk_extents)

[VOLUME_DISK_EXTENTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvol/ns-ntddvol-_volume_disk_extents)