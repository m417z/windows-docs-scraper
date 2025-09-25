# FsRtlAreThereCurrentOrInProgressFileLocks function

## Description

The**FsRtlAreThereCurrentOrInProgressFileLocks** routine determines if there are byte range locks assigned to a file or any lock operations in progress for that file.

## Parameters

### `FileLock` [in]

A pointer to the [**FILE_LOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_lock) structure for the file to be checked.

## Return value

The routine returns TRUE when there are any byte range locks assigned to the file or when there are byte range lock requests in progress for the file. Otherwise, the routine returns FALSE.

## Remarks

File systems can use the **FsRtlAreThereCurrentOrInProgressFileLocks** routine in [Oplock Semantics](https://learn.microsoft.com/windows-hardware/drivers/ifs/oplock-semantics) to determine whether to grant a shared oplock.

## See also

[**FILE_LOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_lock)

[**FsRtlAllocateFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlallocatefilelock)

[**FsRtlGetNextFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlgetnextfilelock)

[**FsRtlInitializeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializefilelock)