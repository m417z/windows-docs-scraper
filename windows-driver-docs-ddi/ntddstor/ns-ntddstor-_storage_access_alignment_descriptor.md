# _STORAGE_ACCESS_ALIGNMENT_DESCRIPTOR structure

## Description

The STORAGE_ACCESS_ALIGNMENT_DESCRIPTOR structure is used in conjunction with the [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property) request to retrieve the storage access alignment descriptor data for a device.

## Members

### `Version`

Contains the size of the structure STORAGE_ACCESS_ALIGNMENT_DESCRIPTOR. The value of this member will change as members are added to the structure.

### `Size`

Specifies the total size of the descriptor, in bytes.

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

```
+- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
|LBA      |X|X|X|0|1|2|3|4|5|6|7|8|9|10|11|12|13|14|15|16|17|
|- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
|Physical |               |                  |
|Sector   |      0        |        1         |         2
+- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
```

In this example, BytesOffsetForSectorAlignment = 3 * size_of_logical_sector.

## Remarks

Storage class drivers issue a device-control request with the I/O control code [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property) to retrieve this structure, which contains access alignment information for data transfer operations. The structure can be retrieved either from the device object for the bus or from an FDO, which forwards the request to the underlying bus.

## See also

[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property)