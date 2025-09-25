# VOLUME_DISK_EXTENTS structure

## Description

Represents a physical location on a disk. It is the output buffer for the
[IOCTL_VOLUME_GET_VOLUME_DISK_EXTENTS](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_volume_get_volume_disk_extents)
control code.

## Members

### `NumberOfDiskExtents`

The number of disks in the volume (a volume can span multiple disks).

An extent is a contiguous run of sectors on one disk. When the number of extents returned is greater than
one (1), the error code **ERROR_MORE_DATA** is returned. You should call
[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) again, allocating enough buffer
space based on the value of **NumberOfDiskExtents** after the first
**DeviceIoControl** call.

### `Extents`

An array of [DISK_EXTENT](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-disk_extent) structures.

## See also

[DISK_EXTENT](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-disk_extent)

[IOCTL_VOLUME_GET_VOLUME_DISK_EXTENTS](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_volume_get_volume_disk_extents)