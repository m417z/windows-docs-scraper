# _STORAGE_WRITE_CACHE_PROPERTY structure

## Description

The STORAGE_WRITE_CACHE_PROPERTY structure is used with the [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property) request to retrieve information about a device's write cache property.

## Members

### `Version`

The version number of the write cache property.

### `Size`

The size, in bytes, of the STORAGE_WRITE_CACHE_PROPERTY structure.

### `WriteCacheType`

A [WRITE_CACHE_TYPE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff568044(v=vs.85))-typed value that indicates the current write cache type

### `WriteCacheEnabled`

A [WRITE_CACHE_ENABLE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff568042(v=vs.85))-typed value that indicates whether the write cache is enabled.

### `WriteCacheChangeable`

A [WRITE_CACHE_CHANGE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff568039(v=vs.85))-typed value that indicates whether if the host can change the write cache characteristics.

### `WriteThroughSupported`

A [WRITE_THROUGH](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff568047(v=vs.85))-typed value that indicates whether the device supports write-through caching.

### `FlushCacheSupported`

A Boolean value that indicates whether the device allows host software to flush the device cache. If **TRUE**, the device allows host software to flush the device cache. If **FALSE**, host software cannot flush the device cache.

### `UserDefinedPowerProtection`

A Boolean value that indicates whether a user can configure the device's power protection characteristics in the registry. If **TRUE**, a user can configure the device's power protection characteristics in the registry. If **FALSE**, the user cannot configure the device's power protection characteristics in the registry.

### `NVCacheEnabled`

A Boolean value that indicates whether the device has a battery backup for the write cache. If **TRUE**, the device has a battery backup for the write cache. If **FALSE**, the device does not have a battery backup for the writer cache.

## Remarks

All of the parameter values that are described in this topic refer to the output of the [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property) request.

## See also

[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property)