# IScheduledWorkItem::SetCreator

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

Sets the name of the [work item's](https://learn.microsoft.com/windows/desktop/TaskSchd/w) creator.

## Parameters

### `pwszCreator`

A null-terminated string that contains the name of the work item's creator.

## Return value

The
**SetCreator** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | The arguments are not valid. |
| **E_OUTOFMEMORY** | Not enough memory is available. |

## Remarks

Programs must call the **IPersistFile::Save** method after calling **SetCreator** to update the creator.

## See also

[IScheduledWorkItem](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ischeduledworkitem)

[IScheduledWorkItem::GetCreator](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-getcreator)