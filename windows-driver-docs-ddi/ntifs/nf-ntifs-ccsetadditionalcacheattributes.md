# CcSetAdditionalCacheAttributes function

## Description

Call the **CcSetAdditionalCacheAttributes** routine to enable or disable read-ahead (also called "lazy read") or write-behind (also called "lazy write") on a cached file.

## Parameters

### `FileObject` [in]

Pointer to a file object for the cached file.

### `DisableReadAhead` [in]

Boolean value set to **TRUE** to disable read-ahead, or **FALSE** to enable it.

### `DisableWriteBehind` [in]

Boolean value set to **TRUE** to disable write-behind, or **FALSE** to enable it.

## Remarks

**CcSetAdditionalCacheAttributes** can be called any time after calling [**CcInitializeCacheMap**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccinitializecachemap). Initially, both read-ahead and write-behind are enabled.

## See also

[**CcInitializeCacheMap**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccinitializecachemap)

[**CcReadAhead**](https://learn.microsoft.com/previous-versions/ff539191(v=vs.85))

[**CcSetReadAheadGranularity**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccsetreadaheadgranularity)