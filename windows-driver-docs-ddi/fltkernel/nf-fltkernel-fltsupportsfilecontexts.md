# FltSupportsFileContexts function

## Description

The **FltSupportsFileContexts** routine determines whether the file system supports file contexts for a given file. (See also [FltSupportsFileContextsEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsupportsfilecontextsex).)

## Parameters

### `FileObject` [in]

Pointer to the file object that represents the file whose file context support is being queried. This parameter is required and cannot be **NULL**.

## Return value

**FltSupportsFileContexts** returns **TRUE** if the file system supports file contexts for the file object; **FALSE** otherwise.

## Remarks

Minifilter drivers call **FltSupportsFileContexts** to determine whether the underlying file system inherently supports file contexts for the file that is represented by the specified *FileObject* without having to allocate a context and attempt to set it. If a context type isn't supported on a file, then the minifilter cannot attach a context to that file.

Note that a file system might support file contexts for some types of files but not for others. For example, NTFS and FAT do not support file contexts for paging files.

For more information about contexts, see [About minifilter contexts](https://learn.microsoft.com/windows-hardware/drivers/ifs/managing-contexts-in-a-minifilter-driver).

## See also

[FltAllocateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext)

[FltDeleteContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletecontext)

[FltDeleteFileContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletefilecontext)

[FltGetFileContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilecontext)

[FltReleaseContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext)

[FltSetFileContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetfilecontext)

[FltSupportsFileContextsEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsupportsfilecontextsex)