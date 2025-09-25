# ITask::GetParameters

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

This method retrieves the [task's](https://learn.microsoft.com/windows/desktop/TaskSchd/t) command-line parameters.

## Parameters

### `ppwszParameters` [out]

A pointer to a null-terminated string that contains the command-line parameters for the task. The method that invokes
**GetParameters** is responsible for freeing this string using the **CoTaskMemFree** function.

## Return value

The
**GetParameters** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | The arguments are not valid. |
| **E_OUTOFMEMORY** | Not enough memory is available. |

## See also

[ITask](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-itask)

[SetParameters](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-itask-setparameters)