# CcWaitForCurrentLazyWriterActivity function

## Description

The **CcWaitForCurrentLazyWriterActivity** routine puts the caller into a wait state until the current batch of lazy writer activity is completed.

## Return value

**CcWaitForCurrentLazyWriterActivity** can return one of the following NTSTATUS values:

## Remarks

**CcWaitForCurrentLazyWriterActivity** puts the calling thread into a wait state until all work items currently in the lazy writer (read ahead or write behind) work queue have completed.

To prevent deadlock, the caller should release any currently held synchronization objects before calling **CcWaitForCurrentLazyWriterActivity**.

## See also

[CcInitializeCacheMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccinitializecachemap)

[CcReadAhead](https://learn.microsoft.com/previous-versions/ff539191(v=vs.85))

[CcSetAdditionalCacheAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccsetadditionalcacheattributes)

[CcSetReadAheadGranularity](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccsetreadaheadgranularity)