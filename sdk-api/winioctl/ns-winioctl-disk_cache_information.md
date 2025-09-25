# DISK_CACHE_INFORMATION structure

## Description

Provides information about the disk cache.This structure is used by the [IOCTL_DISK_GET_CACHE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_get_cache_information) and [IOCTL_DISK_SET_CACHE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_set_cache_information) control codes.

## Members

### `ParametersSavable`

Indicates whether the device is capable of saving any parameters in nonvolatile storage.

### `ReadCacheEnabled`

Indicates whether the read cache is enabled.

### `WriteCacheEnabled`

Indicates whether the write cache is enabled.

### `ReadRetentionPriority`

Determines the likelihood of data cached from a read operation remaining in the cache. This data might be given a different priority than data cached under other circumstances, such as from a prefetch operation.

 This member can be one of the following values from the **DISK_CACHE_RETENTION_PRIORITY** enumeration type.

| Value | Meaning |
| --- | --- |
| **EqualPriority**<br><br>0 | No data is held in the cache on a preferential basis. |
| **KeepPrefetchedData**<br><br>1 | A preference is to be given to prefetched data. |
| **KeepReadData**<br><br>2 | A preference is to be given to data cached from a read operation. |

### `WriteRetentionPriority`

Determines the likelihood of data cached from a write operation remaining in the cache. This data might be given a different priority than data cached under other circumstances, such as from a prefetch operation.

### `DisablePrefetchTransferLength`

Disables prefetching. Prefetching might be disabled whenever the number of blocks requested exceeds the value in *DisablePrefetchTransferLength*. When zero, prefetching is disabled no matter what the size of the block request.

### `PrefetchScalar`

If this member is **TRUE**, the union is a **ScalarPrefetch** structure. Otherwise, the union is a **BlockPrefetch** structure.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.ScalarPrefetch`

### `DUMMYUNIONNAME.ScalarPrefetch.Minimum`

The scalar multiplier of the transfer length of the request. This member is valid only when **PrefetchScalar** is **TRUE**. When **PrefetchScalar** is **TRUE**, this value is multiplied by the transfer length to obtain the minimum amount of data that can be prefetched into the cache on a disk operation.

### `DUMMYUNIONNAME.ScalarPrefetch.Maximum`

The scalar multiplier of the transfer length of the request. This member is valid only when **PrefetchScalar** is **TRUE**. When **PrefetchScalar** is **TRUE**, this value is multiplied by the transfer length to obtain the maximum amount of data that can be prefetched into the cache on a disk operation.

### `DUMMYUNIONNAME.ScalarPrefetch.MaximumBlocks`

The maximum number of blocks which can be prefetched.

### `DUMMYUNIONNAME.BlockPrefetch`

### `DUMMYUNIONNAME.BlockPrefetch.Minimum`

The minimum amount of data that can be prefetched into the cache on a disk operation, as an absolute number of disk blocks. This member is valid only when **PrefetchScalar** is **FALSE**.

### `DUMMYUNIONNAME.BlockPrefetch.Maximum`

The maximum amount of data that can be prefetched into the cache on a disk operation, as an absolute number of disk blocks. This member is valid only when **PrefetchScalar** is **FALSE**.

## See also

[IOCTL_DISK_GET_CACHE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_get_cache_information)

[IOCTL_DISK_SET_CACHE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_set_cache_information)