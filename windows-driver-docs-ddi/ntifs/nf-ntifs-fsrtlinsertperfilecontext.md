# FsRtlInsertPerFileContext function

## Description

The **FsRtlInsertPerFileContext** routine associates a [FSRTL_PER_FILE_CONTEXT](https://learn.microsoft.com/previous-versions/ff547352(v=vs.85)) object with a driver-specified context object for a file.

## Parameters

### `PerFileContextPointer` [in]

A pointer to an opaque pointer used by the file system runtime library (FSRTL) package to track file contexts. To retrieve this pointer from a file object, use the [FsRtlGetPerFileContextPointer](https://learn.microsoft.com/previous-versions/ff546051(v=vs.85)) macro.

### `Ptr` [in]

A pointer to the driver-specific context structure.

## Return value

The **FsRtlInsertPerFileContext** routine returns STATUS_SUCCESS, or an appropriate error code, such as:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | The underlying file system does not support filter file contexts. You can use the [FsRtlSupportsPerFileContexts](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlsupportsperfilecontexts) macro to check whether a file system supports per file context objects. |
| **STATUS_INSUFFICIENT_RESOURCES** | The system could not allocate resources (typically memory). |

## Remarks

The FsRtlGetPerFileContextPointer macro returns a *FileContextSupportPointer* for an open file.

Parameters

*FileObject*

**FILE_OBJECT**

A pointer to a file object.

Return value

**PVOID**

The FsRtlGetPerFileContextPointer macro returns an opaque pointer used by the file system runtime library (FSRTL) package to track file contexts. The macro returns **NULL** if the file system does not support the use of per-file context objects with files.

The FsRtlGetPerFileContextPointer macro returns the pointer to be passed to routines such as **FsRtlInsertPerFileContext**, [FsRtlLookupPerFileContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtllookupperfilecontext), and [FsRtlRemovePerFileContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlremoveperfilecontext).

For more information about how to use and create context objects, see [Tracking Per-File Context in a Legacy File System Filter Driver](https://learn.microsoft.com/windows-hardware/drivers/ifs/tracking-per-file-context-in-a-legacy-file-system-filter-driver).

## See also

[FSRTL_PER_FILE_CONTEXT](https://learn.microsoft.com/previous-versions/ff547352(v=vs.85))

[FsRtlLookupPerFileContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtllookupperfilecontext)

[FsRtlRemovePerFileContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlremoveperfilecontext)

[Tracking Per-File Context in a Legacy File System Filter Driver](https://learn.microsoft.com/windows-hardware/drivers/ifs/tracking-per-file-context-in-a-legacy-file-system-filter-driver)