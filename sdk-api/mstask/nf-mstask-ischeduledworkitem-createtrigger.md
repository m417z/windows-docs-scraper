# IScheduledWorkItem::CreateTrigger

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

Creates a trigger for the [work item](https://learn.microsoft.com/windows/desktop/TaskSchd/w).

## Parameters

### `piNewTrigger` [out]

A pointer to the returned trigger index value of the new trigger. The trigger index for the first trigger associated with a work item is "0". See Remarks for other uses of the trigger index.

### `ppTrigger` [out]

A pointer to a pointer to an
[ITaskTrigger](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-itasktrigger) interface. Currently, the only supported work items are [tasks](https://learn.microsoft.com/windows/desktop/TaskSchd/t).

## Return value

The
**CreateTrigger** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | The arguments are not valid. |
| **E_OUTOFMEMORY** | Not enough memory is available. |

## Remarks

You use the trigger index returned by *piNewTrigger* when you are either retrieving or deleting triggers. However, the trigger index is not an identifier. It indicates only the new trigger's position relative to the other current triggers associated with the work item.

To set the criteria for the new trigger, call
[ITaskTrigger::SetTrigger](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-itasktrigger-settrigger).

After creating a new trigger for a work item, applications must call the
[IPersistFile::Save](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersistfile-save) method to save the new trigger to disk.

#### Examples

For an example of how to set the trigger criteria when creating a new trigger, see [Creating a New Trigger](https://learn.microsoft.com/windows/desktop/TaskSchd/creating-a-new-trigger).

## See also

[IPersistFile::Save](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersistfile-save)

[IScheduledWorkItem](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ischeduledworkitem)

[IScheduledWorkItem::DeleteTrigger](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-deletetrigger)

[IScheduledWorkItem::GetTrigger](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-gettrigger)

[IScheduledWorkItem::GetTriggerString](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-gettriggerstring)

[ITaskTrigger](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-itasktrigger)

[ITaskTrigger::SetTrigger](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-itasktrigger-settrigger)