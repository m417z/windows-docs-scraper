# _DISK_CACHE_INFORMATION structure

## Description

The DISK_CACHE_INFORMATION structure is used with the [IOCTL_DISK_GET_CACHE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_get_cache_information) request to retrieve cache information.

## Members

### `ParametersSavable`

Indicates, when set to 1, that the device is capable of saving any parameters in nonvolatile storage.

### `ReadCacheEnabled`

Indicates, when set to 1, that the read cache is enabled.

### `WriteCacheEnabled`

Indicates, when set to 1, that the write cache is enabled.

### `ReadRetentionPriority`

Determines the likelihood of various types of data remaining in the cache. By means of this value, for instance, data cached from a READ or WRITE operation might be given a different priority than data cached under other circumstances, such as prefetch operations. Thus a value of **EqualPriority** indicates that no data is held in the cache on a preferential basis. When **ReadRetentionPriority** is set to **EqualPriority**, all types of data have equal access to cache memory. On the other hand, a value of **KeepPrefetchedData** indicates that a preference is to be given to prefetched data while a value of **KeepReadData** indicates that a preference is to be given to data cached from a READ operation. For more information about the values that can be assigned to this member see the [DISK_CACHE_RETENTION_PRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ne-ntdddisk-disk_cache_retention_priority) enumeration.

### `WriteRetentionPriority`

See discussion under **ReadRetentionPriority**.

### `DisablePrefetchTransferLength`

Disables prefetching. Prefetching might be disabled whenever the number of blocks requested exceeds the value in **DisablePrefetchTransferLength**. When zero, prefetching is disabled no matter what the size of the block request.

### `PrefetchScalar`

When **TRUE**, Indicates that **ScalarPrefetch.Maximum** should be used together with the transfer length to calculate the amount of data that can be prefetched. When **FALSE**, **BlockPrefetch.Maximum** will be the maximum number of disk blocks that can be prefetched.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.ScalarPrefetch`

### `DUMMYUNIONNAME.ScalarPrefetch.Minimum`

Contains the scalar multiplier of the transfer length of the request when **PrefetchScalar** is **TRUE**. If **PrefetchScalar** is **TRUE**, the value in **ScalarPrefetch.Minimum** is multiplied by the transfer length to obtain the minimum amount of data that can be prefetched into the cache on a disk operation.

### `DUMMYUNIONNAME.ScalarPrefetch.Maximum`

Contains the scalar multiplier of the transfer length of the request when **PrefetchScalar** is **TRUE**. If **PrefetchScalar** is **TRUE**, the value in **ScalarPrefetch.Maximum** is multiplied by the transfer length to obtain the maximum amount of data that can be prefetched into the cache on a disk operation.

### `DUMMYUNIONNAME.ScalarPrefetch.MaximumBlocks`

Contains the maximum size, in blocks, of the transfer length.

### `DUMMYUNIONNAME.BlockPrefetch`

### `DUMMYUNIONNAME.BlockPrefetch.Minimum`

Contains the scalar multiplier of the transfer length of the request when **PrefetchScalar** is **TRUE**. If **PrefetchScalar** is **TRUE**, the value in **ScalarPrefetch.Minimum** is multiplied by the transfer length to obtain the minimum amount of data that can be prefetched into the cache on a disk operation.

### `DUMMYUNIONNAME.BlockPrefetch.Maximum`

Contains the scalar multiplier of the transfer length of the request when **PrefetchScalar** is **TRUE**. If **PrefetchScalar** is **TRUE**, the value in **ScalarPrefetch.Maximum** is multiplied by the transfer length to obtain the maximum amount of data that can be prefetched into the cache on a disk operation.

## See also

[DISK_CACHE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_cache_information)

[IOCTL_DISK_GET_CACHE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_get_cache_information)