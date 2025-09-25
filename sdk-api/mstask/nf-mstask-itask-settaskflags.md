# ITask::SetTaskFlags

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

This method sets the flags that modify the behavior of a scheduled [task](https://learn.microsoft.com/windows/desktop/TaskSchd/t).

## Parameters

### `dwFlags` [in]

Currently, there are no flags defined for scheduled tasks.

## Return value

The
**SetTaskFlags** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | The arguments are not valid. |
| **E_OUTOFMEMORY** | Not enough memory is available. |

## Remarks

Applications must call the **IPersistFile::Save** method after calling
**SetTaskFlags** to update the task flags.

This method is designed to set the flags that only apply to scheduled tasks. In contrast,
[IScheduledWorkItem::SetFlags](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-setflags) is used to set the flags that apply to all types of scheduled work items.

## See also

[GetTaskFlags](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-itask-gettaskflags)

[IScheduledWorkItem::SetFlags](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-setflags)

[ITask](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-itask)