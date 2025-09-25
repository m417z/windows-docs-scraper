## Description

The **WORK_QUEUE_ITEM** structure is used to post a work items to a system work queue.

> [!WARNING]
> Use this structure with extreme caution. See the following **Remarks** section.

## Members

### `List`

Doubly linked list structure. This structure is used to add the work item to the system work queue.

### `WorkerRoutine`

Pointer to a callback routine that processes this work item when the work item is dequeued. This callback routine is declared as follows:

```cpp
VOID
(*PWORKER_THREAD_ROUTINE)(
    IN PVOID Parameter
    );
```

#### Parameter

Context information pointer specified in the **Parameter** member.

### `Parameter`

Pointer to context information to be passed to the callback routine specified in the **WorkerRoutine** member.

## Remarks

To initialize a WORK_QUEUE_ITEM structure, call [ExInitializeWorkItem](https://learn.microsoft.com/windows-hardware/drivers/kernel/mmcreatemdl).

To post the initialized work item to a system work queue, call [ExQueueWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exqueueworkitem).

ExInitializeWorkItem and ExQueueWorkItem can only be used in cases where the specified work item is not associated with any device object or device stack. In all other cases, drivers should use [IoAllocateWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateworkitem), [IoFreeWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iofreeworkitem), and [IoQueueWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioqueueworkitem), because only these routines ensure that the device object associated with the specified work item remains available until the work item has been processed.

## See also

[ExInitializeWorkItem](https://learn.microsoft.com/windows-hardware/drivers/kernel/mmcreatemdl)

[ExQueueWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exqueueworkitem)

[IoAllocateWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateworkitem)

[IoFreeWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iofreeworkitem)

[IoQueueWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioqueueworkitem)