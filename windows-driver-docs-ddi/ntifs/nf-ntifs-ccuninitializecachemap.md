# CcUninitializeCacheMap function

## Description

The **CcUninitializeCacheMap** routine stops the caching of a cached file.

## Parameters

### `FileObject` [in]

Pointer to a file object for the cached file.

### `TruncateSize` [in, optional]

If specified, the file was truncated to the specified size, and the cache should be purged accordingly.

### `UninitializeEvent`

If specified, the provided event is set to the signaled state when the cached file data has been flushed to disk.

## Return value

**CcUninitializeCacheMap** returns **TRUE** if caching was stopped successfully, **FALSE** otherwise.

## Remarks

All file systems that support file caching must call **CcUninitializeCacheMap** when closing a file, whether the file is cached or not. Even if the file was created with caching disabled, the file system still must call **CcUninitializeCacheMap**.

To cache a file, use [CcInitializeCacheMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccinitializecachemap).

## See also

[CcInitializeCacheMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccinitializecachemap)

[CcPurgeCacheSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpurgecachesection)