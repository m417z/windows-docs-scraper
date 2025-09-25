# CcMdlWriteAbort function

## Description

The **CcMdlWriteAbort** routine frees memory descriptor lists (MDL) created by an earlier call to [CcPrepareMdlWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpreparemdlwrite).

## Parameters

### `FileObject` [in]

File object pointer that was passed to [CcPrepareMdlWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpreparemdlwrite).

### `MdlChain` [in]

Address of the MDL chain returned by [CcPrepareMdlWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpreparemdlwrite).

## Remarks

File systems call **CcMdlWriteAbort** to free the memory descriptor lists (MDL) created by an earlier call to [CcPrepareMdlWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpreparemdlwrite) for a cached file. All physical pages that were locked down are unlocked. Any pages that were mapped are unmapped.

File systems normally call **CcMdlWriteAbort** only in cases where, after a successful call to [CcPrepareMdlWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpreparemdlwrite), it is necessary to abort or fail the subsequent MDL write operation.

Unlike [CcMdlWriteComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccmdlwritecomplete), **CcMdlWriteAbort** does not cause any data to be written to the cached file.

## See also

[CcMdlWriteComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccmdlwritecomplete)

[CcPrepareMdlWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpreparemdlwrite)