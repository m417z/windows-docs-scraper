# MmCanFileBeTruncated function

## Description

The **MmCanFileBeTruncated** routine checks whether a file can be truncated.

## Parameters

### `SectionPointer` [in]

Pointer to a structure that contains the file object's section object pointers.

### `NewFileSize` [in, optional]

Pointer to a variable that specifies the size in bytes to which the file is to be truncated. If this parameter is NULL, then a length of zero is assumed and **MmCanFileBeTruncated** checks whether the entire file can be truncated.

## Return value

**MmCanFileBeTruncated** returns TRUE if the file can be truncated; FALSE otherwise.

## Remarks

**MmCanFileBeTruncated** must always be called before a file is truncated.

A file cannot be truncated (and **MmCanFileBeTruncated** will return FALSE) if any of the following are true:

* An image section exists for the file.

* There are one or more outstanding write probes on the file's data section.

* There is a mapped view of file's data section within the truncation range determined by **NewFileSize**.

* One or more users hold references to the data section for the file, and **NewFileSize** <= the current file size.

## See also

[**CcCoherencyFlushAndPurge**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-cccoherencyflushandpurgecache)

[**CcPurgeCacheSection**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpurgecachesection)

[**CcSetFileSizesEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccsetfilesizesex)

[**MmFlushImageSection**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-mmflushimagesection)