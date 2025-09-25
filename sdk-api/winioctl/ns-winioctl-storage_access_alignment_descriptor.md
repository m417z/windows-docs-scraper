# STORAGE_ACCESS_ALIGNMENT_DESCRIPTOR structure

## Description

Used in conjunction with the
[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_query_property) control code to
retrieve the storage access alignment descriptor data for a device.

## Members

### `Version`

Contains the size of this structure, in bytes. The value of this member will change as members are added to
the structure.

### `Size`

Specifies the total size of the data returned, in bytes. This may include data that follows this
structure.

### `BytesPerCacheLine`

The number of bytes in a cache line of the device.

### `BytesOffsetForCacheAlignment`

The address offset necessary for proper cache access alignment, in bytes.

### `BytesPerLogicalSector`

The number of bytes in a logical sector of the device.

### `BytesPerPhysicalSector`

The number of bytes in a physical sector of the device.

### `BytesOffsetForSectorAlignment`

The logical sector offset within the first physical sector where the first logical sector is placed, in bytes.

Example: Offset = 3 Logical sectors

``` syntax
+---------+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
|LBA      |##|##|##|00|01|02|03|04|05|06|07|08|09|10|11|12|13|14|15|16|17|
+---------+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
|Physical |                       |                       |                ...
|Sector   |           0           |           1           |           2
+---------+-----------------------+-----------------------+---------------
```

In this example, `BytesOffsetForSectorAlignment = 3 * BytesPerLogicalSector`.

## See also

[Disk Management Structures](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-structures)

[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_query_property)