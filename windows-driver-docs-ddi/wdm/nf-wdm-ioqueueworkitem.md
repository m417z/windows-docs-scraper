# IoQueueWorkItem function

## Description

The **IoQueueWorkItem** routine associates a [WorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_workitem_routine) routine with a work item, and it inserts the work item into a queue for later processing by a system worker thread.

## Parameters

### `IoWorkItem` [in]

Pointer to an [IO_WORKITEM](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure that was allocated by [IoAllocateWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateworkitem) or initialized by [IoInitializeWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioinitializeworkitem).

### `WorkerRoutine` [in]

Pointer to a [WorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_workitem_routine) routine.

### `QueueType` [in]

Specifies a [WORK_QUEUE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_work_queue_type) value that stipulates the type of system worker thread to handle the work item. Drivers must specify **DelayedWorkQueue**.

### `Context` [in, optional]

Specifies driver-specific information for the work item. The system passes this value as the *Context* parameter to [WorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_workitem_routine).

## Remarks

For more information about work items, see [System Worker Threads](https://learn.microsoft.com/windows-hardware/drivers/kernel/system-worker-threads).

## See also

[IO_WORKITEM](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[IoAllocateWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateworkitem)

[IoQueueWorkItemEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioqueueworkitemex)

[WorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_workitem_routine)