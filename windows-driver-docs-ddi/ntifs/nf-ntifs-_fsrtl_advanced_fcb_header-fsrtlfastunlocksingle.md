# FsRtlFastUnlockSingle function

## Description

The **FsRtlFastUnlockSingle** routine releases a byte-range lock that was acquired by the specified process, with the specified key value, file offset, and length, for a file.

## Parameters

### `FileLock` [in]

A pointer to the FILE_LOCK structure for the file. This structure must have been initialized by a previous call to [FsRtlAllocateFileLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlallocatefilelock) or [FsRtlInitializeFileLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializefilelock).

### `FileObject` [in]

A pointer to the file object for the file.

### `FileOffset` [in]

A pointer to a variable that specifies the starting byte offset within the file of the range to be unlocked. The memory pointed to must not be pageable.

### `Length` [in]

A pointer to a variable that specifies the length, in bytes, of the range to be unlocked. The memory pointed to must not be pageable.

### `ProcessId` [in]

A pointer to the process ID for the process.

### `Key` [in]

The key for the byte-range lock.

### `Context` [in, optional]

An optional context pointer to be used when completing IRPs.

### `AlreadySynchronized` [in]

This parameter is obsolete, but is retained for compatibility with legacy drivers.

## Return value

The **FsRtlFastUnlockSingle** routine returns STATUS_SUCCESS or an error status code such as STATUS_RANGE_NOT_LOCKED.

## See also

[FsRtlAllocateFileLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlallocatefilelock)

[FsRtlInitializeFileLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializefilelock)