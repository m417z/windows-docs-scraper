## Description

The WRITE\_CACHE\_ENABLE enumeration indicates whether the write cache is enabled or disabled.

## Constants

### `WriteCacheEnableUnknown`

The system cannot report whether the device's write cache is enabled or disabled.

### `WriteCacheDisabled`

The device's write cache is disabled.

### `WriteCacheEnabled`

The device's write cache is enabled.

## Remarks

The [**IOCTL\_STORAGE\_QUERY\_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property) request reports a WRITE\_CACHE\_ENABLE value in the [**STORAGE\_WRITE\_CACHE\_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_write_cache_property) structure.

## See also

[**IOCTL\_STORAGE\_QUERY\_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property)

[**STORAGE\_WRITE\_CACHE\_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_write_cache_property)