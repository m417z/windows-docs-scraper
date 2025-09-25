# FsRtlAllocateFileLock function

## Description

The **FsRtlAllocateFileLock** routine allocates and initializes a new FILE_LOCK structure.

## Parameters

### `CompleteLockIrpRoutine` [in, optional]

A pointer to a [**PCOMPLETE_LOCK_IRP_ROUTINE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nc-ntifs-pcomplete_lock_irp_routine)-typed callback routine to be called when an [**IRP_MJ_LOCK_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-lock-control) request is completed. This parameter is optional and can be NULL.

### `UnlockRoutine` [in, optional]

A pointer to a [**PUNLOCK_ROUTINE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nc-ntifs-punlock_routine)-typed callback routine to be called when the byte range is unlocked. This parameter is optional and can be NULL.

## Return value

**FsRtlAllocateFileLock** returns a pointer to the newly allocated FILE_LOCK structure.

## Remarks

**FsRtlAllocateFileLock** allocates a new FILE_LOCK structure from paged pool and initializes it.

Minifilters should call [**FltAllocateFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatefilelock) instead of **FsRtlAllocateFileLock**.

## See also

[**FltAllocateFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatefilelock)

[**FsRtlAreThereCurrentFileLocks**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlaretherecurrentfilelocks)

[**FsRtlCheckLockForReadAccess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlchecklockforreadaccess)

[**FsRtlCheckLockForWriteAccess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlchecklockforwriteaccess)

[**FsRtlFastCheckLockForRead**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlfastchecklockforread)

[**FsRtlFastCheckLockForWrite**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlfastchecklockforwrite)

[**FsRtlFastLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlfastlock)

[**FsRtlFastUnlockAll**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlfastunlockall)

[**FsRtlFastUnlockAllByKey**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlfastunlockallbykey)

[**FsRtlFastUnlockSingle**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlfastunlocksingle)

[**FsRtlGetNextFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlgetnextfilelock)

[**FsRtlInitializeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializefilelock)

[**FsRtlProcessFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlprocessfilelock)

[**FsRtlUninitializeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtluninitializefilelock)

[**IRP_MJ_LOCK_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-lock-control)

[**PCOMPLETE_LOCK_IRP_ROUTINE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nc-ntifs-pcomplete_lock_irp_routine)

[**PUNLOCK_ROUTINE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nc-ntifs-punlock_routine)