# CcMdlWriteComplete function

## Description

The **CcMdlWriteComplete** routine frees the memory descriptor lists (MDL) created by [CcPrepareMdlWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpreparemdlwrite) for a cached file.

## Parameters

### `FileObject` [in]

File object pointer that was passed to [CcPrepareMdlWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpreparemdlwrite).

### `FileOffset` [in]

Value of *FileOffset* that was passed to [CcPrepareMdlWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpreparemdlwrite).

### `MdlChain` [in]

Address of the MDL chain returned by [CcPrepareMdlWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpreparemdlwrite).

## Remarks

File systems call **CcMdlWriteComplete** to free the memory descriptor lists (MDL) created by [CcPrepareMdlWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpreparemdlwrite) for a cached file and to mark the specified byte range for write. All physical pages that were locked down are unlocked. Any pages that were mapped are unmapped.

If the FO_WRITE_THROUGH flag is set on the file object pointed to by the *FileObject* parameter, the file data is immediately flushed to disk. This flush operation re-enters the file system and can cause **CcMdlWriteComplete** to raise an exception if the flush operation fails. In this case, the MDL has not been freed and the caller may re-try the operation.

After **CcMdlWriteComplete** is called successfully for an IRP_MN_COMPLETE operation, the caller must set the IRP's **MdlAddress** field to **NULL**.

Before using **CcMdlWriteComplete**, file system developers are strongly encouraged to study the way this routine is used in the FASTFAT sample.

Each call to [CcPrepareMdlWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpreparemdlwrite) must be followed by a call to **CcMdlWriteComplete** or [CcMdlWriteAbort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccmdlwriteabort).

## See also

[CcMdlWriteAbort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccmdlwriteabort)

[CcPrepareMdlWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpreparemdlwrite)