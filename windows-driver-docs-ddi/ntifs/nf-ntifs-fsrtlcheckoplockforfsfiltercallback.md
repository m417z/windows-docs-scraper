## Description

A file system can call **FsRtlCheckOplockForFsFilterCallback** to break oplocks that are affected by file system filter operations.

### `Oplock`

[in] Pointer to the oplock structure for the file.

### `CallbackData`

[in] Pointer to the[**FS_FILTER_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-fs_filter_callback_data) structure describing the FS filter operation.

### `Flags`

[in] **OPLOCK_FLAG_*XXX*** values in the OPLOCK_FS_FILTER_FLAGS mask.

## Return value

**FsRtlCheckOplockForFsFilterCallback** returns TRUE if it can complete the operation on exiting this thread; otherwise, it returns FALSE.

## Remarks

FsFilter operations can't be pended and shouldn't be blocked, so this routine can only break oplocks asynchronously.

This routine handles the following operation. Passing any other FsFilter operations is an error.

* FS_FILTER_ACQUIRE_FOR_SECTION_SYNCHRONIZATION