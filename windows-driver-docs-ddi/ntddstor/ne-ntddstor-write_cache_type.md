## Description

The WRITE\_CACHE\_TYPE enumeration specifies the cache type.

## Constants

### `WriteCacheTypeUnknown`

The system cannot report the type of the write cache.

### `WriteCacheTypeNone`

The system cannot report the type of the write cache.

### `WriteCacheTypeWriteBack`

The device has a write back cache.

### `WriteCacheTypeWriteThrough`

The device has a write through cache.

## Remarks

There are two main types of write cache: *write back* and *write through*. With a write-back cache, the device does not copy cache data to nonvolatile media until absolutely necessary. This type of operation improves the performance of write operations. With a write-through cache, the device writes data to the cache and the media in parallel. This type of operation does not improve write performance, but it makes subsequent read operations faster.

The [**IOCTL\_STORAGE\_QUERY\_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property) request reports a WRITE\_CACHE\_TYPE value in the [**STORAGE\_WRITE\_CACHE\_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_write_cache_property) structure.

## See also

[**IOCTL\_STORAGE\_QUERY\_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property)

[**STORAGE\_WRITE\_CACHE\_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_write_cache_property)