# WRITE_CACHE_CHANGE enumeration

## Description

Indicates whether the write cache features of a device are changeable.

## Constants

### `WriteCacheChangeUnknown`

The system cannot report the write cache change capability of the device.

### `WriteCacheNotChangeable`

Host software cannot change the characteristics of the device's write cache.

### `WriteCacheChangeable`

Host software can change the characteristics of the device's write cache.

## Remarks

The [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_query_property) request returns a **WRITE_CACHE_CHANGE** value in the [STORAGE_WRITE_CACHE_PROPERTY](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_write_cache_property) structure.

## See also

* [Disk Management Enumeration Types](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-enumeration-types)
* [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_query_property)
* [STORAGE_WRITE_CACHE_PROPERTY](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_write_cache_property)