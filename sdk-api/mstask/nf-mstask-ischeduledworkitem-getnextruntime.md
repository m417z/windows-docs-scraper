# IScheduledWorkItem::GetNextRunTime

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

Retrieves the next time the [work item](https://learn.microsoft.com/windows/desktop/TaskSchd/w) will run.

## Parameters

### `pstNextRun` [out]

A pointer to a **SYSTEMTIME** structure that contains the next time the work item will run.

## Return value

The
**GetNextRunTime** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | The arguments are not valid. |
| **E_OUTOFMEMORY** | Not enough memory is available. |
| **SCHED_S_TASK_DISABLED** | The task will not run at the scheduled times because it has been disabled. |

## See also

[IScheduledWorkItem](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ischeduledworkitem)