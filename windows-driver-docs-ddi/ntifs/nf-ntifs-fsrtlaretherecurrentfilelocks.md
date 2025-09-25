# FsRtlAreThereCurrentFileLocks macro

## Description

The **FsRtlAreThereCurrentFileLocks** macro checks whether any byte range locks exist for the specified file.

## Parameters

### `FL`

Pointer to the [**FILE_LOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_lock) structure for the file. This structure must have been initialized by a previous call to [**FsRtlAllocateFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlallocatefilelock) or [**FsRtlInitializeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializefilelock).

## Remarks

This macro acts like a BOOLEAN function, returning TRUE if any byte range locks exist for the specified file or FALSE if none exist.

File systems and filter drivers often call **FsRtlAreThereCurrentFileLocks** from their **FastIoCheckIfPossible** routines.

If a byte-range lock has existed since the specified file was opened, **FsRtlAreThereCurrentFileLocks** returns TRUE unless the relevant **FILE_LOCK** is reinitialized. If a lock was established and then released, the use of **FsRtlAreThereCurrentFileLocks** can unnecessarily prevent the assignment of oplocks. Use [**FsRtlAreThereCurrentOrInProgressFileLocks**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlaretherecurrentorinprogressfilelocks) to avoid this problem.

## See also

[**FsRtlAllocateFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlallocatefilelock)

[**FsRtlAreThereCurrentOrInProgressFileLocks**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlaretherecurrentorinprogressfilelocks)

[**FsRtlInitializeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializefilelock)