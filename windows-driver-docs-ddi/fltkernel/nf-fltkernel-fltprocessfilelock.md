# FltProcessFileLock function

## Description

The **FltProcessFileLock** routine processes and completes a file lock operation.

## Parameters

### `FileLock` [in]

Pointer to the [**FILE_LOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_lock) structure for the file. This structure must have been initialized by a previous call to [**FltAllocateFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatefilelock) or [**FltInitializeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitializefilelock).

### `CallbackData` [in]

Pointer to the callback data ([**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) structure for the [**IRP_MJ_LOCK_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-lock-control) operation.

### `Context` [in, optional]

Context pointer to be used when completing the operation. This context pointer is passed to the **CompleteLockCallbackDataRoutine** and **UnlockRoutine** callback routines that the minifilter driver registered in a previous call to [**FltAllocateFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatefilelock). This parameter is optional and can be NULL.

## Return value

**FltProcessFileLock** returns one of the following.

| Return code | Description |
| ----------- | ----------- |
| FLT_PREOP_COMPLETE | The Filter Manager is done with the **CallbackData**, which can now be completed. |
| FLT_PREOP_DISALLOW_FASTIO | The **CallbackData** represents a fast I/O operation, and a minifilter driver in the stack has disallowed the fast I/O to be used for this operation. The Filter Manager does not send the operation to any minifilter drivers below the one that disallowed the operation. In this case, the Filter Manager only calls the postoperation callback routines (and **CompleteLockCallbackDataRoutine** callbacks) of the minifilter drivers above the minifilter driver that disallowed the fast I/O operation. |
| FLT_PREOP_PENDING | The lock operation has been pended. |

## Remarks

**FltProcessFileLock** processes a file lock ([**IRP_MJ_LOCK_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-lock-control)) operation. The lock operation can be a fast I/O or IRP-based operation.

For unlock operations, the Filter Manager calls the [**UnlockRoutine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nc-ntifs-punlock_routine) callback routine that the caller registered for the [**FILE_LOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_lock) structure in a previous call to [**FltAllocateFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatefilelock).

When the lock operation is completed, the Filter Manager calls the **CompleteLockCallbackDataRoutine** ([**PFLT_COMPLETE_LOCK_CALLBACK_DATA_ROUTINE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_complete_lock_callback_data_routine)) completion callback routine that the caller registered for the [**FILE_LOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_lock) structure in a previous call to [**FltAllocateFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatefilelock).

When the **CallbackData** parameter passed to **FltProcessFileLock** represents a fast I/O operation, the callback specified in **CompleteLockCallbackDataRoutine** parameter of the [**FltAllocateFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatefilelock) routine is not invoked. Only when the I/O operation in **CallbackData** is an IRP, and **CompleteLockCallbackDataRoutine** is not NULL, will the callback routine be called.

To determine whether the **CallbackData** represents a fast I/O operation, use the [**FLT_IS_FASTIO_OPERATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flt_is_fastio_operation) macro.

To allocate and initialize a new file lock structure, call [**FltAllocateFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatefilelock).

To free an initialized [**FILE_LOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_lock) structure, call [**FltFreeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreefilelock).

## See also

[**FILE_LOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_lock)

[**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[**FLT_IS_FASTIO_OPERATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flt_is_fastio_operation)

[**FltAllocateFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatefilelock)

[**FltCheckLockForReadAccess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltchecklockforreadaccess)

[**FltCheckLockForWriteAccess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltchecklockforwriteaccess)

[**FltFreeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreefilelock)

[**FltInitializeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitializefilelock)

[**FltUninitializeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltuninitializefilelock)

[**FsRtlProcessFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlprocessfilelock)

[**IRP_MJ_LOCK_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-lock-control)

[**PFLT_COMPLETE_LOCK_CALLBACK_DATA_ROUTINE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_complete_lock_callback_data_routine)

[**PUNLOCK_ROUTINE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nc-ntifs-punlock_routine)