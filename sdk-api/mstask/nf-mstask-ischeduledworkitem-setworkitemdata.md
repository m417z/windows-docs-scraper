# IScheduledWorkItem::SetWorkItemData

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

This method stores application-defined data associated with the [work item](https://learn.microsoft.com/windows/desktop/TaskSchd/w).

## Parameters

### `cbData` [in]

The number of bytes in the data buffer. The caller allocates and frees this memory.

### `rgbData` [in]

The data to copy.

## Return value

The
**SetWorkItemData** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | The arguments are not valid. |
| **E_OUTOFMEMORY** | Not enough memory is available. |

## Remarks

You can retrieve data by calling
[IScheduledWorkItem::GetWorkItemData](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-getworkitemdata).

Programs must call the **IPersistFile::Save** method after calling
**SetWorkItemData** to update the work item data.

## See also

[IScheduledWorkItem](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ischeduledworkitem)

[IScheduledWorkItem::GetWorkItemData](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-getworkitemdata)