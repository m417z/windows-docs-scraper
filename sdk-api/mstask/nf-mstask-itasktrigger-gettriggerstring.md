# ITaskTrigger::GetTriggerString

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

The
**GetTriggerString** method retrieves the current task trigger in the form of a string. This string appears in the Task Scheduler user interface in a form similar to "At 2PM every day, starting 5/11/97."

## Parameters

### `ppwszTrigger` [out]

A pointer to a pointer to a null-terminated string that describes the current task trigger. The method that invokes
**GetTriggerString** is responsible for freeing this string using the **CoTaskMemFree** function.

## Return value

The
**GetTriggerString** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | The arguments are not valid. |
| **E_OUTOFMEMORY** | Not enough memory is available. |

## See also

[ITaskTrigger](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-itasktrigger)

[ITaskTrigger::GetTrigger](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-itasktrigger-gettrigger)

[ITaskTrigger::SetTrigger](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-itasktrigger-settrigger)