# NdisInitializeSListHead macro

## Description

The
**NdisInitializeSListHead** function initializes the head of a sequenced, interlocked, singly linked
list.

## Parameters

### `SListHead` [in]

A pointer to the caller-supplied list head to be initialized, which must be in resident
memory. The structure must be 16-byte aligned on 64-bit platforms.

## Remarks

**NdisInitializeSListHead** zero-initializes the opaque list head at
*SListHead* and sets the first-entry pointer to **NULL**.

The sequence number in an S-List is incremented each time an entry is inserted to, or removed from,
the list.

All entries in an S-List must be nonpaged.

Any driver that uses an S-List must provide a spin lock to the
[NdisInterlockedPushEntrySList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinterlockedpushentryslist) and
[NdisInterlockedPopEntrySList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinterlockedpopentryslist) functions. Before its initial call to either of these functions, the
driver must initialize the spin lock with the
[NdisAllocateSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatespinlock) function. To
prevent deadlocks, the driver
must not be holding this spin lock when it makes subsequent calls to
**NdisInterlockedPushEntrySList** and
**NdisInterlockedPopEntrySList**.

To manage a pool of fixed-size entries from nonpaged memory, consider using a lookaside list instead
of an S-List.

Drivers that retry I/O operations should use a doubly linked interlocked queue and the [NdisInterlockedInsertHeadList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinterlockedinsertheadlist), [NdisInterlockedInsertTailList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinterlockedinserttaillist), and [NdisInterlockedRemoveHeadList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinterlockedremoveheadlist) functions, rather than an S-List.

If
**NdisInitializeSListHead** is called at IRQL >= DISPATCH_LEVEL, the storage for the
*SListHead* parameter must be resident.

## See also

[NdisInitializeNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinitializenpagedlookasidelist)

[NdisInterlockedPopEntrySList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinterlockedpopentryslist)

[NdisInterlockedPushEntrySList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinterlockedpushentryslist)

[NdisQueryDepthSList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisquerydepthslist)

[NdisQueueIoWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisqueueioworkitem)