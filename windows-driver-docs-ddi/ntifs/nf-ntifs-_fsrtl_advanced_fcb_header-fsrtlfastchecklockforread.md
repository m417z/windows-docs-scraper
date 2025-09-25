# FsRtlFastCheckLockForRead function

## Description

The **FsRtlFastCheckLockForRead** routine determines whether the specified process has read access to a locked byte range of a file.

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

The **FsRtlFastCheckLockForRead** routine returns **TRUE** if the specified process has read access, **FALSE** otherwise.

## See also

[FsRtlAllocateFileLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlallocatefilelock)

[FsRtlFastCheckLockForWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlfastchecklockforwrite)

[FsRtlInitializeFileLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializefilelock)