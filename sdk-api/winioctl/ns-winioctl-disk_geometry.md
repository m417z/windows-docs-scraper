# DISK_GEOMETRY structure

## Description

Describes the geometry of disk devices and media.

## Members

### `Cylinders`

The number of cylinders. See [**LARGE_INTEGER**](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-large_integer-r1).

### `MediaType`

The type of media. For a list of values, see [MEDIA_TYPE](https://learn.microsoft.com/windows/win32/api/winioctl/ne-winioctl-media_type).

### `TracksPerCylinder`

The number of tracks per cylinder.

### `SectorsPerTrack`

The number of sectors per track.

### `BytesPerSector`

The number of bytes per sector.

## See also

[IOCTL_DISK_GET_DRIVE_GEOMETRY](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_disk_get_drive_geometry), [IOCTL_STORAGE_GET_MEDIA_TYPES](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_get_media_types), [MEDIA_TYPE](https://learn.microsoft.com/windows/win32/api/winioctl/ne-winioctl-media_type)