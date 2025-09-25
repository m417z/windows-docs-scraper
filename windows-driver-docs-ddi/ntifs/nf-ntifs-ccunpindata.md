# CcUnpinData function

## Description

The **CcUnpinData** routine releases cached file data that was mapped or pinned by an earlier call to [CcMapData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccmapdata), [CcPinRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpinread), or [CcPreparePinWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpreparepinwrite).

## Parameters

### `Bcb` [in]

Pointer to a buffer control block (BCB) for the data to be released.

## Remarks

**CcUnpinData** frees the BCB and performs any other necessary cleanup.

Every successful call to [CcMapData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccmapdata), [CcPinRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpinread), or [CcPreparePinWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpreparepinwrite) must be matched by a subsequent call to **CcUnpinData**.

BCBs that have been modified by [CcSetBcbOwnerPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccsetbcbownerpointer) cannot be unpinned by calling **CcUnpinData**. [CcUnpinDataForThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccunpindataforthread) must be called instead.

## See also

[CcMapData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccmapdata)

[CcPinRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpinread)

[CcPreparePinWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpreparepinwrite)

[CcSetBcbOwnerPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccsetbcbownerpointer)

[CcUnpinDataForThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccunpindataforthread)