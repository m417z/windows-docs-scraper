## Description

A file system filter driver (legacy filter) can register a **PCOMPLETE_LOCK_IRP_ROUTINE**-typed routine as the filter's *CompleteLockIrpRoutine* callback.

## Parameters

### `Context`

[in] Context pointer that was passed to [**FsRtlProcessFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlprocessfilelock).

### `Irp`

[in] IRP for the file lock [**IRP_MJ_LOCK_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-lock-control) request that is being completed. The lock request type will be one of the following:

* IRP_MN_LOCK
* IRP_MN_UNLOCK_ALL
* IRP_MN_UNLOCK_ALL_BY_KEY
* IRP_MN_UNLOCK_SINGLE

## Return value

This routine returns STATUS_SUCCESS or an appropriate NTSTATUS value. If it returns an NTSTATUS value that is not a success code, the file lock is removed from the file.

## Remarks

A file system filter driver (legacy filter) can optionally specify a PCOMPLETE_LOCK_IRP_ROUTINE-typed routine as the legacy filter's *CompleteLockIrpRoutine* routine for a byte-range file lock.

To specify this routine, a legacy filter passes a pointer to the routine as the *CompleteLockIrpRoutine* parameter for [**FsRtlAllocateFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlallocatefilelock) or [**FsRtlInitializeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializefilelock).

If the legacy filter specifies a *CompleteLockIrpRoutine* routine for a file lock, the system calls this routine when completing an [**IRP_MJ_LOCK_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-lock-control) operation for the file lock.

## See also

[**FsRtlAllocateFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlallocatefilelock)

[**FsRtlCheckLockForReadAccess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlchecklockforreadaccess)

[**FsRtlCheckLockForWriteAccess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlchecklockforwriteaccess)

[**FsRtlFreeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlfreefilelock)

[**FsRtlInitializeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializefilelock)

[**FsRtlProcessFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlprocessfilelock)

[**FsRtlUninitializeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtluninitializefilelock)

[**IRP_MJ_LOCK_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-lock-control)

[**PUNLOCK_ROUTINE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nc-ntifs-punlock_routine)