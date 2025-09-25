# IoUninitializeWorkItem function

## Description

The **IoUninitializeWorkItem** routine uninitializes a work item that was initialized by [IoInitializeWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioinitializeworkitem).

## Parameters

### `IoWorkItem` [in]

Pointer to the [IO_WORKITEM](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure to uninitialize.

## Remarks

Only uninitialize a work item that is not currently queued. The system dequeues a work item before it runs the work item's callback routine, so **IoUninitializeWorkItem** can be called from within the [WorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_workitem_routine) or [WorkItemEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_workitem_routine_ex) routine for the work item.

For more information about work items, see [System Worker Threads](https://learn.microsoft.com/windows-hardware/drivers/kernel/system-worker-threads).

## See also

[IO_WORKITEM](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[IoInitializeWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioinitializeworkitem)