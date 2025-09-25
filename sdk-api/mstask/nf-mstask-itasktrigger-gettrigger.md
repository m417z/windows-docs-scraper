# ITaskTrigger::GetTrigger

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

The
**GetTrigger** method retrieves the current task trigger.

## Parameters

### `pTrigger` [out]

A pointer to a
[TASK_TRIGGER](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-task_trigger) structure that contains the current task trigger. You must set the **cbTriggerSize** member of the
**TASK_TRIGGER** structure to the size of the task trigger structure before passing the structure to this method.

## Return value

The
**GetTrigger** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | The *pTrigger* parameter is not valid. |
| **E_OUTOFMEMORY** | Not enough memory is available. |

## Remarks

A scheduled work item can have one or more triggers defined. The times that the work item will run are the union of all the triggers defined for that item.

## See also

[ITaskTrigger](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-itasktrigger)

[ITaskTrigger::SetTrigger](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-itasktrigger-settrigger)

[TASK_TRIGGER](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-task_trigger)