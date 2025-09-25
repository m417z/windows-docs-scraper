## Description

The **PEXTERNAL_CACHE_CALLBACK_EX** callback function is called by the cache manager (*Cc*) on every lazy write scan.

## Parameters

### `ExternalCacheContext`

[in] Pointer to the context that identifies the external cache structure. This context was returned by [**CcRegisterExternalCacheEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccregisterexternalcacheex).

### `DirtyPagesInfo`

[in] Pointer to a [**CC_DIRTY_PAGES_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-cc_dirty_pages_info) structure that contains information about dirty page statistics for the external cache.

## Remarks

A client (file system) must register an external cache with *Cc* by calling [**CcRegisterExternalCacheEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccregisterexternalcacheex) before it can receive callbacks from *Cc* during lazy write scans.

The values in **DirtyPagesInfo** are provided by the *Cc* to the external cache client through this callback routine.

Targets (**DirtyPageTarget** and **CleanLockedCachedPagesTarget**) are for defining the upper limits. The client must strive to keep these metrics at or under their target value. When targets are exceeded, the client needs to aggressively bring down the corresponding metric.

Thresholds (**DirtyPageThreshold** and **CleanLockedCachedPagesThreshold**) define the hard upper limit that a client must not cross. The client must therefore pause all activities that could cause thresholds to be exceeded.

## See also

[**CcRegisterExternalCacheEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccregisterexternalcacheex)

[**CC_DIRTY_PAGES_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-cc_dirty_pages_info)