# ITaskHandler::Stop

## Description

Called to stop the COM handler. This method must be implemented by the handler.

## Parameters

### `pRetCode` [out]

The return code that the Task Schedule will raise as an event when the COM handler action is completed.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITaskHandler](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itaskhandler)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)