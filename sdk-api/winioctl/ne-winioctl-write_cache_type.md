# WRITE_CACHE_TYPE enumeration

## Description

Specifies the cache type.

## Constants

### `WriteCacheTypeUnknown`

The system cannot report the type of the write cache.

### `WriteCacheTypeNone`

The device does not have a write cache.

### `WriteCacheTypeWriteBack`

The device has a write-back cache.

### `WriteCacheTypeWriteThrough`

The device has a write-through cache.

## Remarks

There are two main types of write cache: *write back* and *write through*. With a write-back cache, the device does not copy cache data to nonvolatile media until absolutely necessary. This type of operation improves the performance of write operations. With a write-through cache, the device writes data to the cache and the media in parallel. This type of operation does not improve write performance, but it makes subsequent read operations faster.

The [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_query_property) control code reports a **WRITE_CACHE_TYPE** value in the [STORAGE_WRITE_CACHE_PROPERTY](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_write_cache_property) structure.

## See also

* [Disk Management Enumeration Types](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-enumeration-types)
* [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_query_property)
* [STORAGE_WRITE_CACHE_PROPERTY](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_write_cache_property)