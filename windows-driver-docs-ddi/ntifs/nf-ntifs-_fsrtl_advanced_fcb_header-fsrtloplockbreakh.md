# FsRtlOplockBreakH function

## Description

The **FsRtlOplockBreakH** routine breaks CACHE_HANDLE_LEVEL opportunistic locks (oplocks).

## Parameters

### `Oplock` [in]

An opaque opportunistic lock pointer for the file. This pointer must have been initialized by a previous call to [FsRtlInitializeOplock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializeoplock).

### `Irp` [in]

A pointer to the IRP for the I/O operation.

### `Flags` [in]

A bitmask for the associated file I/O operation. A file system or filter driver sets bits to specify the behavior of **FsRtlOplockBreakH**. The *Flags* parameter has the following options:

#### OPLOCK_FLAG_COMPLETE_IF_OPLOCKED (0x00000001)

Specifies to allow an oplock break to proceed without blocking or pending the operation that caused the oplock break.

#### OPLOCK_FLAG_IGNORE_OPLOCK_KEYS (0x00000008)

Supported in Windows 7 and later versions.

Specifies to allow CACHE_HANDLE_LEVEL oplock breaks to proceed regardless of the oplock key.

### `Context` [in, optional]

A pointer to caller-defined context information to be passed to the callback routines that the *CompletionRoutine* and *PostIrpRoutine* parameters point to.

### `CompletionRoutine` [in, optional]

A pointer to a caller-supplied callback routine. If an oplock break is in progress, this routine is called when the break is completed. This parameter is optional and can be **NULL**. If it is **NULL**, the caller is put into a wait state until the oplock break is completed.

This routine is declared as follows:

```
typedef VOID
(*POPLOCK_WAIT_COMPLETE_ROUTINE) (
      IN PVOID Context,
      IN PIRP Irp
      );
```

This routine has the following parameters:

#### Context

A context information pointer that was passed in the *Context* parameter to **FsRtlOplockBreakH**.

#### Irp

A pointer to the IRP for the I/O operation.

### `PostIrpRoutine` [in, optional]

A pointer to a caller-supplied callback routine to be called if the I/O operation is to be pended. The routine is called before the oplock package pends the IRP. This parameter is optional and can be **NULL**.

This routine is declared as follows:

```
typedef VOID
(*POPLOCK_FS_PREPOST_IRP) (
      IN PVOID Context,
      IN PIRP Irp
      );
```

#### Context

A context information pointer that was passed in the *Context* parameter to **FsRtlOplockBreakH**.

#### Irp

A pointer to the IRP for the I/O operation.

## Return value

**FsRtlOplockBreakH** returns STATUS_SUCCESS or an appropriate NTSTATUS code, such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_CANCELLED** | The IRP was canceled. STATUS_CANCELLED is an error code. |
| **STATUS_PENDING** | The IRP was posted to a work queue. STATUS_PENDING is a success code. |
| **STATUS_CANNOT_BREAK_OPLOCK** | The opportunistic lock (oplock) break cannot be accomplished. The IRP is an IRP_MJ_CREATE request. FILE_OPEN_REQUIRING_OPLOCK was specified in the create options parameter for the operation, and there is a granted oplock. STATUS_CANNOT_BREAK_OPLOCK is an error code. |

## Remarks

When an operation must break CACHE_HANDLE_LEVEL oplocks, the operation calls **FsRtlOplockBreakH**.

If the caller specifies the OPLOCK_FLAG_IGNORE_OPLOCK_KEYS flag in the *Flags* parameter, **FsRtlOplockBreakH** breaks all CACHE_HANDLE_LEVEL oplocks, regardless of the oplock key. The default behavior of **FsRtlOplockBreakH** is to break oplocks whose keys do not match the key on the caller's file object.

Minifilters should call [FltOplockBreakH](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltoplockbreakh) instead of **FsRtlOplockBreakH**.

## See also

[FltOplockBreakH](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltoplockbreakh)

[FsRtlInitializeOplock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializeoplock)