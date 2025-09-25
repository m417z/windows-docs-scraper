# FsRtlRemovePerFileContext function

## Description

The **FsRtlRemovePerFileContext** routine returns a pointer to a [**FSRTL_PER_FILE_CONTEXT**](https://learn.microsoft.com/previous-versions/ff547352(v=vs.85)) object that is associated with a file. **FsRtlRemovePerFileContext** removes the **FSRTL_PER_FILE_CONTEXT** object from the list it occupies, along with the associated driver specific context information.

## Parameters

### `PerFileContextPointer` [in]

A pointer to an opaque pointer that is used by the file system runtime library (FSRTL) package to track file contexts. To obtain this pointer from a file object, use the [**FsRtlGetPerFileContextPointer**](https://learn.microsoft.com/previous-versions/ff546051(v=vs.85)) macro.

### `OwnerId` [in, optional]

A pointer to a filter driver-allocated variable that uniquely identifies the owner of the per-file context structure. This parameter is optional, but must be non-NULL if **InstanceId** is non-NULL.

### `InstanceId` [in, optional]

A pointer to a filter driver-allocated variable that can be used to distinguish among per-file context structures that are created by the same filter driver. This parameter is optional.

## Return value

A pointer to the first [**FSRTL_PER_FILE_CONTEXT**](https://learn.microsoft.com/previous-versions/ff547352(v=vs.85)) that matches the **OwnerId** and **InstanceId**, if specified. If no match is found or if the system does not support per file context information, this routine returns NULL.

## Remarks

**FsRtlRemovePerFileContext** removes only the first matching per-file context structure that it finds. If there are additional matching per-file contexts, the filter driver must call **FsRtlRemovePerFileContext** as many times as required to remove them all.

The file system filter driver must free the memory that is used for this context information after the [**FSRTL_PER_FILE_CONTEXT**](https://learn.microsoft.com/previous-versions/ff547352(v=vs.85)) has been removed.

Use this routine for your drivers to remove contexts only when the driver must discard per-file context information while the file is still open. Contexts are removed when a file is closed by using [**FsRtlTeardownPerFileContexts**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlteardownperfilecontexts).

Don't use this routine inside your **FreeCallback** routine. The file system removes contexts from the list before that routine is called.

Don't use this routine inside your IRP_CLOSE handler. You will not be notified when the stream is torn down.

## See also

[**FSRTL_PER_FILE_CONTEXT**](https://learn.microsoft.com/previous-versions/ff547352(v=vs.85))

[**FsRtlGetPerFileContextPointer**](https://learn.microsoft.com/previous-versions/ff546051(v=vs.85))

[**FsRtlInsertPerFileContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinsertperfilecontext)

[**FsRtlLookupPerFileContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtllookupperfilecontext)

[Tracking Per-File Context in a Legacy File System Filter Driver](https://learn.microsoft.com/windows-hardware/drivers/ifs/tracking-per-file-context-in-a-legacy-file-system-filter-driver)