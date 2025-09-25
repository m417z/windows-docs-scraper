# _HYBRID_INFORMATION structure

## Description

The **HYBRID_INFORMATION** structure contains hybrid disk capability information. The structure is returned when the HYBRID_FUNCTION_GET_INFO function is selected in a [IOCTL_SCSI_MINIPORT_HYBRID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_miniport_hybrid) request sent to an HBA miniport driver.

## Members

### `Version`

The version of this structure. Set to HYBRID_REQUEST_INFO_STRUCTURE_VERSION.

### `Size`

The size of this structure. Set to **sizeof**(HYBRID_INFORMATION).

### `HybridSupported`

Miniport supports for hybrid disks. Set to **TRUE** if hybrid disks are supported. Otherwise, **FALSE**.

### `Status`

The status of the hybrid disk cache. This contains one of the following values.

| Value | Meaning |
| --- | --- |
| **NvCacheStatusUnknown** | The miniport driver is not able to report the cache status. |
| **NvCacheStatusDisabling** | The cache is currently changing to **NvCacheStatusDisabled** status. |
| **NvCacheStatusDisabled** | The cache on the hybrid disk is disabled. |
| **NvCacheStatusEnabled** | The cache on the hybrid disk is enabled. |

### `CacheTypeEffective`

The non-volatile caching type currently set for hybrid disk. The effective cache type is one of the following values.

| Value | Meaning |
| --- | --- |
| **NvCacheTypeUnknown** | The miniport driver is not able to report the cache type |
| **NvCacheNone** | The disk does not support a non-volatile cache. |
| **NvCacheTypeWriteBack** | Write-back caching is supported by hybrid disk. |
| **NvCacheTypeWriteThrough** | Write-through caching is supported by hybrid disk. |

### `CacheTypeDefault`

The default caching type used by the hybrid disk. The possible values are the same as for **CacheTypeEffective**.

### `FractionBase`

The base value for fractional fields in this structure. This value is set to 255.

### `CacheSize`

The size, in LBAs, of the non-volatile on the hybrid disk.

### `Attributes`

The hybrid disk attributes.

### `Attributes.WriteCacheChangeable`

Support for changes in write caching policy. The value is 1 policy changes are allowed. Otherwise, changes are ignored.

### `Attributes.WriteThroughIoSupported`

Support for individual write operations when write-through caching is used. The value is 1 if individual writes are supported. Otherwise, the values is 0.

### `Attributes.FlushCacheSupported`

Support for non-volatile cache flush. The value is 1 if flushes are supported. Otherwise, the value is 0.

### `Attributes.Removable`

Support of removal of the non-volatile cache from the disk. The value is 1 if the cache is removable. Otherwise, the value is 0.

### `Attributes.ReservedBits`

Reserved.

### `Priorities`

Priority settings for the hybrid disk.

### `Priorities.PriorityLevelCount`

The number of priority levels supported by the cache. Currently, a non-zero value indicates support for all priorities.

### `Priorities.MaxPriorityBehavior`

If **TRUE**, the disk I/O can fail at maximum priority if the cache is full. Otherwise, if **FALSE**, the operation will complete to disk.

### `Priorities.OptimalWriteGranularity`

### `Priorities.Reserved`

### `Priorities.DirtyThresholdLow`

The low threshold for a cache flush. This value is ratio in the range of **FractionBase**.

### `Priorities.DirtyThresholdHigh`

The low threshold for a cache flush. This value is ratio in the range of **FractionBase**.

### `Priorities.SupportedCommands`

Support for non-volatile cache specific commands to the hybrid disk.

### `Priorities.SupportedCommands.CacheDisable`

Support for changes in write caching policy. The value is 1 policy changes are allowed. Otherwise, changes are ignored.

### `Priorities.SupportedCommands.SetDirtyThreshold`

Support for individual write operations when write-through caching is used. The value is 1 if individual writes are supported. Otherwise, the values is 0.

### `Priorities.SupportedCommands.PriorityDemoteBySize`

Support for non-volatile cache flush. The value is 1 if flushes are supported. Otherwise, the value is 0.

### `Priorities.SupportedCommands.PriorityChangeByLbaRange`

Support for LBA range priority changes. The value is 1 if priority changes are supported. Otherwise, the value is 0.

### `Priorities.SupportedCommands.Evict`

Support of removal of the non-volatile cache from the disk. The value is 1 if the cache is removable. Otherwise, the value is 0.

### `Priorities.SupportedCommands.ReservedBits`

Reserved.

### `Priorities.SupportedCommands.MaxEvictCommands`

The maximum concurrent Evict commands allowed that are outstanding. This value is valid when **Evict** is set to 1.

### `Priorities.SupportedCommands.MaxLbaRangeCountForEvict`

The maximum number of LBA ranges possible to associate with an Evict command. This value is valid when **Evict** is set to 1.

### `Priorities.SupportedCommands.MaxLbaRangeCountForChangeLba`

The maximum number of LBA ranges possible to associate with a Priority Change command. This value is valid when **PriorityChangeByLbaRange** is set to 1.

### `Priorities.Priority`

An array of priority level descriptors. The number of descriptors present in the array is set in **PriorityLevelCount**.

## See also

[IOCTL_SCSI_MINIPORT_HYBRID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_miniport_hybrid)