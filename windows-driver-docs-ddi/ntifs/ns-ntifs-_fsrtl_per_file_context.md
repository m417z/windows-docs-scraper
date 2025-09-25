# _FSRTL_PER_FILE_CONTEXT structure

## Description

A legacy file system filter driver can use a **FSRTL_PER_FILE_CONTEXT** structure to associate driver-specific context information to an open file.

## Members

### `Links`

A link for this structure in the list of all per-file context structures that are associated with the same file. [FsRtlInsertPerFileContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinsertperfilecontext) inserts this member into the list of all per-file context structures for a file.

### `OwnerId`

A pointer to a filter-driver-allocated buffer that uniquely identifies the owner of the per-file context structure. The format of this variable is filter-driver-specific. Filter drivers must set this member to a non-**NULL** value.

### `InstanceId`

A pointer to a filter-driver-allocated buffer that can be used to distinguish among the per-file context structures that are created by the same filter driver. The format of this variable is filter-driver-specific. Filter drivers can set this member to **NULL**.

### `FreeCallback`

A pointer to a [callback routine](https://learn.microsoft.com/windows-hardware/drivers/ifs/pfree-function) that frees the per-file context structure. Filter drivers must set this member to a non-**NULL** value.

## Remarks

In order to associate context information with a file, a legacy filter driver first allocates a **FSRTL_PER_FILE_CONTEXT** structure and initializes it using [FsRtlInsertPerFileContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinsertperfilecontext). The driver then uses **FsRtlInsertPerFileContext** to associate that **FSRTL_PER_FILE_CONTEXT** object with the file. When the system tears down the file context object for a file, it calls [FsRtlTeardownPerFileContexts](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlteardownperfilecontexts) which calls the *FreeCallback* routine that is specified in the **FSRTL_PER_FILE_CONTEXT** object. That callback must free the driver-specific context object.

Filter writers should choose an **OwnerID** value that is both meaningful and convenient, such as the address of a driver object or device object.

Filter writers should choose an **InstanceID** value that is both meaningful and convenient, such as the address of the file context object for the file. Use the [FsRtlGetPerFileContextPointer](https://learn.microsoft.com/previous-versions/ff546051(v=vs.85)) macro to retrieve that address from a file object.

The **FSRTL_PER_FILE_CONTEXT** structure can be used as-is, or embedded in a driver-defined, per-file context structure.

The **FSRTL_PER_FILE_CONTEXT** structure can be allocated from paged or nonpaged pool.

The **FsRtlInitPerFileContext** macro initializes a **FSRTL_PER_FILE_CONTEXT** structure.

Parameters

*FileContext*

**FSRTL_PER_FILE_CONTEXT**

The FSRTL_PER_FILE_CONTEXT object to be initialized.

*OwnerId*

**PVOID**

A pointer to a filter driver-allocated variable that uniquely identifies the owner of the per-file context structure. The format is filter driver-specific. This parameter must have a non-**NULL** value.

*InstanceId*

**PVOID**

A pointer to a filter driver-allocated variable that uniquely identifies the owner of the per-file context structure. The format is filter driver-specific. This parameter must have a non-**NULL** value.

*FreeCallback*

**PFREE_FUNCTION**

A pointer to a [callback routine](https://learn.microsoft.com/windows-hardware/drivers/ifs/pfree-function) that frees the per-file context structure.

Return value

**VOID**

None.

This macro must be used before calling [FsRtlInsertPerFileContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinsertperfilecontext).

Filter writers should choose an *OwnerID* value that is both meaningful and convenient, such as the address of a driver object or device object.

Filter writers should use an *InstanceID* value that is both meaningful and convenient, such as the address of the file context object for the file. Use the **FsRtlGetPerFileContextPointer** macro to retrieve that address from a file object.

For more information about how to use and create context objects, see [Tracking Per-File Context in a Legacy File System Filter Driver](https://learn.microsoft.com/windows-hardware/drivers/ifs/tracking-per-file-context-in-a-legacy-file-system-filter-driver).

## See also

[FsRtlGetPerFileContextPointer](https://learn.microsoft.com/previous-versions/ff546051(v=vs.85))

[FsRtlInitPerFileContext](https://learn.microsoft.com/previous-versions/ff546161(v=vs.85))

[FsRtlInsertPerFileContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinsertperfilecontext)

[FsRtlTeardownPerFileContexts](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlteardownperfilecontexts)

[PFREE_FUNCTION](https://learn.microsoft.com/windows-hardware/drivers/ifs/pfree-function)

[Tracking Per-File Context in a Legacy File System Filter Driver](https://learn.microsoft.com/windows-hardware/drivers/ifs/tracking-per-file-context-in-a-legacy-file-system-filter-driver)