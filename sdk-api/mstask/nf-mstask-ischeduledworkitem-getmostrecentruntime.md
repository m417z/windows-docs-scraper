# IScheduledWorkItem::GetMostRecentRunTime

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

Retrieves the most recent time the [work item](https://learn.microsoft.com/windows/desktop/TaskSchd/w) began running.

## Parameters

### `pstLastRun` [out]

A pointer to a **SYSTEMTIME** structure that contains the most recent time the current work item ran.

## Return value

The
**GetMostRecentRunTime** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | The arguments are not valid. |
| **E_OUTOFMEMORY** | Not enough memory is available. |
| **SCHED_S_TASK_HAS_NOT_RUN** | The work item has never run. |

## See also

[GetNextRunTime](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-getnextruntime)

[IScheduledWorkItem](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ischeduledworkitem)