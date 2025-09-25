# IoFreeWorkItem function

## Description

The **IoFreeWorkItem** routine frees a work item that was allocated by [IoAllocateWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateworkitem).

## Parameters

### `IoWorkItem` [in]

Pointer to an [IO_WORKITEM](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure that was returned by a previous call to [IoAllocateWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateworkitem).

## Remarks

Only free a work item that is not currently queued. The system dequeues a work item before it runs the work item's callback routine, so **IoFreeWorkItem** can be called from within the [WorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_workitem_routine) or [WorkItemEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_workitem_routine_ex) routine for the work item.

For more information about work items, see [System Worker Threads](https://learn.microsoft.com/windows-hardware/drivers/kernel/system-worker-threads).

## See also

[IO_WORKITEM](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[IoAllocateWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateworkitem)