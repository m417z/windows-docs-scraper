# KeInsertHeadQueue function

## Description

The **KeInsertHeadQueue** routine inserts an entry at the head of the given queue if it cannot immediately use the entry to satisfy a thread wait.

## Parameters

### `Queue` [in, out]

Pointer to an initialized queue object for which the caller provides resident storage in nonpaged pool. This structure is defined as follows:

```
typedef struct _KQUEUE {
    DISPATCHER_HEADER Header;
    LIST_ENTRY EntryListHead;
    ULONG CurrentCount;
    ULONG MaximumCount;
    LIST_ENTRY ThreadListHead;
} KQUEUE, *PKQUEUE, *RESTRICTED_POINTER PRKQUEUE;
```

| Member | Meaning |
| --- | --- |
| **Header** | Queue header |
| **EntryListHead** | Pointer to the first entry in the queue |
| **CurrentCount** | Number of entries in the queue |
| **MaximumCount** | Maximum number of entries the queue can contain |
| **ThreadListHead** | Pointer to the first entry in the thread list |

### `Entry` [in, out]

Pointer to the queue entry that is to be inserted. This pointer must be a resident system-space address.

## Return value

**KeInsertHeadQueue** returns the previous signal state of the given queue. If it was set to zero (not signaled) before **KeInsertHeadQueue** was called, **KeInsertHeadQueue** returns zero, meaning that no entries were queued. If it was nonzero (signaled), **KeInsertHeadQueue** returns the number of entries that were queued before **KeInsertHeadQueue** was called.

## Remarks

Entries to be queued by **KeInsertHeadQueue** must be allocated from nonpaged pool. For example, memory for caller-defined entries can be allocated with [ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag). If the caller allocates entries of a fixed size, creating a lookaside list with [ExInitializeNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializenpagedlookasidelist) and allocating from it with [ExAllocateFromNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatefromnpagedlookasidelist) is more efficient than making frequent calls to **ExAllocatePoolWithTag**, particularly for entries whose size is not a multiple of PAGE_SIZE.

If any threads are waiting on the queue object when **KeInsertHeadQueue** is called, a single thread's wait is satisfied by this call. The thread is dispatched for execution with the given *Entry* pointer.

If no threads are currently waiting on the queue object when **KeInsertHeadQueue** is called, the given entry is inserted in the queue and the queue object's signal state is incremented.

For more information about using driver-managed internal queues, see [Driver-Managed Queues](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#driver-managed-queues).

## See also

[ExAllocateFromNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatefromnpagedlookasidelist)

[ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag)

[ExInitializeNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializenpagedlookasidelist)

[KeInitializeQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-keinitializequeue)

[KeInsertQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-keinsertqueue)

[KeRemoveQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-keremovequeue)