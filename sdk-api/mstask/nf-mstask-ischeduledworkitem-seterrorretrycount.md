# IScheduledWorkItem::SetErrorRetryCount

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

Sets the number of times Task Scheduler will try to run the [work item](https://learn.microsoft.com/windows/desktop/TaskSchd/w) again if an error occurs. This method is not implemented.

## Parameters

### `wRetryCount`

A value that specifies the number of error retries for the current work item.

## Return value

The
**SetErrorRetryCount** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | The arguments are not valid. |
| **E_OUTOFMEMORY** | Not enough memory is available. |
| **E_NOTIMPL** | Not implemented. |

## Remarks

Programs must call the **IPersistFile::Save** method after calling
**SetErrorRetryCount** to update the error retry count.

## See also

[IScheduledWorkItem](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ischeduledworkitem)

[IScheduledWorkItem::GetErrorRetryCount](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-geterrorretrycount)