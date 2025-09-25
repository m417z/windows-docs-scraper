# IRegisteredTask::GetRunTimes

## Description

Gets the times that the registered task is scheduled to run during a specified time.

## Parameters

### `pstStart` [in]

The starting time for the query.

### `pstEnd` [in]

The ending time for the query.

### `pCount` [in, out]

The requested number of runs on input and the returned number of runs on output.

### `pRunTimes` [out]

The scheduled times that the task will run. A **NULL** LPSYSTEMTIME object should be passed into this parameter. On return, this array contains *pCount* run times. You must free this array by a calling the **CoTaskMemFree** function.

## Return value

If the method succeeds, it returns S_OK. If the method returns S_FALSE, the pRunTimes parameter contains pCount items, but there were more runs of the task, that were not returned. Otherwise, it returns an HRESULT error code.

## Remarks

If the registered task contains triggers that are individually disabled, these triggers will still affect the next scheduled run time that is returned even though they are disabled.

## See also

[IRegisteredTask](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iregisteredtask)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)