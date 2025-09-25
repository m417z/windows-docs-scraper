# IScheduledWorkItem::GetRunTimes

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

Retrieves the [work item](https://learn.microsoft.com/windows/desktop/TaskSchd/w) run times for a specified time period.

## Parameters

### `pstBegin` [in]

A pointer to a **SYSTEMTIME** structure that contains the starting time of the time period to check. This value is inclusive.

### `pstEnd` [in]

A pointer to a **SYSTEMTIME** structure that contains the ending time of the time period to check. This value is exclusive. If **NULL** is passed for this value, the end time is infinite.

### `pCount` [in, out]

A pointer to a **WORD** value that specifies the number of run times to retrieve.

On input, this parameter contains the number of run times being requested. This can be a number of between 1 and TASK_MAX_RUN_TIMES.

On output, this parameter contains the number of run times retrieved.

### `rgstTaskTimes` [out]

A pointer to an array of **SYSTEMTIME** structures. A **NULL** LPSYSTEMTIME object should be passed into this parameter. On return, this array contains *pCount* run times. You must free this array by a calling the **CoTaskMemFree** function.

## Return value

The
**GetRunTimes** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The requested number of run times was retrieved. |
| **S_FALSE** | The method succeeded, but fewer than the requested number of run times were retrieved. The number of run times retrieved is contained in the value pointed to by *pCount*. If the number of run times retrieved is zero, there are also no event-based triggers that can cause the work item to be executed during the specified time period. |
| **SCHED_S_TASK_NO_VALID_TRIGGERS** | The work item is enabled but has no valid triggers. |
| **SCHED_S_TASK_DISABLED** | The work item is disabled. |
| **E_INVALIDARG** | One or more of the arguments are invalid. |
| **E_OUTOFMEMORY** | There is insufficient memory to compute the result. |

## See also

[IScheduledWorkItem](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ischeduledworkitem)