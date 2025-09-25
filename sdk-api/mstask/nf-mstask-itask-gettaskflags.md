# ITask::GetTaskFlags

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

This method returns the flags that modify the behavior of a [task](https://learn.microsoft.com/windows/desktop/TaskSchd/t).

## Parameters

### `pdwFlags` [out]

Currently, there are no defined flags for scheduled tasks.

## Return value

The
**GetTaskFlags** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | The arguments are not valid. |
| **E_OUTOFMEMORY** | Not enough memory is available. |

This method is designed to get the flags that only apply to scheduled tasks. In contrast,
[IScheduledWorkItem::GetFlags](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-getflags) is used to get the flags that apply to all types of scheduled work items.

## See also

[IScheduledWorkItem::GetFlags](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-getflags)

[ITask](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-itask)

[ITask::SetTaskFlags](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-itask-settaskflags)