# WEEKLY structure

## Description

Defines the interval, in weeks, between invocations of a task.

## Members

### `WeeksInterval`

Number of weeks between invocations of a task.

### `rgfDaysOfTheWeek`

Value that describes the days of the week the task runs. This value is a bitfield and is a combination of the following flags. See Remarks for an example of specifying multiple flags.

| Flag | Meaning |
| --- | --- |
| **TASK_SUNDAY** | The task will run on Sunday. |
| **TASK_MONDAY** | The task will run on Monday. |
| **TASK_TUESDAY** | The task will run on Tuesday. |
| **TASK_WEDNESDAY** | The task will run on Wednesday. |
| **TASK_THURSDAY** | The task will run on Thursday. |
| **TASK_FRIDAY** | The task will run on Friday. |
| **TASK_SATURDAY** | The task will run on Saturday. |

## Remarks

 The
[TRIGGER_TYPE_UNION](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-trigger_type_union) union uses an instance of this structure as part of the **Type** member of the
[TASK_TRIGGER](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-task_trigger) structure definition.

The following C++ shows how to combine the **rgfDaysOfTheWeek** flags. The example runs a task on every other Sunday, Wednesday, and Friday.

```cpp
WEEKLY example;
example.WeeksInterval = 2;
example.rgfDaysOfTheWeek = TASK_SUNDAY | TASK_WEDNESDAY | TASK_FRIDAY;
```

## See also

[IWeeklyTrigger](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iweeklytrigger)

[TASK_TRIGGER](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-task_trigger)

[TRIGGER_TYPE_UNION](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-trigger_type_union)

[WeeksInterval](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-iweeklytrigger-get_weeksinterval)