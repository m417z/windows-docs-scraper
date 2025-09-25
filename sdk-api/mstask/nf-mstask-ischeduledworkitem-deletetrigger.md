# IScheduledWorkItem::DeleteTrigger

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

Deletes a trigger from a [work item](https://learn.microsoft.com/windows/desktop/TaskSchd/w).

## Parameters

### `iTrigger` [in]

A trigger index value that specifies the trigger to be deleted. For more information, see Remarks.

## Return value

The
**DeleteTrigger** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | The arguments are not valid. |
| **E_OUTOFMEMORY** | Not enough memory is available. |

## Remarks

A trigger index is created for each trigger when the trigger is created. However, it is not a unique identifier for a specific trigger. For example, if you create four triggers, they will be numbered 0 through 3. But if the second trigger is deleted, the remaining triggers will be numbered 0 through 2. Note that the index of the first trigger is always 0, and the index of the last trigger is one less than the total number of triggers for the work item (TriggerCount -1).

You can retrieve the trigger count using
[IScheduledWorkItem::GetTriggerCount](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-gettriggercount).

To complete the deletion of the trigger, programs must call the **IPersistFile::Save** method after calling
**DeleteTrigger**. Calling **IPersistFile::Save** saves the changes to disk.

## See also

[CreateTrigger](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-createtrigger)

[IScheduledWorkItem](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ischeduledworkitem)

[IScheduledWorkItem::GetTriggerCount](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-gettriggercount)