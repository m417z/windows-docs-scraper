# ITaskScheduler::GetTargetComputer

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

The
**GetTargetComputer** method returns the name of the computer on which
[ITaskScheduler](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-itaskscheduler) is currently targeted.

## Parameters

### `ppwszComputer` [out]

A pointer to a null-terminated string that contains the name of the target computer for the current task. This string is allocated by the application that invokes
**GetTargetComputer**, and must also be freed using **CoTaskMemFree**.

## Return value

The
**GetTargetComputer** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | The arguments are not valid. |
| **E_OUTOFMEMORY** | Not enough memory is available. |

## See also

[ITaskScheduler](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-itaskscheduler)