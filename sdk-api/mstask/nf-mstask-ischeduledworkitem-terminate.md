# IScheduledWorkItem::Terminate

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

This method ends the execution of the [work item](https://learn.microsoft.com/windows/desktop/TaskSchd/w).

## Return value

The
**Terminate** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | The arguments are not valid. |
| **E_OUTOFMEMORY** | Not enough memory is available. |

## Remarks

The
**Terminate** method operates asynchronously. It does not wait for the task to terminate before returning a return value.

If the WM_CLOSE message cannot be sent (for example, the application has no windows) or the application has not exited within three minutes of the receiving WM_CLOSE, the Task Scheduler terminates the application using **TerminateProcess**.

#### Examples

For an example of how to retrieve the task status and terminate a task, see [Terminating a Task Example](https://learn.microsoft.com/windows/desktop/TaskSchd/terminating-a-task-example).

## See also

[IScheduledWorkItem](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ischeduledworkitem)

[ITask](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-itask)