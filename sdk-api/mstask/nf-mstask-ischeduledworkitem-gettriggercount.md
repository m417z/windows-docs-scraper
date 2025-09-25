# IScheduledWorkItem::GetTriggerCount

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

Retrieves the number of [triggers](https://learn.microsoft.com/windows/desktop/TaskSchd/t) for the current [work item](https://learn.microsoft.com/windows/desktop/TaskSchd/w).

## Parameters

### `pwCount` [out]

A pointer to a **WORD** that will contain the number of triggers associated with the work item.

## Return value

The
**GetTriggerCount** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | The arguments are not valid. |
| **E_OUTOFMEMORY** | Not enough memory is available. |

## See also

[IScheduledWorkItem](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ischeduledworkitem)

[ITask](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-itask)