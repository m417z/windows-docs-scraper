# IScheduledWorkItem::GetWorkItemData

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

Retrieves application-defined data associated with the [work item](https://learn.microsoft.com/windows/desktop/TaskSchd/w).

## Parameters

### `pcbData` [out]

A pointer to the number of bytes copied.

### `prgbData` [out]

A pointer to a pointer to a BYTE that contains user-defined data for the current work item. The method that invokes
**GetWorkItemData** is responsible for freeing this memory by using [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

## Return value

The
**GetWorkItemData** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | The arguments are not valid. |
| **E_OUTOFMEMORY** | Not enough memory is available. |

## Remarks

Retrieving the data of a work item does not affect the operation of the work item in any way.

## See also

[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree)

[IScheduledWorkItem](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ischeduledworkitem)

[SetWorkItemData](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-setworkitemdata)