# CcSetDirtyPinnedData function

## Description

The **CcSetDirtyPinnedData** routine marks as dirty the buffer control block (BCB) for a pinned buffer whose contents have been modified.

## Parameters

### `BcbVoid` [in]

Pointer to the BCB structure to be marked as dirty.

### `Lsn` [in, optional]

Logical sequence number (LSN) to be associated with this buffer.

## Remarks

**CcSetDirtyPinnedData** marks the BCB as dirty, so that the contents of the pinned buffer will be lazy-written to disk. Even if the flush operation is to be performed by some means other than the lazy writer, **CcSetDirtyPinnedData** should be called whenever the contents of a pinned buffer are modified. This is especially important if the buffer was pinned only for read access (by [CcPinRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpinread) or [CcPinMappedData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpinmappeddata)). Although buffers that are pinned only for read access can be modified, their contents are not automatically flushed to disk unless the buffers have been marked as dirty by calling **CcSetDirtyPinnedData**.

## See also

[CcMapData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccmapdata)

[CcPinMappedData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpinmappeddata)

[CcPinRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpinread)

[CcPreparePinWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpreparepinwrite)

[CcUnpinData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccunpindata)