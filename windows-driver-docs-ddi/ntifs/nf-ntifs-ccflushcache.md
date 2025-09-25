# CcFlushCache function

## Description

The **CcFlushCache** routine flushes all or a portion of a cached file to disk.

## Parameters

### `SectionObjectPointer` [in]

Pointer to a **SECTION_OBJECT_POINTERS** structure containing the file object's section object pointers.

### `FileOffset` [in, optional]

Pointer to a variable that specifies the starting byte offset within the cached file where the data is to be flushed.

If *FileOffset* is **NULL**, the entire file is flushed from the cache.

If *FileOffset* is not **NULL**, only the byte range specified by *FileOffset* and *Length* is flushed.

### `Length` [in]

Length of the byte range to flush, starting at *FileOffset*. If *FileOffset* is **NULL**, *Length* is ignored.

### `IoStatus` [out, optional]

Pointer to a structure that receives the final completion status and information about the flush operation. If the data is flushed successfully, *IoStatus.Status* contains STATUS_SUCCESS. If not all of the data is flushed successfully, *IoStatus.Information* contains the actual number of bytes that were flushed. Otherwise, *IoStatus.Information* contains the value given in *Length*.

## Remarks

**CcFlushCache** has no *Wait* parameter. Thus the caller must be able to enter a wait state until all the data has been flushed.

To cache a file, use [CcInitializeCacheMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccinitializecachemap).

## See also

[CcCopyWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-cccopywrite)

[CcInitializeCacheMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccinitializecachemap)

[CcIsFileCached](https://learn.microsoft.com/previous-versions/ff539143(v=vs.85))

[CcPurgeCacheSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpurgecachesection)