# ITask::GetApplicationName

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

This method retrieves the name of the application that the [task](https://learn.microsoft.com/windows/desktop/TaskSchd/t) is associated with.

## Parameters

### `ppwszApplicationName` [out]

A pointer to a null-terminated string that contains the name of the application the current task is associated with. After processing this name, call **CoTaskMemFree** to free resources.

## Return value

The
**GetApplicationName** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | The arguments are not valid. |
| **E_OUTOFMEMORY** | Not enough memory is available. |

## See also

[ITask](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-itask)

[ITask::SetApplicationName](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-itask-setapplicationname)

[SetParameters](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-itask-setparameters)