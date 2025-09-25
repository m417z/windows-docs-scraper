# CcIsThereDirtyDataEx function

## Description

The **CcIsThereDirtyDataEx** routine determines whether a volume contains any files that have dirty data in the system cache.

## Parameters

### `Vpb` [in]

A pointer to a volume parameter block (VPB) for the volume.

### `NumberOfDirtyPages` [in, optional]

An optional pointer to an unsigned long buffer that receives the number of dirty pages on the volume (associated with the Vpb parameter).

## Return value

The **CcIsThereDirtyDataEx** routine returns **TRUE** if the volume contains one or more cached files whose data has been modified in the cache, but not yet flushed to disk. Otherwise, this routine returns **FALSE**.

## Remarks

This routine will return **TRUE** if any dirty pages exist including temporary files ([CcIsThereDirtyData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccistheredirtydata) ignores temporary files). It will also return **TRUE** if there is any data currently queued to the volume.

## See also

[CcFlushCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccflushcache)

[CcIsThereDirtyData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccistheredirtydata)

[CcPurgeCacheSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpurgecachesection)