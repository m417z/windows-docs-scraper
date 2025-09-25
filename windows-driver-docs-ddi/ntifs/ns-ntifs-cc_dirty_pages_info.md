## Description

The **CC_DIRTY_PAGES_INFO** structure contains information about dirty page statistics for an external cache.

## Members

### `Version`

The version of the **CC_DIRTY_PAGES_INFO** structure. This field must be set to **CC_DIRTY_PAGES_INFO_V1**.

### `DirtyPageThreshold`

The hard upper limit for dirty pages. The Cache Manager (*Cc*) provides this value to the external cache client.

The external cache client must not exceed this limit and should pause activities that could increase dirty pages beyond this threshold.

### `DirtyPageTarget`

The target limit for dirty pages. *Cc* provides this value to the external cache client.

The external cache client should strive to keep the number of dirty pages at or below this value.

### `CleanLockedCachedPagesThreshold`

The hard upper limit for clean locked cached pages. *Cc* provides this value to the external cache client.

The external cache client must not exceed this limit.

### `CleanLockedCachedPagesTarget`

The target limit for clean locked cached pages. *Cc* provides this value to the external cache client.

The external cache client should aim to maintain the number of clean locked cached pages at or below this value.

### `CurrentDirtyPages`

The current number of dirty pages reported by the external cache client back to the *Cc*. Must be zero when passed from *Cc* to the external cache client's callback.

### `CurrentCleanLockedCachedPages`

The current number of clean locked cached pages reported by the external cache client back to *Cc*. Must be zero when passed from *Cc* to the external cache client's callback.

### `CurrentPagesQueuedForWriting`

The current number of pages queued for writing, reported by the external cache client back to *Cc*. Must be zero when passed from *Cc* to the external cache client's callback.

## Remarks

The **CC_DIRTY_PAGES_INFO** structure facilitates communication between *Cc* and an external cache client regarding the management of dirty pages and clean locked cached pages.

*Cc* provides threshold and target values to the external cache client to guide the client's management strategies.

The external cache client reports back current metrics to *Cc*.

## See also

[**CcUpdateExternalCacheInfoEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccupdateexternalcacheinfoex)

[**PEXTERNAL_CACHE_CALLBACK_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nc-ntifs-pexternal_cache_callback_ex)