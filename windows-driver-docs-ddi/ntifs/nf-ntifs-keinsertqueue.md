# KeInsertQueue function

## Description

The **KeInsertQueue** routine inserts an entry at the tail of the given queue if it cannot immediately use the entry to satisfy a thread wait.

## Parameters

### `Queue` [in, out]

Pointer to an initialized queue object for which the caller provides resident storage in nonpaged pool.

### `Entry` [in, out]

Pointer to an entry to be queued. This pointer must be a resident system-space address.

## Return value

**KeInsertQueue** returns the previous signal state of the given *Queue*. If it was set to zero (that is, not signaled) before **KeInsertQueue** was called, **KeInsertQueue** returns zero, meaning that no entries were queued. If it was nonzero (signaled), **KeInsertQueue** returns the number of entries that were queued before **KeInsertQueue** was called.

## Remarks

Entries to be queued by **KeInsertQueue** must be allocated from nonpaged pool. For example, memory for caller-defined entries can be allocated with [ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag). If the caller allocates entries of a fixed size, creating a lookaside list with [ExInitializeNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializenpagedlookasidelist) and allocating from it with [ExAllocateFromNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatefromnpagedlookasidelist) is more efficient than making frequent calls to **ExAllocatePoolWithTag**, particularly for entries whose size is not a multiple of PAGE_SIZE.

If any threads are waiting on the queue object when **KeInsertQueue** is called, a single thread's wait is satisfied by this call. The thread is dispatched for execution with the given *Entry* pointer.

If no threads are currently waiting on the queue object when **KeInsertQueue** is called, the given entry is inserted in the queue, and the queue object's signal state is incremented.

For more information about using driver-managed internal queues, see [Driver-Managed Queues](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#driver-managed-queues).

## See also

[ExAllocateFromNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatefromnpagedlookasidelist)

[ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag)

[ExInitializeNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializenpagedlookasidelist)

[KeInitializeQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-keinitializequeue)

[KeInsertHeadQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-keinsertheadqueue)

[KeRemoveQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-keremovequeue)