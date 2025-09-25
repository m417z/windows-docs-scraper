# PFLT_COMPLETE_LOCK_CALLBACK_DATA_ROUTINE callback function

## Description

A minifilter driver can register a routine of type **PFLT_COMPLETE_LOCK_CALLBACK_DATA_ROUTINE** as the minifilter driver's **CompleteLockCallbackDataRoutine** callback routine for a [**FILE_LOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_lock) structure.

## Parameters

### `Context` [in, optional]

Context pointer that was passed to [**FltProcessFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltprocessfilelock).

### `CallbackData` [in]

Pointer to the callback data ([**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) structure for the [**IRP_MJ_LOCK_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-lock-control) operation that is being completed. The lock request type will be one of the following:

* IRP_MN_LOCK
* IRP_MN_UNLOCK_ALL
* IRP_MN_UNLOCK_ALL_BY_KEY
* IRP_MN_UNLOCK_SINGLE

## Return value

This routine returns STATUS_SUCCESS or an appropriate NTSTATUS value. If it returns an NTSTATUS value that is not a success code, the file lock is removed from the file.

## Remarks

A minifilter driver can optionally specify a routine of type **PFLT_COMPLETE_LOCK_CALLBACK_DATA_ROUTINE** as the minifilter driver's **CompleteLockCallbackDataRoutine** routine for a byte-range file lock. To specify this routine, the minifilter driver passes a pointer to the routine as the **CompleteLockCallbackDataRoutine** parameter for [**FltAllocateFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatefilelock).

When completing an [**IRP_MJ_LOCK_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-lock-control) operation for the file lock, filter manager calls this routine, if specified, as a notification to the minifilter.

## See also

[**FILE_LOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_lock)

[**FltAllocateFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatefilelock)

[**FltCheckLockForReadAccess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltchecklockforreadaccess)

[**FltCheckLockForWriteAccess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltchecklockforwriteaccess)

[**FltFreeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreefilelock)

[**FltInitializeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitializefilelock)

[**FltProcessFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltprocessfilelock)

[**FltUninitializeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltuninitializefilelock)

[**IRP_MJ_LOCK_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-lock-control)

[**PUNLOCK_ROUTINE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nc-ntifs-punlock_routine)