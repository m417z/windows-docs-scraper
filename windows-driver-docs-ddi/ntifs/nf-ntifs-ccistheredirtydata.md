# CcIsThereDirtyData function

## Description

The **CcIsThereDirtyData** routine determines whether a mounted volume contains any files that have dirty data in the system cache.

## Parameters

### `Vpb` [in]

Pointer to a volume parameter block (VPB) for the volume.

## Return value

**CcIsThereDirtyData** returns **TRUE** if the volume contains one or more cached files whose data has been modified in the cache but not yet flushed to disk, **FALSE** otherwise.

## Remarks

**CcIsThereDirtyData** ignores temporary files.

## See also

[CcFlushCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccflushcache)

[CcPurgeCacheSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpurgecachesection)