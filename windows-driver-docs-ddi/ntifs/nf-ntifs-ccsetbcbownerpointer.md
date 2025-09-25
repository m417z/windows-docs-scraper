# CcSetBcbOwnerPointer function

## Description

The **CcSetBcbOwnerPointer** routine sets the owner thread pointer for a pinned buffer control block (BCB).

## Parameters

### `Bcb` [in]

Pointer to a pinned BCB structure that is owned by the current thread.

### `OwnerPointer` [in]

A valid resource owner pointer, which means a pointer to an allocated system address, with the low-order two bits set. This address may not be deallocated until after the BCB is unpinned by a subsequent call to [CcUnpinDataForThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccunpindataforthread).

## Remarks

File systems call **CcSetBcbOwnerPointer** to set the resource owner for a pinned buffer control block (BCB), in cases where another thread will unpin the BCB and thus the current thread can exit.

Each call to **CcSetBcbOwnerPointer** must be matched by a subsequent call to [CcUnpinDataForThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccunpindataforthread), which must be called with the same owner pointer.

BCBs that have been modified by **CcSetBcbOwnerPointer** cannot be unpinned by calling [CcUnpinData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccunpindata).

## See also

[CcUnpinData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccunpindata)

[CcUnpinDataForThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccunpindataforthread)

[ExSetResourceOwnerPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exsetresourceownerpointer)