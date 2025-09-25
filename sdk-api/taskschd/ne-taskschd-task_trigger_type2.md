# TASK_TRIGGER_TYPE2 enumeration

## Description

Defines the type of triggers that can be used by tasks.

## Constants

### `TASK_TRIGGER_EVENT:0`

Triggers the task when a specific event occurs. For more information about event triggers, see [IEventTrigger](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-ieventtrigger).

### `TASK_TRIGGER_TIME:1`

Triggers the task at a specific time of day. For more information about time triggers, see [ITimeTrigger](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itimetrigger).

### `TASK_TRIGGER_DAILY:2`

Triggers the task on a daily schedule. For example, the task starts at a specific time every day, every other day, or every third day. For more information about daily triggers, see [IDailyTrigger](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-idailytrigger).

### `TASK_TRIGGER_WEEKLY:3`

Triggers the task on a weekly schedule. For example, the task starts at 8:00 AM on a specific day every week or other week. For more information about weekly triggers, see [IWeeklyTrigger](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iweeklytrigger).

### `TASK_TRIGGER_MONTHLY:4`

Triggers the task on a monthly schedule. For example, the task starts on specific days of specific months. For more information about monthly triggers, see [IMonthlyTrigger](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-imonthlytrigger).

### `TASK_TRIGGER_MONTHLYDOW:5`

Triggers the task on a monthly day-of-week schedule. For example, the task starts on a specific days of the week, weeks of the month, and months of the year. For more information about monthly day-of-week triggers, see [IMonthlyDOWTrigger](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-imonthlydowtrigger).

### `TASK_TRIGGER_IDLE:6`

Triggers the task when the computer goes into an idle state. For more information about idle triggers, see [IIdleTrigger](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iidletrigger).

### `TASK_TRIGGER_REGISTRATION:7`

Triggers the task when the task is registered. For more information about registration triggers, see [IRegistrationTrigger](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iregistrationtrigger).

### `TASK_TRIGGER_BOOT:8`

Triggers the task when the computer boots. For more information about boot triggers, see [IBootTrigger](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iboottrigger).

### `TASK_TRIGGER_LOGON:9`

Triggers the task when a specific user logs on. For more information about logon triggers, see [ILogonTrigger](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-ilogontrigger).

### `TASK_TRIGGER_SESSION_STATE_CHANGE:11`

Triggers the task when a specific user session state changes. For more information about session state change triggers, see [ISessionStateChangeTrigger](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-isessionstatechangetrigger).

### `TASK_TRIGGER_CUSTOM_TRIGGER_01:12`

## See also

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)

[Task Scheduler Enumerated Types](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-enumerated-types)