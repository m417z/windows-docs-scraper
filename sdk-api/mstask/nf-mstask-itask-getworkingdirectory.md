# ITask::GetWorkingDirectory

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

This method retrieves the [task's](https://learn.microsoft.com/windows/desktop/TaskSchd/t)[working directory](https://learn.microsoft.com/windows/desktop/TaskSchd/w).

## Parameters

### `ppwszWorkingDirectory` [in]

A pointer to a null-terminated string that contains the task's working directory. The application that invokes
**GetWorkingDirectory** is responsible for freeing this string using the **CoTaskMemFree** function.

## Return value

The
**GetWorkingDirectory** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | The arguments are not valid. |
| **E_OUTOFMEMORY** | Not enough memory is available. |

## See also

[ITask](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-itask)

[SetWorkingDirectory](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-itask-setworkingdirectory)