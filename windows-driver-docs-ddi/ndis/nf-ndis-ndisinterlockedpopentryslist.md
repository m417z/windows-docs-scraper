# NdisInterlockedPopEntrySList macro

## Description

The
**NdisInterlockedPopEntrySList** function removes the first entry from a sequenced, singly linked
list.

## Parameters

### `SListHead`

A pointer to the head of the already initialized sequenced, singly linked list from which the
entry is to be returned.

### `Lock` [in]

A pointer to a caller-supplied spin lock, not currently held by the caller.

## Remarks

A driver
must not be holding the given
*Lock* when it calls
**NdisInterlockedPopEntrySList**. If necessary, the driver should call the
[NdisReleaseSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreleasespinlock) function before
making this call.
**NdisInterlockedPopEntrySList** itself must acquire this spin lock to remove the first entry in the
S-List, if any, in a multiprocessor-safe way.

The caller must provide resident storage for the
*Lock*, which must be initialized with the
[NdisAllocateSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatespinlock) function before
the initial call to any
**NdisInterlocked..SList** function.

If
**NdisInterlockedPopEntrySList** is called at IRQL >= DISPATCH_LEVEL, the storage for the
*ListHead* parameter must be resident.

## See also

[NdisAllocateSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatespinlock)

[NdisFreeSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreespinlock)

[NdisInitializeSListHead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinitializeslisthead)

[NdisInterlockedPushEntrySList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinterlockedpushentryslist)

[NdisQueryDepthSList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisquerydepthslist)

[NdisReleaseSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreleasespinlock)