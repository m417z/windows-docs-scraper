# WRITE_CACHE_ENABLE enumeration

## Description

Indicates whether the write cache is enabled or disabled.

## Constants

### `WriteCacheEnableUnknown`

The system cannot report whether the device's write cache is enabled or disabled.

### `WriteCacheDisabled`

The device's write cache is disabled.

### `WriteCacheEnabled`

The device's write cache is enabled.

## Remarks

The [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_query_property) control code reports a **WRITE_CACHE_ENABLE** value in the [STORAGE_WRITE_CACHE_PROPERTY structure](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_write_cache_property).

## See also

* [Disk Management Enumeration Types](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-enumeration-types)
* [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_query_property)
* [STORAGE_WRITE_CACHE_PROPERTY structure](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_write_cache_property)