# FsRtlOplockBreakToNoneEx function

## Description

The **FsRtlOplockBreakToNoneEx** routine breaks all opportunistic locks (oplocks) immediately without regard for any oplock key.

## Parameters

### `Oplock` [in, out]

An opaque oplock pointer for the file. This pointer must have been initialized by a previous call to [FsRtlInitializeOplock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializeoplock).

### `Irp` [in]

A pointer to the IRP for the I/O operation.

### `Flags` [in]

A bitmask for the associated file I/O operation. A file system or filter driver sets bits to specify the behavior of **FsRtlOplockBreakToNoneEx**. The *Flags* parameter has the following options:

#### OPLOCK_FLAG_COMPLETE_IF_OPLOCKED (0x00000001)

Specifies to allow an oplock break to proceed without blocking or pending the operation that caused the oplock break. Typically, this flag is only used if the IRP that the *Irp* parameter points to declares an IRP_MJ_CREATE operation.

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

A context information pointer that was passed in the *Context* parameter to **FsRtlOplockBreakToNoneEx**.

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

A context information pointer that was passed in the *Context* parameter to **FsRtlOplockBreakToNoneEx**.

#### Irp

A pointer to the IRP for the I/O operation.

## Return value

**FsRtlOplockBreakToNoneEx** returns STATUS_SUCCESS or an appropriate NTSTATUS code such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_CANCELLED** | The IRP was canceled. STATUS_CANCELLED is an error code. |
| **STATUS_PENDING** | An oplock break is underway. Therefore, the IRP was pended. STATUS_PENDING is a success code. |
| **STATUS_OPLOCK_BREAK_IN_PROGRESS** | An opportunistic lock break (oplock) is underway. STATUS_OPLOCK_BREAK_IN_PROGRESS is a success code that **FsRtlOplockBreakToNoneEx** returns if the caller set OPLOCK_FLAG_COMPLETE_IF_OPLOCKED in the *Flags* parameter and an oplock must be broken. |

## Remarks

For more information about opportunistic locks, see the Microsoft Windows SDK documentation.

Minifilters should call [FltOplockBreakToNoneEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltoplockbreaktononeex) instead of **FsRtlOplockBreakToNoneEx**.

## See also

[FltOplockBreakToNoneEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltoplockbreaktononeex)

[FsRtlInitializeOplock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializeoplock)