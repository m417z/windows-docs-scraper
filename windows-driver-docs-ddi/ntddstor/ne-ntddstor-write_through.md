## Description

The WRITE\_THROUGH enumeration specifies whether a storage device supports write-through caching.

## Constants

### `WriteThroughUnknown`

Indicates that no information is available concerning the writethrough capabilities of the device.

### `WriteThroughNotSupported`

Indicates that the device does not support writethrough operations.

### `WriteThroughSupported`

Indicates that the device supports writethrough operations.

## Remarks

The [**IOCTL\_STORAGE\_QUERY\_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property) request reports this value in the [**STORAGE\_WRITE\_CACHE\_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_write_cache_property) structure.

## See also

[**IOCTL\_STORAGE\_QUERY\_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property)

[**STORAGE\_WRITE\_CACHE\_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_write_cache_property)