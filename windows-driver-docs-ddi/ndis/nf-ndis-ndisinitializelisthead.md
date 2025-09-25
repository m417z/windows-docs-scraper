# NdisInitializeListHead macro

## Description

The
**NdisInitializeListHead** function initializes a doubly linked, driver-maintained queue.

## Parameters

### `_ListHead` [in]

A pointer to driver-allocated nonpaged storage for the head of the interlocked queue or
list.

## Remarks

**NdisInitializeListHead** can be called from a
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function or
from a protocol driver's
[DriverEntry](https://learn.microsoft.com/previous-versions/windows/embedded/gg156036(v=winembedded.80)) routine
if the driver queues requests internally. However, miniport drivers seldom set up internal queues because
the NDIS library serializes requests and packets sent to miniport drivers.

Any NDIS driver that maintains an internal queue is responsible for synchronizing driver functions'
accesses to queued entries. The
**NdisInterlocked*Xxx*List** functions ensure that only one driver function can access queued entries at any given moment,
even if the driver is running on a multiprocessor computer, because the queue is protected by a
caller-supplied spin lock.

For an interlocked queue, the driver also must provide nonpaged storage for a spin lock. It must
initialize the spin lock with the
[NdisAllocateSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatespinlock) function before
passing a pointer to that spin lock to any of the
**NdisInterlocked*Xxx*List** functions.

Callers of **NdisInitializeListHead** can be running at any IRQL. If **NdisInitializeListHead** is called at IRQL >= DISPATCH_LEVEL the storage for *ListHead* must be resident.

## See also

[DriverEntry of NDIS Protocol
Drivers](https://learn.microsoft.com/previous-versions/windows/embedded/gg156036(v=winembedded.80))

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NdisAllocateSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatespinlock)

[NdisInterlockedInsertHeadList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinterlockedinsertheadlist)

[NdisInterlockedInsertTailList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinterlockedinserttaillist)

[NdisInterlockedRemoveHeadList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinterlockedremoveheadlist)