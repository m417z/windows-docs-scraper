# TASK_TRIGGER structure

## Description

Defines the times to run a scheduled [work item](https://learn.microsoft.com/windows/desktop/TaskSchd/w).

## Members

### `cbTriggerSize`

Size of this structure, in bytes.

### `Reserved1`

For internal use only; this value must be zero.

### `wBeginYear`

Year that the task trigger activates. This value must be four digits (1997, not 97). The beginning year must be specified when setting a task.

### `wBeginMonth`

Month of the year (specified in the **wBeginYear** member) that the task trigger activates. The beginning month must be specified when setting a task.

### `wBeginDay`

Day of the month (specified in the **wBeginMonth** member) that the task trigger activates. The beginning day must be specified when setting a task.

### `wEndYear`

Year that the task trigger deactivates. This value must be four digits (1997, not 97).

### `wEndMonth`

Month of the year (specified in the **wEndYear** member) that the task trigger deactivates.

### `wEndDay`

Day of the month (specified in the **wEndMonth** member) that the task trigger deactivates.

### `wStartHour`

Hour of the day the task runs. This value is on a 24-hour clock; hours go from 00 to 23.

### `wStartMinute`

Minute of the hour (specified in the **wStartHour** member) that the task runs.

### `MinutesDuration`

Number of minutes after the task starts that the trigger will remain active. The number of minutes specified here must be greater than or equal to the **MinutesInterval** setting.

For example, if you start a task at 8:00 A.M. and want to repeatedly start the task until 5:00 P.M., there would be 540 minutes in the duration.

### `MinutesInterval`

Number of minutes between consecutive task executions. This number is counted from the start of the previous scheduled task. The number of minutes specified here must be less than the **MinutesDuration** setting.

For example, to run a task every hour from 8:00 A.M. to 5:00 P.M., set this field to 60.

### `rgFlags`

Value that describes the behavior of the trigger. This value is a combination of the following flags.

#### TASK_TRIGGER_FLAG_HAS_END_DATE

Trigger structure's end date is valid. If this flag is not set, the end date data is ignored and the trigger will be valid indefinitely.

#### TASK_TRIGGER_FLAG_KILL_AT_DURATION_END

Task will be terminated at the end of the active trigger's lifetime. At the duration end, the Task Scheduler sends a WM_CLOSE message to the associated application. If WM_CLOSE cannot be sent (for example, the application has no windows) or the application has not exited within three minutes of the receiving WM_CLOSE, the Task Scheduler terminates the application using **TerminateProcess**.

#### TASK_TRIGGER_FLAG_DISABLED

Task trigger is inactive.

### `TriggerType`

A
[TASK_TRIGGER_TYPE](https://learn.microsoft.com/windows/desktop/api/mstask/ne-mstask-task_trigger_type) enumerated value that specifies the type of trigger. This member is used with **Type**. The type of trigger specified here determines which fields of the
[TRIGGER_TYPE_UNION](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-trigger_type_union) specified in **Type** member will be used. Trigger type is based on when the trigger will run the task.

### `Type`

A
[TRIGGER_TYPE_UNION](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-trigger_type_union) structure that specifies details about the trigger. Note that the **TriggerType** member determines which fields of the TRIGGER_TYPE_UNION union will be used.

### `Reserved2`

For internal use only; this value must be zero.

### `wRandomMinutesInterval`

Not currently used.

## Remarks

These times may include the start time, end time, duration, and modification flags for the work item. Note that when setting a trigger, the beginning day month and year must be set.

**Note** A scheduled work item can have one or more triggers defined. The times that the work item will run is the union of all the triggers defined for that item.

## See also

[IScheduledWorkItem::CreateTrigger](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-createtrigger)

[ITaskTrigger::GetTrigger](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-itasktrigger-gettrigger)

[ITaskTrigger::SetTrigger](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-itasktrigger-settrigger)

[TASK_TRIGGER_TYPE](https://learn.microsoft.com/windows/desktop/api/mstask/ne-mstask-task_trigger_type)

[TRIGGER_TYPE_UNION](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-trigger_type_union)

[Task Scheduler 2.0 Trigger Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/trigger-interfaces)