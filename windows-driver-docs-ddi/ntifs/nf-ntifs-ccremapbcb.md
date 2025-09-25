# CcRemapBcb function

## Description

The **CcRemapBcb** routine maps a buffer control block (BCB) an additional time to preserve it through several calls that perform additional maps and unpins.

## Parameters

### `Bcb` [in]

Pointer to the BCB to be remapped.

## Return value

**CcRemapBcb** returns a pointer to the remapped BCB with a read-only indicator.

## Remarks

Like [CcMapData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccmapdata), **CcRemapBcb** maps data in a cached file for read access. Note that after **CcRemapBcb** is called, the data is mapped; but it is not pinned. This distinction is important. Data that is mapped but not pinned cannot safely be modified. To pin the data, use [CcPinMappedData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpinmappeddata), [CcPinRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpinread), or [CcPreparePinWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpreparepinwrite).

## See also

[CcMapData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccmapdata)

[CcPinMappedData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpinmappeddata)

[CcPinRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpinread)

[CcPreparePinWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpreparepinwrite)

[CcUnpinData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccunpindata)