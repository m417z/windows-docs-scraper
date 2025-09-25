# ITask::SetMaxRunTime

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

This method sets the maximum time the [task](https://learn.microsoft.com/windows/desktop/TaskSchd/t) can run, in milliseconds, before terminating.

## Parameters

### `dwMaxRunTimeMS` [in]

A **DWORD** value that specifies the maximum run time (in milliseconds), for the task. This parameter may be set to INFINITE to specify an unlimited time.

## Return value

The
**SetMaxRunTime** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | The arguments are not valid. |
| **E_OUTOFMEMORY** | Not enough memory is available. |

## Remarks

When the maximum run time is exceeded, the Task Scheduler attempts to terminate the application associated with the task. If a WM_CLOSE message cannot be sent (for example, the application has no windows) or the application has not exited within three minutes of the receiving WM_CLOSE, the Task Scheduler terminates the application using **TerminateProcess**.

After setting the maximum run time, be sure to call **IPersistFile::Save** to save the modified task object to disk.

#### Examples

For an example of how to set the maximum run time, see [C/C++ Code Example: Setting MaxRunTime](https://learn.microsoft.com/windows/desktop/TaskSchd/c-c-code-example-setting-maxruntime).

## See also

[IGetMaxRunTime](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-itask-getmaxruntime)

[ITask](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-itask)