# FsRtlIsSystemPagingFile function

## Description

The **FsRtlIsSystemPagingFile** routine determines whether a given file is currently a system paging file.

## Parameters

### `FileObject` [in]

Pointer to a file object for the file.

## Return value

**FsRtlIsSystemPagingFile** returns TRUE if the file represented by **FileObject** is a system paging file, otherwise FALSE.

## See also

[**FsRtlIsPagingFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlispagingfile)

[**FsRtlPostPagingFileStackOverflow**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlpostpagingfilestackoverflow)

[**FsRtlSupportsPerStreamContexts**](https://learn.microsoft.com/previous-versions/ff547285(v=vs.85))