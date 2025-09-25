# IScheduledWorkItem::GetFlags

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

Retrieves the flags that modify the behavior of any type of [work item](https://learn.microsoft.com/windows/desktop/TaskSchd/w).

## Parameters

### `pdwFlags` [out]

A pointer to a **DWORD** that contains the flags for the work item. For a list of these flags, see
[SetFlags](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-setflags).

## Return value

The
**GetFlags** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | The arguments are not valid. |
| **E_OUTOFMEMORY** | Not enough memory is available. |

## Remarks

This method is used to get those flags used by any type of scheduled work item. In contrast,
[ITask::GetTaskFlags](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-itask-gettaskflags) is used only to get flags used by scheduled tasks.

## See also

[IScheduledWorkItem](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ischeduledworkitem)

[IScheduledWorkItem::SetFlags](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-setflags)

[ITask::GetTaskFlags](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-itask-gettaskflags)