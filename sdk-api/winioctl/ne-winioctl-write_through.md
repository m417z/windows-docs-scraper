# WRITE_THROUGH enumeration

## Description

Specifies whether a storage device supports write-through caching.

## Constants

### `WriteThroughUnknown`

Indicates that no information is available about the write-through capabilities of the device.

### `WriteThroughNotSupported`

Indicates that the device does not support write-through caching.

### `WriteThroughSupported`

Indicates that the device supports write-through caching.

## Remarks

The [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_query_property) control code reports this value in the [STORAGE_WRITE_CACHE_PROPERTY](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_write_cache_property) structure.

## See also

* [Disk Management Enumeration Types](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-enumeration-types)
* [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_query_property)
* [STORAGE_WRITE_CACHE_PROPERTY](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_write_cache_property)