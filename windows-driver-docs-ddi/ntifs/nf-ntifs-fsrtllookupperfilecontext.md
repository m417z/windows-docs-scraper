# FsRtlLookupPerFileContext function

## Description

The **FsRtlLookupPerFileContext** routine returns a pointer to a [FSRTL_PER_FILE_CONTEXT](https://learn.microsoft.com/previous-versions/ff547352(v=vs.85)) object that is associated with a specified file.

## Parameters

### `PerFileContextPointer` [in]

A pointer to an opaque pointer that is used by the file system runtime library (FSRTL) package to track file contexts. To retrieve this pointer from a file object, use the [FsRtlGetPerFileContextPointer](https://learn.microsoft.com/previous-versions/ff546051(v=vs.85)) macro.

### `OwnerId` [in, optional]

A pointer to a filter driver-allocated variable that uniquely identifies the owner of the per-file context structure. The format of this variable is filter driver-specific. This parameter is optional, but must be non-**NULL** if *InstanceId* is non-**NULL**.

### `InstanceId` [in, optional]

A pointer to a filter driver-allocated variable that can be used to distinguish among per-file context structures that are created by the same filter driver. The format of this variable is filter driver-specific. This parameter is optional.

## Return value

A pointer to the first FSRTL_PER_FILE_CONTEXT structure that matches the *OwnerId* and *InstanceId*, if specified, or **NULL** if no match is found or the file system does not support per-file contexts.

## Remarks

By not specifying *OwnerID* and *InstanceId*, a filter driver can search for the first context that is associated with a file.

If the file system does not support per-file context objects, **NULL** is returned. Use the [FsRtlSupportsPerFileContexts](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlsupportsperfilecontexts) macro to determine whether a file system supports per-file context objects.

## See also

[FSRTL_PER_FILE_CONTEXT](https://learn.microsoft.com/previous-versions/ff547352(v=vs.85))

[FsRtlGetPerFileContextPointer](https://learn.microsoft.com/previous-versions/ff546051(v=vs.85))

[FsRtlInsertPerFileContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinsertperfilecontext)

[FsRtlRemovePerFileContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlremoveperfilecontext)

[Tracking Per-File Context in a Legacy File System Filter Driver](https://learn.microsoft.com/windows-hardware/drivers/ifs/tracking-per-file-context-in-a-legacy-file-system-filter-driver)