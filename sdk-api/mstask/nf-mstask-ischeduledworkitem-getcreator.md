# IScheduledWorkItem::GetCreator

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

Retrieves the name of the creator of the [work item](https://learn.microsoft.com/windows/desktop/TaskSchd/w).

## Parameters

### `ppwszCreator` [out]

A pointer to a null-terminated string that contains the name of the creator of the current work item. The application that invokes
**GetCreator** is responsible for freeing this string using the **CoTaskMemFree** function.

## Return value

The
**GetCreator** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | The arguments are not valid. |
| **E_OUTOFMEMORY** | Not enough memory is available. |

## See also

[IScheduledWorkItem](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ischeduledworkitem)

[IScheduledWorkItem::SetCreator](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-setcreator)