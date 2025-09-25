# IScheduledWorkItem::SetComment

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

Sets the comment for the [work item](https://learn.microsoft.com/windows/desktop/TaskSchd/w).

## Parameters

### `pwszComment` [in]

A null-terminated string that specifies the comment for the current work item.

## Return value

The
**SetComment** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | The arguments are not valid. |
| **E_OUTOFMEMORY** | Not enough memory is available. |

## Remarks

After setting the comment of a work item, be sure to call **IPersistFile::Save** to save the modified work item object to disk.

#### Examples

For an example of how to set the comment of a task, see [C/C++ Code Example: Setting Task Comment](https://learn.microsoft.com/windows/desktop/TaskSchd/c-c-code-example-setting-task-comment).

## See also

[IScheduledWorkItem](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ischeduledworkitem)

[IScheduledWorkItem::GetComment](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-getcomment)

[ITask](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-itask)