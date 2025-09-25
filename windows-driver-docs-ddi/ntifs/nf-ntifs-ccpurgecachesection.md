# CcPurgeCacheSection function

## Description

The **CcPurgeCacheSection** routine purges all or a portion of a cached file from the system cache.

## Parameters

### `SectionObjectPointer` [in]

Pointer to a structure containing the file object's section object pointers.

### `FileOffset` [in, optional]

Pointer to a variable that specifies the starting byte offset within the cached file where the data is to be purged.

If *FileOffset* is **NULL**, the entire file is purged from the cache.

If *FileOffset* is not **NULL**, only the byte range specified by *FileOffset* and *Length* is purged.

### `Length` [in]

Length of the byte range to purge, starting at *FileOffset*. If *Length* is zero, the range from *FileOffset* to the end of the file is purged. If *FileOffset* is **NULL**, *Length* is ignored.

### `Flags`

Set to **TRUE** to uninitialize any private cache maps for the file before purging the file data.

## Return value

**CcPurgeCacheSection** returns **TRUE** if the cached file data was successfully purged, **FALSE** otherwise.

## Remarks

File systems call **CcPurgeCacheSection** to purge stale data from the cache. For example, when a file is truncated but not deleted, **CcPurgeCacheSection** should be called to purge any cached data that is no longer part of the file.

**CcPurgeCacheSection** will not purge mapped files.

Before calling **CcPurgeCacheSection**, the caller must acquire the file exclusively and ensure that no thread, including the caller, has mapped or pinned any byte range in the file.

## See also

[CcFlushCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccflushcache)

[CcInitializeCacheMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccinitializecachemap)

[CcIsFileCached](https://learn.microsoft.com/previous-versions/ff539143(v=vs.85))

[CcUninitializeCacheMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccuninitializecachemap)

[MmFlushImageSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-mmflushimagesection)