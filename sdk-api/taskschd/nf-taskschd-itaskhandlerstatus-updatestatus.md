# ITaskHandlerStatus::UpdateStatus

## Description

Tells the Task Scheduler about the percentage of completion of the COM handler.

## Parameters

### `percentComplete` [in]

A value that indicates the percentage of completion for the COM handler.

### `statusMessage` [in]

The message that is displayed in the Task Scheduler UI.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITaskHandlerStatus](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itaskhandlerstatus)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)