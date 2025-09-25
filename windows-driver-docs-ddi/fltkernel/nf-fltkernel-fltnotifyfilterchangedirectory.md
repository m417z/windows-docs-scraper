# FltNotifyFilterChangeDirectory function

## Description

The **FltNotifyFilterChangeDirectory** routine creates a notify structure for an IRP_MN_NOTIFY_CHANGE_DIRECTORY operation and adds it to the specified notify list.

## Parameters

### `NotifySync` [in, out]

Pointer to an opaque synchronization object for the change directory notify list that the *NotifyList* parameter points to.

### `NotifyList` [in, out]

Pointer to the head of the change directory notify list for the current volume. Each element in the list is an opaque notify structure.

### `FsContext` [in]

Pointer to a unique value assigned by the caller to identify the notify structure to be created. If a callback routine is supplied in the *TraverseCallback* parameter, *FsContext* is passed as the *NotifyContext* parameter to that routine.

### `FullDirectoryName` [in]

Pointer to an ANSI or Unicode string that contains the full name for the directory associated with this notify structure.

### `WatchTree` [in]

Set to **TRUE** if all subdirectories of the directory that is specified by the *FullDirectoryName* parameter should also be watched. Set to **FALSE** if only the directory itself is to be watched.

### `IgnoreBuffer` [in]

Set to **TRUE** to ignore any user buffers and force the directory to be reenumerated. This action speeds the operation.

### `CompletionFilter` [in]

Bitmask of flags that specify the types of changes to files or directories that should cause the callback data structures in the notify list to be completed. The possible flag values are described in the following table.

| Flag | Meaning |
| --- | --- |
| FILE_NOTIFY_CHANGE_FILE_NAME | A file has been added, deleted, or renamed in this directory. |
| FILE_NOTIFY_CHANGE_DIR_NAME | A subdirectory has been created, removed, or renamed. |
| FILE_NOTIFY_CHANGE_NAME | This directory's name has changed. |
| FILE_NOTIFY_CHANGE_ATTRIBUTES | The value of an attribute of this file, such as last access time, has changed. |
| FILE_NOTIFY_CHANGE_SIZE | This file's size has changed. |
| FILE_NOTIFY_CHANGE_LAST_WRITE | This file's last modification time has changed. |
| FILE_NOTIFY_CHANGE_LAST_ACCESS | This file's last access time has changed. |
| FILE_NOTIFY_CHANGE_CREATION | This file's creation time has changed. |
| FILE_NOTIFY_CHANGE_EA | This file's extended attributes have been modified. |
| FILE_NOTIFY_CHANGE_SECURITY | This file's security information has changed. |
| FILE_NOTIFY_CHANGE_STREAM_NAME | A file stream has been added, deleted, or renamed in this directory. |
| FILE_NOTIFY_CHANGE_STREAM_SIZE | This file stream's size has changed. |
| FILE_NOTIFY_CHANGE_STREAM_WRITE | This file stream's data has changed. |

### `NotifyCallbackData` [in]

Pointer to the callback data structure for the operation to be added to the notify list. This parameter is required and cannot be **NULL**.

### `TraverseCallback` [in, optional]

Optional pointer to a callback routine to be invoked when a change occurs in a subdirectory that is being watched in a directory tree. This pointer lets the file system check whether the watcher has traverse access to that directory. Such a caller-supplied routine is declared as follows:

```
NTSTATUS
(*PCHECK_FOR_TRAVERSE_ACCESS) (
    IN PVOID NotifyContext,                     // FsContext
    IN PVOID TargetContext,                     // Context pointer
    IN PSECURITY_SUBJECT_CONTEXT SubjectContext // SubjectContext
    );
```

For more information about the *TargetContext* parameter, see the *TargetContext* parameter of the [FsRtlNotifyFullReportChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlnotifyfullreportchange) routine.

### `SubjectContext` [in, optional]

Pointer to a context structure to be passed to *TraverseCallback*. **FltNotifyFilterChangeDirectory** releases the context and frees the structure after using it. If a *TraverseCallback* routine is supplied, *SubjectContext* is passed as the *SubjectContext* parameter to that routine.

### `FilterCallback` [in, optional]

Optional pointer to a callback routine to be invoked when a change occurs to the directory. If this callback routine returns **TRUE**, [FsRtlNotifyFilterReportChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlnotifyfilterreportchange) completes the pending IRP_MN_NOTIFY_CHANGE_DIRECTORY operations in the notify list; otherwise, it does not. Such a caller-supplied routine is declared as follows:

```
BOOLEAN
(*PFILTER_REPORT_CHANGE) (
    IN PVOID NotifyContext,                     // FsContext
    IN PVOID FilterContext                      // Context pointer
    );
```

## Return value

None

## Remarks

A minifilter driver can call **FltNotifyFilterChangeDirectory** from the preoperation callback routine ([PFLT_PRE_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)) that it registered to process notify change directory operations. These operations have a major function code of [IRP_MJ_DIRECTORY_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-directory-control) and a minor function code of IRP_MN_NOTIFY_CHANGE_DIRECTORY.

The minifilter driver calls **FltNotifyFilterChangeDirectory** to create a notify structure to hold the callback data structure for the operation and add the notify structure to the notify list for the current volume.

**FltNotifyFilterChangeDirectory** does the following:

* Checks whether the operation's file object has been cleaned up. If so, **FltNotifyFilterChangeDirectory** completes the operation with status STATUS_NOTIFY_CLEANUP and does not add it to the notify list.
* If the operation's file object has not been cleaned up, **FltNotifyFilterChangeDirectory** checks whether the notify list already contains a notify structure for the given *FsContext* value. If such a notify structure is found, and there are pending changes to report, **FltNotifyFilterChangeDirectory** completes the callback data structure pointed to by the *NotifyCallbackData* parameter. If a notify structure is found, but there are no pending changes to report, **FltNotifyFilterChangeDirectory** adds the operation to the notify structure. If no such notify structure is found, **FltNotifyFilterChangeDirectory** creates a notify structure for the operation and inserts it into the list.

When a change occurs to the directory, the file system calls [FsRtlNotifyFilterReportChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlnotifyfilterreportchange) to complete the pending IRP_MN_NOTIFY_CHANGE_DIRECTORY operations in the notify list.

## See also

[FsRtlNotifyFilterReportChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlnotifyfilterreportchange)

[IRP_MJ_DIRECTORY_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-directory-control)

[PFLT_PRE_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)