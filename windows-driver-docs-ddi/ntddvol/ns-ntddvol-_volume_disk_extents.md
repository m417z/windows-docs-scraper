# _VOLUME_DISK_EXTENTS structure

## Description

The VOLUME_DISK_EXTENTS structure is used in conjunction with the [IOCTL_VOLUME_GET_VOLUME_DISK_EXTENTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvol/ni-ntddvol-ioctl_volume_get_volume_disk_extents) request to retrieve information about all the extents on a given volume.

## Members

### `NumberOfDiskExtents`

Indicates the number of extents that comprise the volume, which can span multiple disks.

### `Extents`

Indicates the number of extents that comprise the volume, which can span multiple disks.

## See also

[DISK_EXTENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvol/ns-ntddvol-_disk_extent)

[IOCTL_VOLUME_GET_VOLUME_DISK_EXTENTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvol/ni-ntddvol-ioctl_volume_get_volume_disk_extents)

disk extent