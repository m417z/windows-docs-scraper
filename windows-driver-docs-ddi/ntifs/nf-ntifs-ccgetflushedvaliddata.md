# CcGetFlushedValidData function

## Description

The **CcGetFlushedValidData** routine determines how much of a cached file has been flushed to disk.

## Parameters

### `SectionObjectPointer` [in]

Pointer to a structure containing the file object's section object pointers.

### `BcbListHeld` [in]

Reserved for system use. Must be **FALSE**.

## Return value

If the entire file has been flushed, **CcGetFlushedValidData** returns the valid data length for the file. If there are dirty pages that have not been flushed to disk, **CcGetFlushedValidData** returns the starting byte offset of the lowest dirty page currently in the file. If the file is not cached or is no longer cached, MAXLONGLONG is returned in the quad part.

## Remarks

The file system is responsible for ensuring that the value of *SectionObjectPointer* remains valid while in use. It is impossible for the cache manager to guarantee this.

## See also

[CcFlushCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccflushcache)

[CcPurgeCacheSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpurgecachesection)