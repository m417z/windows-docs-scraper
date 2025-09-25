# CcSetReadAheadGranularity function

## Description

The **CcSetReadAheadGranularity** routine sets the read-ahead granularity for a cached file.

## Parameters

### `FileObject` [in]

Pointer to a file object for the cached file whose read-ahead granularity is to be set.

### `Granularity` [in]

Specifies the desired read-ahead granularity, which must be an even power of two and must be greater than or equal to PAGE_SIZE.

## Remarks

After [CcInitializeCacheMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccinitializecachemap) is called to cache a file, but before **CcSetReadAheadGranularity** is called for the cached file, the default read-ahead granularity for the cached file is equal to PAGE_SIZE.

## See also

[CcInitializeCacheMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccinitializecachemap)

[CcReadAhead](https://learn.microsoft.com/previous-versions/ff539191(v=vs.85))

[CcScheduleReadAhead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccschedulereadahead)

[CcSetAdditionalCacheAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccsetadditionalcacheattributes)