# CcSetDirtyPageThreshold function

## Description

The **CcSetDirtyPageThreshold** routine sets a per-file dirty page threshold on a cached file.

## Parameters

### `FileObject` [in]

Pointer to a file object for the cached file on which the dirty page threshold is to be set.

### `DirtyPageThreshold` [in]

Specifies, as a number of pages, the dirty page threshold value. To remove a per-file dirty page threshold value that was set previously, set *DirtyPageThreshold* to zero.

## Remarks

**CcSetDirtyPageThreshold** sets or removes a per-file dirty page threshold. After a per-file dirty page threshold is set on a cached file, if the file system attempts to exceed the threshold, the cache manager will refuse requests to write to the file.

To determine whether the cache manager will accept or refuse write requests, use [CcCanIWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-cccaniwrite).

Note that the *per-file* dirty page threshold is not the same as the *global* dirty page threshold for the entire system cache.

## See also

[CcCanIWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-cccaniwrite)

[CcDeferWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccdeferwrite)