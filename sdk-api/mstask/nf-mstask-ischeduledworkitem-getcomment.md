# IScheduledWorkItem::GetComment

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

Retrieves the comment for the [work item](https://learn.microsoft.com/windows/desktop/TaskSchd/w).

## Parameters

### `ppwszComment` [out]

A pointer to a null-terminated string that contains the retrieved comment for the current work item.

## Return value

The
**GetComment** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | The arguments are not valid. |
| **E_OUTOFMEMORY** | Not enough memory is available. |

## See also

[IScheduledWorkItem](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ischeduledworkitem)

[IScheduledWorkItem::SetComment](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-setcomment)