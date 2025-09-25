# STORAGE_WRITE_CACHE_PROPERTY structure

## Description

Used with the [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_query_property) control code to retrieve information about a device's write cache property.

## Members

### `Version`

Contains the size of this structure, in bytes. The value of this member will change as members are added to
the structure.

### `Size`

Specifies the total size of the data returned, in bytes. This may include data that follows this
structure.

### `WriteCacheType`

A value from the [WRITE_CACHE_TYPE](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-write_cache_type) enumeration
that indicates the current write cache type.

| Value | Meaning |
| --- | --- |
| **WriteCacheTypeUnknown**<br><br>0 | The system cannot report the type of the write cache. |
| **WriteCacheTypeNone**<br><br>1 | The device does not have a write cache. |
| **WriteCacheTypeWriteBack**<br><br>2 | The device has a write-back cache. |
| **WriteCacheTypeWriteThrough**<br><br>3 | The device has a write-through cache. |

### `WriteCacheEnabled`

A value from the [WRITE_CACHE_ENABLE](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-write_cache_enable) enumeration
that indicates whether the write cache is enabled.

| Value | Meaning |
| --- | --- |
| **WriteCacheEnableUnknown**<br><br>0 | The system cannot report whether the device's write cache is enabled or disabled. |
| **WriteCacheDisabled**<br><br>1 | The device's write cache is disabled. |
| **WriteCacheEnabled**<br><br>2 | The device's write cache is enabled. |

### `WriteCacheChangeable`

A value from the [WRITE_CACHE_CHANGE](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-write_cache_change) enumeration that
indicates whether if the host can change the write cache characteristics.

| Value | Meaning |
| --- | --- |
| **WriteCacheChangeUnknown**<br><br>0 | The system cannot report the write cache change capability of the device. |
| **WriteCacheNotChangeable**<br><br>1 | Host software cannot change the characteristics of the device's write cache |
| **WriteCacheChangeable**<br><br>2 | Host software can change the characteristics of the device's write cache |

### `WriteThroughSupported`

A value from the [WRITE_THROUGH](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-write_through) enumeration that indicates whether the device supports write-through caching.

| Value | Meaning |
| --- | --- |
| **WriteThroughUnknown**<br><br>0 | Indicates that no information is available concerning the write-through capabilities of the device. |
| **WriteThroughNotSupported**<br><br>1 | Indicates that the device does not support write-through operations. |
| **WriteThroughSupported**<br><br>2 | Indicates that the device supports write-through operations. |

### `FlushCacheSupported`

A **BOOLEAN** value that indicates whether the device allows host software to
flush the device cache. If **TRUE**, the device allows host software to flush the device
cache. If **FALSE**, host software cannot flush the device cache.

### `UserDefinedPowerProtection`

A **BOOLEAN** value that indicates whether a user can configure the device's power
protection characteristics in the registry. If **TRUE**, a user can configure the device's
power protection characteristics in the registry. If **FALSE**, the user cannot configure
the device's power protection characteristics in the registry.

### `NVCacheEnabled`

A **BOOLEAN** value that indicates whether the device has a battery backup for the
write cache. If **TRUE**, the device has a battery backup for the write cache. If
**FALSE**, the device does not have a battery backup for the writer cache.

## See also

[Disk Management Structures](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-structures)

[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_query_property)