## Description

The WRITE\_CACHE\_CHANGE enumeration indicates whether the write cache features of a device are changeable or not.

## Constants

### `WriteCacheChangeUnknown`

The system cannot report the write cache change capability of the device.

### `WriteCacheNotChangeable`

Host software cannot change the characteristics of the device's write cache.

### `WriteCacheChangeable`

Host software can change the characteristics of the device's write cache.

## Remarks

The [**IOCTL\_STORAGE\_QUERY\_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property) request reports a WRITE\_CACHE\_CHANGE value in the [**STORAGE\_WRITE\_CACHE\_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_write_cache_property) structure.

## See also

[**IOCTL\_STORAGE\_QUERY\_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property)

[**STORAGE\_WRITE\_CACHE\_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_write_cache_property)