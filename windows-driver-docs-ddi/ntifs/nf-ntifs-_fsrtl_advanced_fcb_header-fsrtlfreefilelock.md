# FsRtlFreeFileLock function

## Description

The **FsRtlFreeFileLock** routine uninitializes and frees a file lock structure.

## Parameters

### `FileLock` [in]

Pointer to the FILE_LOCK structure. This structure must have been allocated by a previous call to **FsRtlAllocateFileLock**.

## Remarks

**FsRtlFreeFileLock** should be used only for file locks that were allocated and initialized by **FsRtlAllocateFileLock**.

It is a programming error to call **FsRtlFreeFileLock** for a FILE_LOCK structure that has already been uninitialized by a call to [FsRtlUninitializeFileLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtluninitializefilelock).

Minifilters must call [FltFreeFileLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreefilelock) instead of **FsRtlFreeFileLock**.

## See also

[FltFreeFileLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreefilelock)

[FsRtlAreThereCurrentFileLocks](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlaretherecurrentfilelocks)

[FsRtlCheckLockForReadAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlchecklockforreadaccess)

[FsRtlCheckLockForWriteAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlchecklockforwriteaccess)

[FsRtlFastCheckLockForRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlfastchecklockforread)

[FsRtlFastCheckLockForWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlfastchecklockforwrite)

[FsRtlFastLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlfastlock)

[FsRtlFastUnlockAll](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlfastunlockall)

[FsRtlFastUnlockAllByKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlfastunlockallbykey)

[FsRtlFastUnlockSingle](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlfastunlocksingle)

[FsRtlGetNextFileLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlgetnextfilelock)

[FsRtlInitializeFileLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializefilelock)

[FsRtlProcessFileLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlprocessfilelock)

[FsRtlUninitializeFileLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtluninitializefilelock)