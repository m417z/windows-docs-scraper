# FsRtlCheckOplockEx function

## Description

The **FsRtlCheckOplockEx** routine synchronizes the IRP for a file I/O operation with the current opportunistic lock (oplock) state of the file.

## Parameters

### `Oplock` [in]

An opaque opportunistic lock pointer for the file. This pointer must have been initialized by a previous call to [**FsRtlInitializeOplock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializeoplock).

### `Irp` [in]

A pointer to the IRP for the I/O operation.

### `Flags` [in]

A bitmask for the associated file I/O operation. A file system or filter driver sets bits to specify the behavior of **FsRtlCheckOplockEx**. The **Flags** parameter has the following options:

| Value | Meaning |
| ----- | ------- |
| OPLOCK_FLAG_COMPLETE_IF_OPLOCKED (0x00000001) | Specifies to allow an opportunistic lock break to proceed without blocking or pending the operation that caused the oplock break. |
| OPLOCK_FLAG_OPLOCK_KEY_CHECK_ONLY (0x00000002) | Supported starting with Windows 7. Specifies that **FsRtlCheckOplockEx** should only check for an opportunistic lock key on the FILE_OBJECT that is associated with the IRP that the **Irp** parameter points to. **FsRtlCheckOplockEx** must then add the key if one is provided in the IRP. No other oplock processing occurs; that is, no opportunistic lock break will occur. |
| OPLOCK_FLAG_BACK_OUT_ATOMIC_OPLOCK (0x00000004) | Supported starting with Windows 7. Specifies that **FsRtlCheckOplockEx** should revert any state that was previously set up through a call to the [**FsRtlOplockFsctrl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtloplockfsctrl) routine. **FsRtlOplockFsctrl** is called during processing of an IRP_MJ_CREATE request that specifies the FILE_OPEN_REQUIRING_OPLOCK flag in the create options parameter. The OPLOCK_FLAG_BACK_OUT_ATOMIC_OPLOCK flag is typically used in final processing of such a create request when it previously failed. |
| OPLOCK_FLAG_IGNORE_OPLOCK_KEYS (0x00000008) | Supported starting with Windows 7. Specifies to allow all opportunistic lock breaks to proceed regardless of the opportunistic lock key. |
| OPLOCK_FLAG_PARENT_OBJECT (0x00000010) | Supported starting with Windows 8. Specifies that **Oplock** is associated with the parent (directory) of the file or directory to which the IRP in the **Irp** parameter is directed. |
| OPLOCK_FLAG_CLOSING_DELETE_ON_CLOSE (0x00000020) | Supported starting with Windows 8. Specifies that the I/O operation specified in **Irp** is an IRP_MJ_CLEANUP for a handle that was originally opened with the FILE_DELETE_ON_CLOSE flag set in its create options. This flag as no effect if **Irp** is not an IRP_MJ_CLEANUP operation. Specifying this flag may result in an opportunistic lock break. |
| OPLOCK_FLAG_REMOVING_FILE_OR_LINK (0x00000040) | Supported starting with Windows 8. Specifies handling an opportunistic lock break on a parent directory when deleting a file or link in that directory. If specified, this flag must be combined with OPLOCK_FLAG_PARENT_OBJECT. This flag must be specified when the file system is processing an operation that results in the removal of a link or file. |

### `Context` [in, optional]

A pointer to caller-defined context information to be passed to the callback routines that the **CompletionRoutine** and **PostIrpRoutine** parameters point to.

### `CompletionRoutine` [in, optional]

A pointer to a caller-supplied callback routine. If an opportunistic lock break is in progress, this routine is called when the break is completed. This parameter is optional and can be NULL. If it is NULL, the caller is put into a wait state until the opportunistic lock break is completed.

This routine is declared as follows:

``` cpp
typedef VOID
(*POPLOCK_WAIT_COMPLETE_ROUTINE) (
      IN PVOID Context,
      IN PIRP Irp
      );
```

This routine has the following parameters:

| Parameter | Description |
| --------- | ----------- |
| Context | A context information pointer that was passed in the **Context** parameter to **FsRtlCheckOplockEx**. |
| Irp | A pointer to the IRP for the I/O operation. |

### `PostIrpRoutine` [in, optional]

A pointer to a caller-supplied callback routine to be called if the I/O operation is posted to a work queue. This parameter is optional and can be NULL.

This routine is declared as follows:

``` cpp
typedef VOID
(*POPLOCK_FS_PREPOST_IRP) (
      IN PVOID Context,
      IN PIRP Irp
      );
```

This routine has the following parameters:

| Parameter | Description |
| --------- | ----------- |
| Context | A context information pointer that was passed in the **Context** parameter to **FsRtlCheckOplockEx**. |
| Irp | A pointer to the IRP for the I/O operation. |

## Return value

**FsRtlCheckOplockEx** returns STATUS_SUCCESS or an appropriate NTSTATUS code such as one of the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_CANCELLED | The IRP was canceled. STATUS_CANCELLED is an error code. |
| STATUS_CANNOT_BREAK_OPLOCK | The opportunistic lock (oplock) break cannot be accomplished. The IRP is an IRP_MJ_CREATE request. FILE_OPEN_REQUIRING_OPLOCK was specified in the create options parameter for the operation, and there is a granted oplock. |
| STATUS_OPLOCK_BREAK_IN_PROGRESS | An opportunistic lock break is underway. The IRP is an IRP_MJ_CREATE request, and FILE_COMPLETE_IF_OPLOCKED was specified in the create options parameter for the operation. STATUS_OPLOCK_BREAK_IN_PROGRESS is a success code that is returned if OPLOCK_FLAG_COMPLETE_IF_OPLOCKED was set, and an opportunistic lock has been broken. |
| STATUS_PENDING | An opportunistic lock break has been initiated, and control of the IRP has been passed to the oplock package. If CompletionRoutine is NULL, this routine will block while the oplock break is processed, rather than return STATUS_PENDING. STATUS_PENDING is a success code. |

## Remarks

**FsRtlCheckOplockEx** synchronizes the IRP for an I/O operation with the current opportunistic lock state of a file according to the following conditions:

* If the I/O operation will cause the opportunistic lock to break, the opportunistic lock break is initiated.

* If the I/O operation cannot continue until the opportunistic lock break is complete and a completion routine in **CompletionRoutine** was specified, **FsRtlCheckOplockEx** returns STATUS_PENDING and calls the callback routine specified in **PostIrpRoutine**. When the opportunistic lock break has been acknowledged, the callback routine in **CompletionRoutine** is called.

* If the I/O operation cannot continue until the opportunistic lock break is complete and **CompletionRoutine** was not specified, **FsRtlCheckOplockEx** will not return until the opportunistic lock break is acknowledged.

A **PostIrpRoutine** should be specified only if a **CompletionRoutine** has been specified.

If a file system or filter driver uses opportunistic locks, it must call **FsRtlCheckOplockEx** from any dispatch routines for I/O operations that can cause opportunistic lock breaks. This rule applies to the following types of I/O operations, because these operations can cause opportunistic lock breaks:

* IRP_MJ_CLEANUP
* IRP_MJ_CREATE
* IRP_MJ_FILE_SYSTEM_CONTROL
* IRP_MJ_FLUSH_BUFFERS
* IRP_MJ_LOCK_CONTROL
* IRP_MJ_READ
* IRP_MJ_SET_INFORMATION
* IRP_MJ_WRITE

For more information about opportunistic locks, see the Microsoft Windows SDK documentation.

Minifilters should call [**FltCheckOplockEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcheckoplockex) instead of **FsRtlCheckOplockEx**.

## See also

[**FSCTL_OPBATCH_ACK_CLOSE_PENDING**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-opbatch-ack-close-pending)

[**FSCTL_OPLOCK_BREAK_ACKNOWLEDGE**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-oplock-break-acknowledge)

[**FSCTL_OPLOCK_BREAK_ACK_NO_2**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-oplock-break-ack-no-2)

[**FSCTL_OPLOCK_BREAK_NOTIFY**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-oplock-break-notify)

[**FSCTL_REQUEST_BATCH_OPLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-batch-oplock)

[**FSCTL_REQUEST_FILTER_OPLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-filter-oplock)

[**FSCTL_REQUEST_OPLOCK_LEVEL_1**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-oplock-level-1)

[**FSCTL_REQUEST_OPLOCK_LEVEL_2**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-oplock-level-2)

[**FltCheckOplockEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcheckoplockex)

[**FsRtlCurrentBatchOplock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlcurrentbatchoplock)

[**FsRtlInitializeOplock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializeoplock)

[**FsRtlOplockFsctrl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtloplockfsctrl)

[**FsRtlOplockIsFastIoPossible**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtloplockisfastiopossible)

[**FsRtlUninitializeOplock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtluninitializeoplock)