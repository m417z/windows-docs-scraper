# IScheduledWorkItem::GetTrigger

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

Retrieves a task [trigger](https://learn.microsoft.com/windows/desktop/TaskSchd/t).

## Parameters

### `iTrigger` [in]

The index of the trigger to retrieve.

### `ppTrigger` [out]

A pointer to a pointer to an
[ITaskTrigger](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-itasktrigger) interface for the retrieved trigger.

## Return value

The
**GetTrigger** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | The arguments are not valid. |
| **E_OUTOFMEMORY** | Not enough memory is available. |

## See also

[IScheduledWorkItem](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ischeduledworkitem)

[ITaskTrigger](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-itasktrigger)