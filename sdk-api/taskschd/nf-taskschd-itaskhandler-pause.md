# ITaskHandler::Pause

## Description

Called to pause the COM handler. This method is optional and should only be implemented to give the Task Scheduler the ability to pause and restart the handler.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITaskHandler](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itaskhandler)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)