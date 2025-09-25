# FltAllocateFileLock function

## Description

The **FltAllocateFileLock** routine allocates and initializes a new [**FILE_LOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_lock) structure.

## Parameters

### `CompleteLockCallbackDataRoutine` [in, optional]

Pointer to a [**PFLT_COMPLETE_LOCK_CALLBACK_DATA_ROUTINE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_complete_lock_callback_data_routine)-typed callback routine to be called when an [**IRP_MJ_LOCK_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-lock-control) request is completed. This parameter is optional and can be NULL.

### `UnlockRoutine` [in, optional]

Pointer to a [**PUNLOCK_ROUTINE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nc-ntifs-punlock_routine)-typed callback routine to be called when the byte range is unlocked. This parameter is optional and can be NULL.

## Return value

**FltAllocateFileLock** returns a pointer to the newly allocated [**FILE_LOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_lock) structure.

## Remarks

**FltAllocateFileLock** allocates a new [**FILE_LOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_lock) structure from paged pool and initializes it.

The returned [**FILE_LOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_lock) structure can be used to lock a byte range in a file by calling [**FltProcessFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltprocessfilelock).

When the [**FILE_LOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_lock) structure is no longer needed, it can be uninitialized by calling [**FltUninitializeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltuninitializefilelock). The uninitialized **FILE_LOCK** structure can then be initialized for reuse by calling **FltInitializeFileLock**.

To free an initialized [**FILE_LOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_lock) structure, call [**FltFreeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreefilelock).

When the **CallbackData** parameter passed to [**FltProcessFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltprocessfilelock) represents a fast I/O operation, the callback specified in **CompleteLockCallbackDataRoutine** is not invoked. Only when the I/O operation in **CallbackData** is an IRP, and **CompleteLockCallbackDataRoutine** is not NULL, will the callback routine be called.

## See also

[**FILE_LOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_lock)

[**FltCheckLockForReadAccess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltchecklockforreadaccess)

[**FltCheckLockForWriteAccess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltchecklockforwriteaccess)

[**FltFreeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreefilelock)

[**FltInitializeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitializefilelock)

[**FltProcessFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltprocessfilelock)

[**FltUninitializeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltuninitializefilelock)

[**FsRtlAllocateFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlallocatefilelock)

[**IRP_MJ_LOCK_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-lock-control)

[**PFLT_COMPLETE_LOCK_CALLBACK_DATA_ROUTINE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_complete_lock_callback_data_routine)

[**PUNLOCK_ROUTINE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nc-ntifs-punlock_routine)