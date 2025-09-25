# FltOplockBreakH function

## Description

The **FltOplockBreakH** routine breaks CACHE_HANDLE_LEVEL opportunistic locks (oplocks).

## Parameters

### `Oplock` [in]

An opaque oplock pointer for the file. This pointer must have been initialized by a previous call to [FltInitializeOplock](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitializeoplock).

### `CallbackData` [in]

A pointer to the callback data ([FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) structure for the I/O operation.

### `Flags` [in]

A bitmask for the associated file I/O operation. A minifilter driver sets bits to specify the behavior of **FltOplockBreakH**. The *Flags* parameter has the following options:

#### OPLOCK_FLAG_COMPLETE_IF_OPLOCKED (0x00000001)

Allows an oplock break to proceed without blocking or pending the operation that caused the oplock break.

#### OPLOCK_FLAG_IGNORE_OPLOCK_KEYS (0x00000008)

Allows CACHE_HANDLE_LEVEL oplock breaks to proceed regardless of the oplock key.

### `Context` [in, optional]

A pointer to caller-defined context information to be passed to the callback routines that the *WaitCompletionRoutine* and *PrePostCallbackDataRoutine* parameters point to.

### `WaitCompletionRoutine` [in, optional]

A pointer to a caller-supplied callback routine. If an oplock break is in progress, this routine is called when the break is completed. This parameter is optional and can be **NULL**. If it is **NULL**, the caller is put into a wait state until the oplock break is completed.

This routine is declared as follows:

```
typedef VOID
(*PFLTOPLOCK_WAIT_COMPLETE_ROUTINE) (
    __in PFLT_CALLBACK_DATA CallbackData,
 __in_opt PVOID Context
    );
```

This routine has the following parameters:

#### CallbackData

A pointer to the callback data structure for the I/O operation.

#### Context

A context information pointer that was passed in the *Context* parameter to **FltOplockBreakH**.

### `PrePostCallbackDataRoutine` [in, optional]

A pointer to a caller-supplied callback routine to be called if the I/O operation must be pended. The routine is called before the oplock package pends the IRP. This parameter is optional and can be **NULL**.

This routine is declared as follows:

```
typedef VOID
(*PFLTOPLOCK_PREPOST_CALLBACKDATA_ROUTINE) (
    __in PFLT_CALLBACK_DATA CallbackData,
 __in_opt PVOID Context
      );
```

This routine has the following parameters:

#### CallbackData

A pointer to the callback data structure for the I/O operation.

#### Context

A context information pointer that was passed in the *Context* parameter to **FltOplockBreakH**.

## Return value

**FltOplockBreakH** returns one of the following FLT_PREOP_CALLBACK_STATUS codes:

| Return code | Description |
| --- | --- |
| **FLT_PREOP_COMPLETE** | **FltOplockBreakH** encountered a pool allocation failure, or a call to the [FsRtlOplockBreakH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtloplockbreakh) function returned an error. **FltOplockBreakH** will set the error code in the **Status** member of the [IO_STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure. The IO_STATUS_BLOCK structure is specified in the **IoStatus** member of the [FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data) callback data structure. The *CallbackData* parameter points to this FLT_CALLBACK_DATA. |
| **FLT_PREOP_PENDING** | An oplock break was initiated, which caused the Filter Manager to post the I/O operation to a work queue. The I/O operation is represented by the callback data that the *CallbackData* parameter points to. |
| **FLT_PREOP_SUCCESS_WITH_CALLBACK** | The callback data that the *CallbackData* parameter points to was not pended, and the I/O operation was performed immediately. Be aware that if the caller specified OPLOCK_FLAG_COMPLETE_IF_OPLOCKED in the *Flags* parameter, an oplock break might actually be in progress even though the I/O operation was not pended. To determine whether this is the situation, the caller should check for STATUS_OPLOCK_BREAK_IN_PROGRESS in the **Status** member of the [IO_STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure. The IO_STATUS_BLOCK structure is specified in the **IoStatus** member of the [FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data) callback data structure. |

## Remarks

For more information about opportunistic locks, see the Microsoft Windows SDK documentation.

## See also

[FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[FltInitializeOplock](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitializeoplock)

[FsRtlOplockBreakH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtloplockbreakh)

[IO_STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block)