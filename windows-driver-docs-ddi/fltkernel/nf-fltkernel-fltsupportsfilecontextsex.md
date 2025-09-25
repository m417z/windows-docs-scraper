# FltSupportsFileContextsEx function

## Description

The **FltSupportsFileContextsEx** routine determines whether the file system or the filter manager support file contexts for a given file.

## Parameters

### `FileObject` [in]

Pointer to the file object that represents the file whose file context support is being queried. This parameter is required and cannot be **NULL**.

### `Instance` [in, optional]

Opaque instance pointer for the caller. This parameter is optional and can be **NULL**. For more information about this parameter, see the Remarks section of this page.

## Return value

**FltSupportsFileContextsEx** returns **TRUE** if the file system or filter manager supports file contexts for the file; **FALSE** otherwise.

## Remarks

Minifilter drivers can call the **FltSupportsFileContextsEx** routine to determine whether the underlying file system or the filter manager supports file contexts for the file represented by *FileObject* without having to allocate a context and attempt to set it. If a context type isn't supported on a file, then the minifilter cannot attach a context to that file.

For file systems (such as FAT) that support only a single data stream per file, file contexts are equivalent to stream contexts. Such file systems usually support stream contexts but do not support file contexts. Instead, the filter manager provides file context support, using the file system's existing support for stream contexts. For minifilter instances attached to these file systems, [FltSupportsFileContexts](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsupportsfilecontexts) returns **FALSE**, while **FltSupportsFileContextsEx** returns **TRUE** (when a valid non-**NULL** value is passed for the *Instance* parameter).

If a non-**NULL** value is supplied for the *Instance* parameter, **FltSupportsFileContextsEx** returns **TRUE** if the file system or the filter manager supports file contexts for the file; **FALSE** otherwise.

If the *Instance* parameter is **NULL**, **FltSupportsFileContextsEx** returns **TRUE** only if the file system supports file contexts for the file. Otherwise, it returns **FALSE**, even if the filter manager supports file contexts for the file.

Note that a file system might support file contexts for some types of files but not for others. For example, NTFS and FAT do not support file contexts for paging files.

For more information about contexts, see [About minifilter contexts](https://learn.microsoft.com/windows-hardware/drivers/ifs/managing-contexts-in-a-minifilter-driver).

## See also

[FltAllocateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext)

[FltDeleteContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletecontext)

[FltDeleteFileContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletefilecontext)

[FltGetFileContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilecontext)

[FltReleaseContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext)

[FltSetFileContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetfilecontext)

[FltSupportsFileContexts](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsupportsfilecontexts)