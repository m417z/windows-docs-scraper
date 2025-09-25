# FsRtlInitializeFileLock function

## Description

The **FsRtlInitializeFileLock** routine initializes a FILE_LOCK structure.

## Parameters

### `FileLock` [in]

Pointer to an uninitialized [**FILE_LOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_lock) structure.

### `CompleteLockIrpRoutine` [in, optional]

Pointer to a [**PCOMPLETE_LOCK_IRP_ROUTINE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nc-ntifs-pcomplete_lock_irp_routine)-typed callback routine to be called when an [**IRP_MJ_LOCK_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-lock-control) request is completed. This parameter is optional and can be NULL.

### `UnlockRoutine` [in, optional]

Pointer to a [**PUNLOCK_ROUTINE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nc-ntifs-punlock_routine)-typed callback routine to be called when the byte range is unlocked. This parameter is optional and can be NULL.

## Remarks

**FsRtlInitializeFileLock** initializes an uninitialized FILE_LOCK structure.

It is a programming error to call **FsRtlInitializeFileLock** for a FILE_LOCK structure that has already been initialized by **FsRtlInitializeFileLock** or [**FltAllocateFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatefilelock), unless the structure has been uninitialized by a subsequent call to [**FsRtlUninitializeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtluninitializefilelock).

Once initialized, the FILE_LOCK structure can be used to lock a byte range in a file by calling [**FsRtlProcessFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlprocessfilelock) or[**FsRtlFastLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlfastlock). **FsRtlProcessFileLock** processes lock IRPs. **FsRtlFastLock** performs non-IRP locking.

When the **FILE_LOCK** structure is no longer needed, it can be uninitialized by calling [**FsRtlUninitializeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtluninitializefilelock). The uninitialized FILE_LOCK structure can then be initialized for reuse by calling **FsRtlInitializeFileLock**.

Minifilters must call [**FltInitializeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitializefilelock) instead of **FsRtlInitializeFileLock**.

## See also

[**FILE_LOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_lock)

[**FltInitializeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitializefilelock)

[**FltAllocateFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatefilelock)

[**FsRtlAreThereCurrentFileLocks**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlaretherecurrentfilelocks)

[**FsRtlFastLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlfastlock)

[**FsRtlProcessFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlprocessfilelock)

[**FsRtlUninitializeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtluninitializefilelock)

[**IRP_MJ_LOCK_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-lock-control)

[**IoCompleteRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocompleterequest)

[**PCOMPLETE_LOCK_IRP_ROUTINE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nc-ntifs-pcomplete_lock_irp_routine)

[**PUNLOCK_ROUTINE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nc-ntifs-punlock_routine)