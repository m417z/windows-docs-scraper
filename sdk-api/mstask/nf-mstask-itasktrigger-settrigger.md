# ITaskTrigger::SetTrigger

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

The
**SetTrigger** method sets the trigger criteria for a task [trigger](https://learn.microsoft.com/windows/desktop/TaskSchd/t).

## Parameters

### `pTrigger` [in]

A pointer to a
[TASK_TRIGGER](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-task_trigger) structure that contains the values that define the new task trigger.

## Return value

The
**SetTrigger** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | The arguments are not valid. |
| **E_OUTOFMEMORY** | Not enough memory is available. |

## Remarks

The **wBeginDay**, **wBeginMonth**, and **wBeginYear** members of the
[TASK_TRIGGER](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-task_trigger) structure must be set to a valid day, month, and year respectively.

A task can have any number of triggers associated with it. The times that the task will run are the union of all the triggers defined for that task.

To update the task with these new trigger settings, applications must call the
[IPersistFile::Save](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersistfile-save) method after calling
**SetTrigger**.

#### Examples

The following code shows the variable declaration and calling syntax for this method, including the required members of
[TASK_TRIGGER](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-task_trigger). Setting the trigger criteria when creating a new trigger, see [Creating a New Trigger](https://learn.microsoft.com/windows/desktop/TaskSchd/creating-a-new-trigger).

```cpp
HRESULT hr = S_OK;

TASK_TRIGGER Trigger;

ZeroMemory(&Trigger, sizeof(TASK_TRIGGER));

Trigger.cbTriggerSize = sizeof(TASK_TRIGGER);
Trigger.wBeginDay = 1;
Trigger.wBeginMonth = 1;
Trigger.wBeginYear = 1999;

// pITaskTrigger is a previously assigned ITaskTrigger pointer.
hr = pITaskTrigger->SetTrigger(&Trigger);
if (FAILED(hr))
{
   printf("Failed SetTrigger\n");
   exit(1);
}

```

## See also

[IPersistFile::Save](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersistfile-save)

[ITaskTrigger](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-itasktrigger)

[ITaskTrigger::GetTrigger](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-itasktrigger-gettrigger)

[TASK_TRIGGER](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-task_trigger)