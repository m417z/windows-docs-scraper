# KeInitializeQueue function

## Description

The **KeInitializeQueue** routine initializes a queue object on which threads can wait for entries.

## Parameters

### `Queue` [out]

Pointer to a KQUEUE structure for which the caller must provide resident storage in nonpaged pool. This structure is defined as follows:

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
| **Header** | Queue header. |
| **EntryListHead** | Pointer to the first entry in the queue. |
| **CurrentCount** | Current number of threads waiting on the queue. |
| **MaximumCount** | Maximum number of concurrent threads the queue can satisfy waits for. |
| **ThreadListHead** | Pointer to the first entry in the thread list. |

### `Count` [in]

The maximum number of threads for which the waits on the queue object can be satisfied concurrently. If this parameter is not supplied, the number of processors in the machine is used.

## Remarks

Usually the caller of **KeInitializeQueue** also creates a set of dedicated threads to queue and dequeue its entries. Such a caller can specify an explicit *Count* to prevent too many of its dedicated threads from waiting concurrently on its queue object.

**KeInitializeQueue** sets the queue object's initial signal state to Not Signaled.

For more information about using driver-managed internal queues, see [Driver-Managed IRP Queues](https://learn.microsoft.com/windows-hardware/drivers/kernel/driver-managed-irp-queues).

## See also

[ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag)

[IoAllocateWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateworkitem)

[IoQueueWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioqueueworkitem)

[KeInsertQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-keinsertqueue)

[KeRemoveQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-keremovequeue)

[KeRundownQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-kerundownqueue)

[PsCreateSystemThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pscreatesystemthread)