# NdisInterlockedPushEntrySList macro

## Description

The
**NdisInterlockedPushEntrySList** function inserts an entry at the head of a sequenced, singly linked
list.

## Parameters

### `SListHead`

A pointer to the head of the already initialized sequenced, singly linked list into which the
specified entry is to be inserted.

### `SListEntry`

A pointer to the entry to be inserted.

### `Lock` [in]

A pointer to a caller-supplied spin lock, not currently held by the caller.

## Remarks

Before the driver's initial call the
**NdisInterlockedPushEntrySList** function, it must initialize the list head with the
[NdisInitializeSListHead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinitializeslisthead) function.

A driver
must not be holding the given
*Lock* when it calls
**NdisInterlockedPushEntrySList**. If necessary, a driver must call the
[NdisReleaseSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreleasespinlock) function before
calling
**NdisInterlockedPushEntrySList**.
**NdisInterlockedPushEntrySList** must acquire this lock itself before it inserts
*ListEntry* at the head of the list to ensure that this operation is handled in a multiprocessor-safe
way.

The caller must provide resident storage for the
*Lock*, which must be initialized with the
[NdisAllocateSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatespinlock) function before
the initial call to any
**NdisInterlocked..SList** routine.

Drivers that retry I/O operations should use a doubly linked interlocked queue and the
**NdisInterlockedInsert/Remove..List** functions, instead of an S-List.

If
**NdisInterlockedPushEntrySList** is called at IRQL >= DISPATCH_LEVEL, the storage for the
*ListHead* parameter and the list entries must be resident

## See also

[NdisAllocateSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatespinlock)

[NdisFreeSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreespinlock)

[NdisInitializeSListHead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinitializeslisthead)

[NdisInterlockedPopEntrySList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinterlockedpopentryslist)

[NdisQueryDepthSList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisquerydepthslist)

[NdisReleaseSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreleasespinlock)