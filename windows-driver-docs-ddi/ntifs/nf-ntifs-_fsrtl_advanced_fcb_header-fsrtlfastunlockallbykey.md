# FsRtlFastUnlockAllByKey function

## Description

The **FsRtlFastUnlockAllByKey** routine releases all byte-range locks that were acquired by the specified process, with the specified key value, for a file.

## Parameters

### `FileLock` [in]

A pointer to the FILE_LOCK structure for the file. This structure must have been initialized by a previous call to [FsRtlAllocateFileLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlallocatefilelock) or [FsRtlInitializeFileLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializefilelock).

### `FileObject` [in]

A pointer to the file object for the file.

### `ProcessId` [in]

A pointer to the process ID for the process.

### `Key` [in]

The key value.

### `Context` [in, optional]

Optional context pointer to be used when completing IRPs.

## Return value

**FsRtlFastUnlockAllByKey** returns STATUS_SUCCESS or an error status code such as STATUS_RANGE_NOT_LOCKED.

## Remarks

After releasing the byte-range locks, **FsRtlFastUnlockAllByKey** completes any currently queued lock IRPs that can now be completed.

## See also

[FsRtlAllocateFileLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlallocatefilelock)

[FsRtlInitializeFileLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializefilelock)