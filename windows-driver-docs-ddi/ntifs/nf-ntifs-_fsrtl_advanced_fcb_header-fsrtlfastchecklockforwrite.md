# FsRtlFastCheckLockForWrite function

## Description

The **FsRtlFastCheckLockForWrite** routine determines whether the specified process has write access to a locked byte range of a file.

## Parameters

### `FileLock` [in]

A pointer to the FILE_LOCK structure for the file. This structure must have been initialized by a previous call to [FsRtlAllocateFileLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlallocatefilelock) or [FsRtlInitializeFileLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializefilelock).

### `StartingByte` [in]

A pointer to a variable that specifies the starting byte offset within the file of the byte range to check.

### `Length` [in]

A pointer to a variable that specifies the length, in bytes, of the range to check.

### `Key` [in]

The key for the byte range lock.

### `FileObject` [in]

A pointer to the file object for the file.

### `ProcessId` [in]

A pointer to the EPROCESS for the process.

## Return value

The [FsRtlFastCheckLockForWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlfastchecklockforwrite) routine returns **TRUE** if the specified process has write access, **FALSE** otherwise.

## See also

[FsRtlAllocateFileLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlallocatefilelock)

[FsRtlFastCheckLockForRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlfastchecklockforread)

[FsRtlInitializeFileLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializefilelock)