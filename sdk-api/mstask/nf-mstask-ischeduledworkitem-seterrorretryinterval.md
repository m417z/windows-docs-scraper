# IScheduledWorkItem::SetErrorRetryInterval

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

Sets the time interval, in minutes, between Task Scheduler's attempts to run a [work item](https://learn.microsoft.com/windows/desktop/TaskSchd/w) after an error occurs. This method is not implemented.

## Parameters

### `wRetryInterval`

A value that specifies the interval between error retries for the current work item, in minutes.

## Return value

The
**SetErrorRetryInterval** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | The arguments are not valid. |
| **E_OUTOFMEMORY** | Not enough memory is available. |
| **E_NOTIMPL** | Not implemented. |

## Remarks

Programs must call the **IPersistFile::Save** method after calling
**SetErrorRetryInterval** to update the error retry interval.

## See also

[IScheduledWorkItem](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ischeduledworkitem)

[IScheduledWorkItem::GetErrorRetryInterval](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-geterrorretryinterval)