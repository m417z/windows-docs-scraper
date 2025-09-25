# FsRtlTeardownPerFileContexts function

## Description

File systems call the**FsRtlTeardownPerFileContexts** routine to free [FSRTL_PER_FILE_CONTEXT](https://learn.microsoft.com/previous-versions/ff547352(v=vs.85)) objects that are associated with a [file control block (FCB)](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-fcb-structure) structure.

## Parameters

### `PerFileContextPointer` [in]

A pointer to an opaque pointer that identifies the per file context structure. To retrieve this pointer from a file object, use the [FsRtlGetPerFileContextPointer](https://learn.microsoft.com/previous-versions/ff546051(v=vs.85)) macro.

## Remarks

This routine calls the *FreeCallback* routine specified in the [FSRTL_PER_FILE_CONTEXT](https://learn.microsoft.com/previous-versions/ff547352(v=vs.85)) object. The *FreeCallback* routine has to deallocate the **FSRTL_PER_FILE_CONTEXT** structure and the associated context.

To avoid conflicts in synchronization, the **FsRtlTeardownPerFileContexts** routine releases the lock for the per file context objects before calling *FreeCallback*. This avoids blocking access to the to the per file context objects by the filter for its own list operations, such as removal with [FsRtlRemovePerFileContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlremoveperfilecontext).

## See also

[FSRTL_PER_FILE_CONTEXT](https://learn.microsoft.com/previous-versions/ff547352(v=vs.85))

[PFREE_FUNCTION](https://learn.microsoft.com/windows-hardware/drivers/ifs/pfree-function)

[Tracking Per-File Context in a Legacy File System Filter Driver](https://learn.microsoft.com/windows-hardware/drivers/ifs/tracking-per-file-context-in-a-legacy-file-system-filter-driver)