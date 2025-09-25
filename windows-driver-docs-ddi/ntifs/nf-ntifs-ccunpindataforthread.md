# CcUnpinDataForThread function

## Description

The **CcUnpinDataForThread** routine releases pages of a cached file whose buffer control block (BCB) was modified by an earlier call to [CcSetBcbOwnerPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccsetbcbownerpointer).

## Parameters

### `Bcb` [in]

Pointer to the BCB for the pages to be released.

### `ResourceThreadId` [in]

Identifies the thread that originally acquired the BCB. Must match the owner pointer used in the call to [CcSetBcbOwnerPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccsetbcbownerpointer).

## Remarks

**CcUnpinDataForThread** releases the BCB for the indicated thread and performs any other necessary cleanup.

Each call to [CcSetBcbOwnerPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccsetbcbownerpointer) must be matched by a subsequent call to **CcUnpinDataForThread**.

**CcUnpinDataForThread** is functionally equivalent to [CcUnpinData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccunpindata), except that it also releases the BCB resource for the indicated thread.

## See also

[CcSetBcbOwnerPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccsetbcbownerpointer)

[CcUnpinData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccunpindata)