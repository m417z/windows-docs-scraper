# ITaskHandlerStatus::TaskCompleted

## Description

Tells the Task Scheduler that the COM handler is completed.

## Parameters

### `taskErrCode` [in]

The error code that the Task Scheduler will raise as an event.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITaskHandlerStatus](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itaskhandlerstatus)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)