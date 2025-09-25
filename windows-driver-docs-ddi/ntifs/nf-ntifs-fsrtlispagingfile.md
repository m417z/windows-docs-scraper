# FsRtlIsPagingFile function

## Description

The **FsRtlIsPagingFile** routine determines whether a given file is a paging file.

## Parameters

### `FileObject` [in]

Pointer to a file object for the file.

## Return value

**FsRtlIsPagingFile** returns **TRUE** if the file represented by *FileObject* is a paging file, otherwise **FALSE**.

## Remarks

File system filter drivers call **FsRtlIsPagingFile** to determine whether a given file object represents a paging file.

**Note** If **FsRtlIsPagingFile** is called in the create completion ("post-create") path, it returns **FALSE**, even if the file is a paging file. However, it works properly on Windows Vista and later.

## See also

[FsRtlPostPagingFileStackOverflow](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlpostpagingfilestackoverflow)

[FsRtlSupportsPerStreamContexts](https://learn.microsoft.com/previous-versions/ff547285(v=vs.85))