# FsRtlNotifyFullChangeDirectory macro

## Description

The **FsRtlNotifyFullChangeDirectory** routine creates a notify structure for a notification request and adds it to the specified notify list.

## Parameters

### `A1`

A pointer to an opaque synchronization object for the notify list for the current volume.

### `A2`

A pointer to the head of a notify list. Each element in the list is an opaque notify structure.

### `A3`

A pointer to a unique value assigned by the file system to identify the notify structure to be created as belonging to a particular file object. If a *TraverseCallback* routine is supplied, *FsContext* is passed as the *NotifyContext* parameter to that routine.

### `A4`

A pointer to an ANSI or Unicode string that contains the full name for the directory associated with this notify structure. Ignored if *NotifyIrp* is **NULL**.

### `A5`

Set to **TRUE** if all subdirectories of this directory should also be watched. Set to **FALSE** if only the directory itself is to be watched. Ignored if *NotifyIrp* is **NULL**.

### `A6`

Set to **TRUE** to ignore any user buffers and force the directory to be reenumerated. This action speeds the operation. Ignored if *NotifyIrp* is **NULL**.

### `A7`

Bitmask of flags that specify the types of changes to files or subdirectories that should cause the queue of pending notify IRPs to be completed. The possible flag values are described following.

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

*CompletionFilter* is ignored if *NotifyIrp* is **NULL**.

### `A8`

A pointer to the IRP to complete on notify change. If *NotifyIrp* is **NULL**, this means that the file stream represented by this file object is being deleted.

### `A9`

Optional pointer to a callback routine to be invoked when a change occurs in a subdirectory being watched in a directory tree. This lets the file system check whether the watcher has traverse access to that directory. Such a caller-supplied routine is declared as follows:

|  |
| --- |
| ``` NTSTATUS (*PCHECK_FOR_TRAVERSE_ACCESS) (     IN PVOID NotifyContext,                     // FsContext     IN PVOID TargetContext,                     // Context pointer     IN PSECURITY_SUBJECT_CONTEXT SubjectContext // SubjectContext     ); ``` |

For more information about the *TargetContext* parameter, see the *TargetContext* parameter of [**FsRtlNotifyFullReportChange**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlnotifyfullreportchange). *TraverseCallback* is ignored if *NotifyIrp* is **NULL**.

### `A10`

A pointer to a context structure to be passed to *TraverseCallback*. **FsRtlNotifyFullChangeDirectory** releases the context and frees the structure after using it. Ignored if *NotifyIrp* is **NULL**. If a *TraverseCallback* routine is supplied, *SubjectContext* is passed as the *SubjectContext* parameter to that routine.

## Remarks

**FsRtlNotifyFullChangeDirectory** is called by a file system that has received a notify change request. This request is received as an IRP with major function code IRP_MJ_DIRECTORY_CONTROL, minor function code IRP_MN_NOTIFY_CHANGE_DIRECTORY.

If *NotifyIrp* is **NULL**, **FsRtlNotifyFullChangeDirectory** checks whether the notify list contains a pending IRP that refers to this file object and, if so, completes it with STATUS_DELETE_PENDING.

If *NotifyIrp* is not **NULL**, **FsRtlNotifyFullChangeDirectory** does the following:

* Checks whether the file object has undergone cleanup. If so, **FsRtlNotifyFullChangeDirectory** completes the notify IRP with status STATUS_NOTIFY_CLEANUP.
* If the file object has not undergone cleanup, **FsRtlNotifyFullChangeDirectory** checks whether the notify list for this volume already contains a notify structure for this change. If so, **FsRtlNotifyFullChangeDirectory** completes any pending IRPs. If not, **FsRtlNotifyFullChangeDirectory** marks the notify IRP as pending, creates a notify structure, and inserts it into the list.

## See also

[FsRtlNotifyFullReportChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlnotifyfullreportchange)

[IRP_MJ_DIRECTORY_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-directory-control)

[SECURITY_SUBJECT_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)