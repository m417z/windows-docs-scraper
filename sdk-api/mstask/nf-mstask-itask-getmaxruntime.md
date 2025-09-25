# ITask::GetMaxRunTime

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

This method retrieves the maximum length of time, in milliseconds, the [task](https://learn.microsoft.com/windows/desktop/TaskSchd/t) can run before terminating.

## Parameters

### `pdwMaxRunTimeMS` [out]

A pointer to a **DWORD** that contains the maximum run time of the current task.

If the maximum run time is reached during the execution of a task, the Task Scheduler first sends a WM_CLOSE message to the associated application. If the application does not exit within three minutes, **TerminateProcess** is run.

## Return value

The
**GetMaxRunTime** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | The arguments are not valid. |
| **E_OUTOFMEMORY** | Not enough memory is available. |

## See also

[ITask](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-itask)

[SetMaxRunTime](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-itask-setmaxruntime)