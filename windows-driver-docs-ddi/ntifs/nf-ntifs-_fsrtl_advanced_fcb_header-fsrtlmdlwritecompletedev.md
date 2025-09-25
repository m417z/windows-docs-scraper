# FsRtlMdlWriteCompleteDev function

## Description

The **FsRtlMdlWriteCompleteDev** routine frees the resources that [FsRtlPrepareMdlWriteDev](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlpreparemdlwritedev) allocated.

## Parameters

### `FileObject` [in]

A pointer to the file object.

### `FileOffset` [in]

A pointer to a value that specifies the starting byte offset within the cache that holds the data.

### `MdlChain` [in]

A pointer to a linked list of memory descriptor lists (MDLs) that [FsRtlPrepareMdlWriteDev](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlpreparemdlwritedev) allocated.

### `DeviceObject` [ in, optional ]

A pointer to a device object on which the file is opened.

## Return value

The **FsRtlMdlWriteCompleteDev** routine returns **TRUE** if the operation succeeds and **FALSE** if the operation fails or if the FO_WRITE_THROUGH flag is set in the file object.

## Remarks

The **FsRtlMdlWriteCompleteDev** routine frees the memory descriptor lists (MDLs) that [FsRtlPrepareMdlWriteDev](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlpreparemdlwritedev) allocated and unlocks the cache memory that **FsRtlPrepareMdlWriteDev** locked.

If the FO_WRITE_THROUGH flag is set on the file object pointed to by the *FileObject* parameter, **FsRtlMdlWriteCompleteDev** immediately flushes the cached memory to disk. This flush operation re-enters the file system and can cause **FsRtlMdlWriteCompleteDev** to raise an exception if the flush operation fails.

Each call to [FsRtlPrepareMdlWriteDev](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlpreparemdlwritedev) must be followed by a call to **FsRtlMdlWriteCompleteDev**.

## See also

[FsRtlPrepareMdlWriteDev](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlpreparemdlwritedev)