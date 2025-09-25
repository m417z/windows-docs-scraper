# DISK_GEOMETRY_EX structure

## Description

Describes the extended geometry of disk devices and media.

## Members

### `Geometry`

A [**DISK_GEOMETRY**](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-disk_geometry) structure.

### `DiskSize`

The disk size, in bytes. See [**LARGE_INTEGER**](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-large_integer-r1).

### `Data`

Any additional data. For more information, see Remarks.

## Remarks

**DISK_GEOMETRY_EX** is a variable-length structure composed of a [**DISK_GEOMETRY**](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-disk_geometry) structure followed by a [**DISK_PARTITION_INFO**](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-disk_partition_info) structure and a [**DISK_DETECTION_INFO**](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-disk_detection_info) structure. Because the detection information is not at a fixed location within the **DISK_GEOMETRY_EX** structure, use the following macro to access the **DISK_DETECTION_INFO** structure.

```cpp
PDISK_DETECTION_INFO DiskGeometryGetDetect(
  PDISK_GEOMETRY_EX Geometry
);
```

Similarly, use the following macro to access the [**DISK_PARTITION_INFO**](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-disk_partition_info) structure.

```cpp
PDISK_PARTITION_INFO DiskGeometryGetPartition(
  PDISK_GEOMETRY_EX Geometry
);
```

The information returned does not include the number of partitions nor the partition information contained in the [**DISK_PARTITION_INFO**](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-disk_partition_info) structure. To obtain this information, use the [**IOCTL_DISK_GET_DRIVE_LAYOUT_EX**](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_disk_get_drive_layout_ex) control code.

## See also

[DISK_GEOMETRY](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-disk_geometry), [DISK_DETECTION_INFO](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-disk_detection_info), [DISK_PARTITION_INFO](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-disk_partition_info), [IOCTL_DISK_GET_DRIVE_GEOMETRY_EX](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_disk_get_drive_geometry_ex)