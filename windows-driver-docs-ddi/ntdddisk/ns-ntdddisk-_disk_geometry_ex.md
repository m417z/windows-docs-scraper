# _DISK_GEOMETRY_EX structure

## Description

The DISK_GEOMETRY_EX structure is an arbitrary-length structure composed of a [DISK_GEOMETRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_geometry) structure followed by a [DISK_PARTITION_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_partition_info) structure followed, in turn, by a [DISK_DETECTION_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_detection_info) structure.

## Members

### `Geometry`

See [DISK_GEOMETRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_geometry) for a description of this member.

### `DiskSize`

Contains the size in bytes of the disk.

### `Data`

Beginning of the data block, starting with a [DISK_PARTITION_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_partition_info) structure followed by a [DISK_DETECTION_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_detection_info) structure.

## Remarks

DISK_GEOMETRY_EX is used in conjunction with the [IOCTL_DISK_GET_DRIVE_GEOMETRY_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_get_drive_geometry_ex) and the [IOCTL_DISK_GET_MEDIA_TYPES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_get_media_types) IOCTLs, in order to retrieve information about the geometry of a physical disk (media type, number of cylinders, tracks per cylinder, sectors per track, and bytes per sector).

Because the partition and detect information are not at fixed locations within the DISK_GEOMETRY_EX structure, *ntdddisk.h* provides two macros for accessing this information. Both macros take a pointer to a structure of type DISK_GEOMETRY_EX as an argument:

```cpp
#if (NTDDI_VERSION < NTDDI_WS03)
#define DiskGeometryGetPartition(Geometry)\
                        ((PDISK_PARTITION_INFO)((Geometry)+1))

#define DiskGeometryGetDetect(Geometry)\
                        ((PDISK_DETECTION_INFO)(((PBYTE)DiskGeometryGetPartition(Geometry)+\
                                        DiskGeometryGetPartition(Geometry)->SizeOfPartitionInfo)))
#else
#define DiskGeometryGetPartition(Geometry)\
                        ((PDISK_PARTITION_INFO)((Geometry)->Data))

#define DiskGeometryGetDetect(Geometry)\
                        ((PDISK_DETECTION_INFO)(((ULONG_PTR)DiskGeometryGetPartition(Geometry)+\
                                        DiskGeometryGetPartition(Geometry)->SizeOfPartitionInfo)))
#endif
```

## See also

[DISK_DETECTION_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_detection_info)

[DISK_GEOMETRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_geometry)

[DISK_PARTITION_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_partition_info)

[IOCTL_DISK_GET_DRIVE_GEOMETRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_get_drive_geometry)

[IOCTL_DISK_GET_MEDIA_TYPES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_get_media_types)