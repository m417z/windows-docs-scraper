# IScheduledWorkItem::GetTriggerString

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

 Retrieves a string that describes the [work item](https://learn.microsoft.com/windows/desktop/TaskSchd/w) trigger.

## Parameters

### `iTrigger` [in]

The index of the trigger to be retrieved. The first trigger is always referenced by 0. For more information, see Remarks.

### `ppwszTrigger` [out]

A pointer to a null-terminated string that contains the retrieved trigger description. Note that this string must be release by a call to **CoTaskMemFree** after the string is no longer needed.

## Return value

The
**GetTriggerString** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | The arguments are not valid. |
| **E_OUTOFMEMORY** | Not enough memory is available. |

## Remarks

A trigger index is not an identifier. It only indicates the trigger's position relative to the current triggers associated with the work item. For example, if you create four triggers, they will be numbered 0 through 3. But if the second trigger is deleted, the remaining triggers will be numbered 0 through 2. Note that the index of the first trigger is always 0, and the index of the last trigger is one less than the total number of triggers for the work item (TriggerCount -1).

You can retrieve the trigger count using
[IScheduledWorkItem::GetTriggerCount](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-gettriggercount).

#### Examples

For an example of how to retrieve the trigger string of all triggers associated with a task, see [Retrieving Trigger Strings Example](https://learn.microsoft.com/windows/desktop/TaskSchd/retrieving-trigger-strings-example).

## See also

[IScheduledWorkItem](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ischeduledworkitem)

[ITask](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-itask)