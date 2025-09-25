# ITriggerCollection::Create

## Description

Creates a new trigger for the task.

## Parameters

### `type` [in]

This parameter is set to one of the following [TASK_TRIGGER_TYPE2](https://learn.microsoft.com/windows/desktop/api/taskschd/ne-taskschd-task_trigger_type2) enumeration constants.

| Value | Meaning |
| --- | --- |
| **TASK_TRIGGER_EVENT**<br><br>0 | Triggers the task when a specific event occurs. |
| **TASK_TRIGGER_TIME**<br><br>1 | Triggers the task at a specific time of day. |
| **TASK_TRIGGER_DAILY**<br><br>2 | Triggers the task on a daily schedule. For example, the task starts at a specific time every day, every-other day, every third day, and so on. |
| **TASK_TRIGGER_WEEKLY**<br><br>3 | Triggers the task on a weekly schedule. For example, the task starts at 8:00 AM on a specific day every week or other week. |
| **TASK_TRIGGER_MONTHLY**<br><br>4 | Triggers the task on a monthly schedule. For example, the task starts on specific days of specific months. |
| **TASK_TRIGGER_MONTHLYDOW**<br><br>5 | Triggers the task on a monthly day-of-week schedule. For example, the task starts on a specific days of the week, weeks of the month, and months of the year. |
| **TASK_TRIGGER_IDLE**<br><br>6 | Triggers the task when the computer goes into an idle state. |
| **TASK_TRIGGER_REGISTRATION**<br><br>7 | Triggers the task when the task is registered. |
| **TASK_TRIGGER_BOOT**<br><br>8 | Triggers the task when the computer boots. |
| **TASK_TRIGGER_LOGON**<br><br>9 | Triggers the task when a specific user logs on. |
| **TASK_TRIGGER_SESSION_STATE_CHANGE**<br><br>11 | Triggers the task when a specific session state changes. |

### `ppTrigger` [out]

An [ITrigger](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itrigger) interface that represents the new trigger.

Pass in a reference to a **NULL** [ITrigger](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itrigger) interface pointer. Referencing a non-**NULL** pointer can cause a memory leak because the pointer will be overwritten.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITriggerCollection](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itriggercollection)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)