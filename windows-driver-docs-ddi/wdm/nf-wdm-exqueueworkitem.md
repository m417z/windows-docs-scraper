## Description

**ExQueueWorkItem** inserts a given work item into a queue from which a system worker thread removes the item and gives control to the routine that the caller supplied to [ExInitializeWorkItem](https://learn.microsoft.com/windows-hardware/drivers/kernel/mmcreatemdl).

> [!WARNING]
> Use this routine with extreme caution. See the **Remarks** section below.

## Parameters

### `WorkItem` [in, out]

Pointer to the work item. This work item must have been initialized by a preceding call to [ExInitializeWorkItem](https://learn.microsoft.com/windows-hardware/drivers/kernel/mmcreatemdl).

### `QueueType` [in]

Specifies the queue into which the work item pointed to by *WorkItem* is to be inserted. *QueueType* can be either of the following:

| Value | Meaning |
|---|---|
| **CriticalWorkQueue** | Insert the *WorkItem* into the queue from which a system thread with a real-time priority attribute will process the work item. |
| **DelayedWorkQueue** | Insert the *WorkItem* into the queue from which a system thread with a variable priority attribute will process the work item. |

The *QueueType* value **HyperCriticalWorkQueue** is reserved for system use.

## Remarks

Device drivers must use [IoQueueWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioqueueworkitem) instead of **ExQueueWorkItem**. Drivers should use **ExQueueWorkItem**, and the associated [ExInitializeWorkItem](https://learn.microsoft.com/windows-hardware/drivers/kernel/mmcreatemdl), only in cases where the specified work item is not associated with a device object or device stack. In all other cases, drivers should use [IoAllocateWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateworkitem), [IoFreeWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iofreeworkitem), and **IoQueueWorkItem** because only these routines ensure that the device object associated with the specified work item remains available until the work item has been processed.

The callback routine that was specified in the *Routine* parameter to [ExInitializeWorkItem](https://learn.microsoft.com/windows-hardware/drivers/kernel/mmcreatemdl) is called in a system context at IRQL PASSIVE_LEVEL. This caller-supplied routine is responsible for freeing the work item when it is no longer needed by calling [ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exfreepool) or [ExFreePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exfreepoolwithtag).

System worker threads are a limited resource. Drivers must not permanently reserve a work item for the driver's use. Work items are designed for operations that complete quickly. Drivers should free any work items that they allocate as soon as possible.

A driver must not wait for its callback routine to complete an operation if it is already holding one synchronization object and might attempt to acquire another. To prevent deadlock, a driver should release any currently held semaphores, mutexes, resource variables, and so forth before it calls **ExQueueWorkItem**.

The value of *QueueType* determines the runtime priority at which the callback routine is run, as follows:

- If the callback runs in the system thread with a real-time priority attribute, the callback routine cannot be preempted except by threads with higher real-time priorities.

- If the callback runs in the system thread with a variable priority attribute, the callback can be preempted by threads with higher variable and real-time priorities, and the callback is scheduled to run round-robin with other threads of the same priority for a quantum each.

Threads at either priority remain interruptible.

## See also

[ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exfreepool)

[ExFreePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exfreepoolwithtag)

[ExInitializeWorkItem](https://learn.microsoft.com/windows-hardware/drivers/kernel/mmcreatemdl)

[IoAllocateWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateworkitem)

[IoFreeWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iofreeworkitem)

[IoQueueWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioqueueworkitem)

[WORK_QUEUE_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_work_queue_item)