# IScheduledWorkItem::Run

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

Sends a request to the Task Scheduler service to run the [work item](https://learn.microsoft.com/windows/desktop/TaskSchd/w).

## Return value

The
**Run** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. The request was sent. For more information, see Remarks. |
| **E_INVALIDARG** | The arguments are not valid. |
| **E_OUTOFMEMORY** | Not enough memory is available. |

## Remarks

**Run** is an asynchronous operation. A return code of S_OK means that the request to run the work item has been made; it does not mean that the work item has started running. There may be a delay of a few seconds after
**Run** returns before the work item actually starts running.

To determine whether the work item is running, call
[IScheduledWorkItem::GetStatus](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-getstatus).

#### Examples

For an example of how to start a task, see [Starting a Task Example](https://learn.microsoft.com/windows/desktop/TaskSchd/starting-a-task-example).

## See also

[IScheduledWorkItem](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ischeduledworkitem)

[IScheduledWorkItem::GetStatus](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-getstatus)

[ITask](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-itask)