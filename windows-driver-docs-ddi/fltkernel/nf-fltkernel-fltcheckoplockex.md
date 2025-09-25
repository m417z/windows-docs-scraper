# FltCheckOplockEx function

## Description

A minifilter driver calls the **FltCheckOplockEx** routine to synchronize the callback data structure for an IRP-based I/O operation that has the current opportunistic lock (oplock) state of the file.

## Parameters

### `Oplock` [in]

An opaque oplock pointer for the file. This pointer must have been initialized by a previous call to [**FltInitializeOplock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitializeoplock).

### `CallbackData` [in]

A pointer to the callback data [**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data) structure for the I/O operation.

### `Flags` [in]

A bitmask for the associated file I/O operation. A minifilter driver sets bits to specify the behavior of **FltCheckOplockEx**. *Flags* can be one or more of the following values.

| Flag | Description |
| ---- | ----------- |
| OPLOCK_FLAG_COMPLETE_IF_OPLOCKED (0x00000001) | Allows an opportunistic lock break to proceed without blocking or pending the operation that caused the oplock break. |
| OPLOCK_FLAG_OPLOCK_KEY_CHECK_ONLY (0x00000002) | Specifies that **FltCheckOplockEx** should only check for an opportunistic lock key on the FILE_OBJECT that is associated with the I/O operation. This I/O operations is represented by the callback data that the *CallbackData* parameter points to. **FltCheckOplockEx** must then add the key if one is provided in the I/O operation. No other oplock processing occurs; that is, no opportunistic lock break will occur. |
| OPLOCK_FLAG_BACK_OUT_ATOMIC_OPLOCK (0x00000004) | Specifies that [**FsRtlCheckOplockEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlcheckoplockex) should revert any state that was previously set up through a call to the [**FltOplockFsctrl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltoplockfsctrl) routine. **FltOplockFsctrl** is called when an IRP_MJ_CREATE request is processed. This IRP_MJ_CREATE request specifies the FILE_OPEN_REQUIRING_OPLOCK flag in the create options parameter. The OPLOCK_FLAG_BACK_OUT_ATOMIC_OPLOCK flag is typically used in final processing of such a create request when it previously failed. |
| OPLOCK_FLAG_IGNORE_OPLOCK_KEYS (0x00000008) | Allows all opportunistic lock breaks to proceed regardless of the opportunistic lock key. |

### `Context` [in, optional]

A pointer to caller-defined context information to be passed to the callback routines that *WaitCompletionRoutine* and *PrePostCallbackDataRoutine* point to. The Filter Manager treats this information as opaque.

### `WaitCompletionRoutine` [in, optional]

A pointer to a caller-supplied callback routine. If an oplock break is in progress, the Filter Manager calls this routine when the oplock break is completed. This parameter is optional and can be NULL. If it is NULL, the caller is put into a wait state until the oplock break is completed.

This routine is declared as follows:

```C
typedef VOID
(*PFLTOPLOCK_WAIT_COMPLETE_ROUTINE) (
      IN PFLT_CALLBACK_DATA CallbackData,
      IN PVOID Context
      );
```

This routine has the following parameters:

* **CallbackData** is a pointer to the callback data structure for the I/O operation. When your *WaitCompleteRoutine* is called, the IoStatus sub-structure might be filled in with a failure status (for instance STATUS_CANCELLED). You should inspect this status and react appropriately.

* **Context** is a context information pointer that was passed in the **Context** parameter to **FltCheckOplockEx**.

### `PrePostCallbackDataRoutine` [in, optional]

A pointer to a caller-supplied callback routine to be called if the I/O operation is posted to a work queue. This parameter is optional and can be NULL.

This routine is declared as follows:

```C
typedef VOID
(*PFLTOPLOCK_PREPOST_CALLBACKDATA_ROUTINE) (
      IN PFLT_CALLBACK_DATA CallbackData,
      IN PVOID Context
      );
```

* **CallbackData** is a pointer to the callback data structure for the I/O operation.

* **Context** is a context information pointer that was passed in the *Context* parameter to **FltCheckOplockEx**.

## Return value

**FltCheckOplockEx** returns one of the following FLT_PREOP_CALLBACK_STATUS codes:

| Return code | Description |
| ----------- | ----------- |
| FLT_PREOP_COMPLETE | **FltCheckOplockEx** encountered a pool allocation failure, or a call to the [**FsRtlCheckOplockEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcheckoplockex) function returned an error. **FltCheckOplockEx** sets the error code in the **Status** member of the [**IO_STATUS_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure of the **IoStatus** member of the [**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data) callback data structure. The **CallbackData** parameter points to this FLT_CALLBACK_DATA structure. |
| FLT_PREOP_PENDING | An oplock break was initiated, which caused the Filter Manager to post the I/O operation to a work queue. The I/O operation is represented by the callback data that the **CallbackData** parameter points to. |
| FLT_PREOP_SUCCESS_WITH_CALLBACK | The callback data that the **CallbackData** parameter points to was not pended, and the I/O operation was performed immediately. Be aware that if the caller specified OPLOCK_FLAG_COMPLETE_IF_OPLOCKED in the **Flags** parameter, an oplock break might actually be in progress even though the I/O operation was not pended. To determine whether this is the situation, the caller should check for STATUS_OPLOCK_BREAK_IN_PROGRESS in the **Status** member of the [**IO_STATUS_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure of the **IoStatus** member of the [**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data) callback data structure. |

## Remarks

A minifilter driver calls **FltCheckOplockEx** to synchronize an IRP-based I/O operation with the current oplock state of a file according to the following conditions:

* If the I/O operation will cause the oplock to break, the oplock break is initiated.

* If the I/O operation cannot continue until the oplock break is complete, **FltCheckOplockEx** returns FLT_PREOP_PENDING and calls the callback routine that the *PrePostCallbackDataRoutine* parameter points to.

* If a minifilter driver uses oplocks, it must call **FltCheckOplockEx** from any preoperation callback ([PFLT_PRE_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)) routine for I/O operations that can cause oplock breaks. This rule applies to the following types of I/O operations, because these operations can cause oplock breaks:

  * IRP_MJ_CLEANUP

  * IRP_MJ_CREATE

  * IRP_MJ_FILE_SYSTEM_CONTROL

  * IRP_MJ_FLUSH_BUFFERS

  * IRP_MJ_LOCK_CONTROL

  * IRP_MJ_READ

  * IRP_MJ_SET_INFORMATION

  * IRP_MJ_WRITE

  * IRP_MJ_ACQUIRE_FOR_SECTION_SYNCHRONIZATION

With the exception of IRP_MJ_ACQUIRE_FOR_SECTION_SYNCHRONIZATION, the I/O operation must be an IRP-based I/O operation. To determine whether a given callback data structure represents an IRP-based I/O operation, use the [FLT_IS_IRP_OPERATION](https://learn.microsoft.com/previous-versions/ff544654(v=vs.85)) macro.

Minifilters must not call **FltCheckOplockEx** again within the callback specified in *WaitCompletionRoutine*. Doing so can result in a deadlock condition if the oplock package calls the completion callback before **FltCheckOplockEx** returns.

**FltCheckOplockEx** will only every return FLT_PREOP_SUCCESS_WITH_CALLBACK when the major function is IRP_MJ_ACQUIRE_FOR_SECTION_SYNCHRONIZATION.

For more information about opportunistic locks, see [Opportunistic Locks](https://learn.microsoft.com/windows/win32/fileio/opportunistic-locks).

## See also

[FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[FLT_IS_IRP_OPERATION](https://learn.microsoft.com/previous-versions/ff544654(v=vs.85))

[FltInitializeOplock](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitializeoplock)

[FltOplockFsctrl](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltoplockfsctrl)

[FsRtlCheckOplockEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlcheckoplockex)

[IO_STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block)

[PFLT_PRE_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)