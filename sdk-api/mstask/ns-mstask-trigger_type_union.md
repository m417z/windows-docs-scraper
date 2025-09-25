# TRIGGER_TYPE_UNION structure

## Description

Defines the invocation schedule of the trigger within the **Type** member of a
[TASK_TRIGGER](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-task_trigger) structure.

## Members

### `Daily`

A
[DAILY](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-daily) structure that specifies the number of days between invocations of a task.

### `Weekly`

A
[WEEKLY](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-weekly) structure that specifies the number of weeks between invocations of a task, and day(s) of the week the task will run.

### `MonthlyDate`

A
[MONTHLYDATE](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-monthlydate) structure that specifies the month(s) and day(s) of the month a task will run.

### `MonthlyDOW`

A
[MONTHLYDOW](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-monthlydow) structure that specifies the day(s) of the year a task runs by month(s), week of month, and day(s) of week.

## Remarks

The **TriggerType** member of the
[TASK_TRIGGER](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-task_trigger) structure defines which fields of this union are used.

## See also

[DAILY](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-daily)

[ITrigger](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itrigger)

[MONTHLYDATE](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-monthlydate)

[MONTHLYDOW](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-monthlydow)

[TASK_TRIGGER](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-task_trigger)

[Type](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-itrigger-get_type)

[WEEKLY](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-weekly)