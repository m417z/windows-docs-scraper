# NdisFreeSpinLock function

## Description

The
**NdisFreeSpinLock** function releases a spin lock initialized in a preceding call to the
[NdisAllocateSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatespinlock) function.

## Parameters

### `SpinLock` [in]

Pointer to the spin lock to be deinitialized.

## Remarks

If the caller of
**NdisFreeSpinLock** needs to use the spin lock again, it must call
**NdisAllocateSpinLock** before passing that spin lock pointer to any of the
**Ndis..SpinLock** or
**NdisInterlocked*Xxx*** functions.

Callers of
**NdisFreeSpinLock** can run at any IRQL. Usually, this function is not called until a driver is
unloading.

## See also

[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt)

[NdisAcquireSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisacquirespinlock)

[NdisAllocateSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatespinlock)

[NdisDprAcquireSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisdpracquirespinlock)

[NdisDprReleaseSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisdprreleasespinlock)

[NdisInterlockedAddUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinterlockedaddulong)

[NdisInterlockedInsertHeadList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinterlockedinsertheadlist)

[NdisInterlockedInsertTailList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinterlockedinserttaillist)

[NdisInterlockedRemoveHeadList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinterlockedremoveheadlist)

[NdisReleaseSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreleasespinlock)