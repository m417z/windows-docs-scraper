# IScheduledWorkItem::EditWorkItem

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

Displays the Task, Schedule, and settings property pages for the [work item](https://learn.microsoft.com/windows/desktop/TaskSchd/w), allowing a user set the properties on those pages.

## Parameters

### `hParent` [in]

Reserved for future use. Set this parameter to **NULL**.

### `dwReserved` [in]

Reserved for internal use; this parameter must be set to zero.

## Return value

The
**EditWorkItem** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **STG_E_NOTFILEBASEDSTORAGE** | The work item object is not persistent. |
| **E_INVALIDARG** | The arguments are not valid. |
| **E_OUTOFMEMORY** | Not enough memory is available. |

## See also

[IScheduledWorkItem](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ischeduledworkitem)