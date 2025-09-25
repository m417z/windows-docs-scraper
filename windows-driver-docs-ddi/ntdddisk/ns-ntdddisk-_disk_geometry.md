# _DISK_GEOMETRY structure

## Description

The DISK_GEOMETRY structure is obsolete and provided only to support existing drivers. New drivers must use [DISK_GEOMETRY_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_geometry_ex). DISK_GEOMETRY is used in conjunction with the [IOCTL_DISK_GET_DRIVE_GEOMETRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_get_drive_geometry) and the [IOCTL_DISK_GET_MEDIA_TYPES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_get_media_types) requests, in order to retrieve information about the geometry of a physical disk.

## Members

### `Cylinders`

Indicates the number of cylinders on the disk device.

### `MediaType`

Indicates the type of disk. The enumeration [MEDIA_TYPE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff562216(v=vs.85)) lists the values that can be assigned to this member.

### `TracksPerCylinder`

Indicates the number of tracks in a cylinder.

### `SectorsPerTrack`

Indicates the number of sectors in each track.

### `BytesPerSector`

Indicates the number of bytes in a disk sector.

## Remarks

[DISK_GEOMETRY_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_geometry_ex) must be used with new drivers, in order to accommodate GUID Partition Table (GPT) partitions. The DISK_GEOMETRY structure is nested within the DISK_GEOMETRY_EX structure.

[IOCTL_DISK_GET_MEDIA_TYPES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_get_media_types) causes an array of these structures to be returned.

## See also

[DISK_GEOMETRY_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_geometry_ex)

[IOCTL_DISK_GET_DRIVE_GEOMETRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_get_drive_geometry)

[IOCTL_DISK_GET_MEDIA_TYPES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_get_media_types)