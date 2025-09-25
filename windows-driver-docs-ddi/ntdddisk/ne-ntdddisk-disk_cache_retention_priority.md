# DISK_CACHE_RETENTION_PRIORITY enumeration

## Description

The DISK_CACHE_RETENTION_PRIORITY enumeration is used in conjunction with the [IOCTL_DISK_GET_CACHE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_get_cache_information) request and the structure [DISK_CACHE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_cache_information) to indicate which kinds data are to be held in the cache on a preferential basis.

## Constants

### `EqualPriority`

Indicates that no data is held in the cache on a preferential basis. All types of data have equal access to cache memory.

### `KeepPrefetchedData`

Indicates that a preference is to be given to prefetched data.

### `KeepReadData`

Indicates that a preference is to be given to data cached from a READ operation.

## See also

[DISK_CACHE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_cache_information)

[IOCTL_DISK_GET_CACHE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_get_cache_information)