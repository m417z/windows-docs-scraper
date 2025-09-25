# TASK_TRIGGER_TYPE enumeration

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Enumerated Types](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-enumerated-types) instead.] ]

Defines the types of [triggers](https://learn.microsoft.com/windows/desktop/TaskSchd/t) associated with a task.

## Constants

### `TASK_TIME_TRIGGER_ONCE:0`

Trigger is set to run the task a single time.

When this value is specified, the **Type** member of the
[TASK_TRIGGER](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-task_trigger) structure is ignored.

### `TASK_TIME_TRIGGER_DAILY:1`

Trigger is set to run the task on a daily interval.

When this value is specified, the
**DAILY** member of the
[TRIGGER_TYPE_UNION](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-trigger_type_union) structure is used.

### `TASK_TIME_TRIGGER_WEEKLY:2`

Trigger is set to run the work item on specific days of a specific week of a specific month.

When this value is specified, the
**WEEKLY** member of the
[TRIGGER_TYPE_UNION](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-trigger_type_union) structure is used.

### `TASK_TIME_TRIGGER_MONTHLYDATE:3`

Trigger is set to run the task on a specific day(s) of the month.

When this value is specified, the
**MONTHLYDATE** member of the
[TRIGGER_TYPE_UNION](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-trigger_type_union) structure is used.

### `TASK_TIME_TRIGGER_MONTHLYDOW:4`

Trigger is set to run the task on specific days, weeks, and months.

When this value is specified, the
**MONTHLYDOW** member of the
[TRIGGER_TYPE_UNION](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-trigger_type_union) structure is used.

### `TASK_EVENT_TRIGGER_ON_IDLE:5`

Trigger is set to run the task if the system remains idle for the amount of time specified by the [idle wait time](https://learn.microsoft.com/windows/desktop/TaskSchd/i) of the task.

When this value is specified, the **wStartHour**, **wStartMinute**, and **Type** member of the
[TASK_TRIGGER](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-task_trigger) structure are ignored.

### `TASK_EVENT_TRIGGER_AT_SYSTEMSTART:6`

Trigger is set to run the task at system startup.

When this value is specified, the **Type** member of the
[TASK_TRIGGER](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-task_trigger) structure is ignored.

### `TASK_EVENT_TRIGGER_AT_LOGON:7`

Trigger is set to run the task when a user logs on.

When this value is specified, the **Type** member of the
[TASK_TRIGGER](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-task_trigger) structure is ignored.

## Remarks

The constants defined here are used in the **TriggerType** member of the
[TASK_TRIGGER](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-task_trigger) structure.

## See also

[IScheduledWorkItem::SetIdleWait](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-setidlewait)

[TASK_TRIGGER](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-task_trigger)

[TASK_TRIGGER_TYPE2](https://learn.microsoft.com/windows/desktop/api/taskschd/ne-taskschd-task_trigger_type2)

[TRIGGER_TYPE_UNION](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-trigger_type_union)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)