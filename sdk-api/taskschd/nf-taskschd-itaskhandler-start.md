# ITaskHandler::Start

## Description

Called to start the COM handler. This method must be implemented by the handler.

## Parameters

### `pHandlerServices` [in]

An **IUnkown** interface that is used to communicate back with the Task Scheduler.

### `data` [in]

The arguments that are required by the handler. These arguments are defined in the [Data](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-icomhandleraction-get_data) property of the COM handler action.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When implementing this method, the handler should return control immediately to the Task Scheduler (starting its own thread if inproc).

After the handler starts its processing, it can call the [UpdateStatus](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-itaskhandlerstatus-updatestatus) method to indicate its percentage of completion or call the [TaskCompleted](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-itaskhandlerstatus-taskcompleted) method to indicate when the handler has completed its processing. These methods are provided by the [ITaskHandlerStatus](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itaskhandlerstatus) interface.

## See also

[Data](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-icomhandleraction-get_data)

[ITaskHandler](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itaskhandler)

[ITaskHandlerStatus](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itaskhandlerstatus)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)

[TaskCompleted](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-itaskhandlerstatus-taskcompleted)

[UpdateStatus](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-itaskhandlerstatus-updatestatus)