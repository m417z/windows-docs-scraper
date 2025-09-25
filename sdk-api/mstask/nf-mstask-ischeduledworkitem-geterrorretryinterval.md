# IScheduledWorkItem::GetErrorRetryInterval

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

 Retrieves the time interval, in minutes, between Task Scheduler's attempts to run a work item if an error occurs. This method is not implemented.

## Parameters

### `pwRetryInterval` [out]

A pointer to a **WORD** value that contains the time interval between retries of the current work item.

## Return value

The
**GetErrorRetryInterval** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | The arguments are not valid. |
| **E_OUTOFMEMORY** | Not enough memory is available. |
| **E_NOTIMPL** | Not implemented. |

## See also

[IScheduledWorkItem](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ischeduledworkitem)

[SetErrorRetryInterval](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-seterrorretryinterval)