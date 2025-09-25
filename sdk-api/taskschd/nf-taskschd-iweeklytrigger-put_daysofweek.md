# IWeeklyTrigger::put_DaysOfWeek

## Description

Gets or sets the days of the week in which the task runs.

This property is read/write.

## Parameters

## Remarks

The following table shows the mapping of the bitwise mask used by this property.

| Month | Hex value | Decimal value |
| --- | --- | --- |
| Sunday | 0X01 | 1 |
| Monday | 0x02 | 2 |
| Tuesday | 0X04 | 4 |
| Wednesday | 0X08 | 8 |
| Thursday | 0X10 | 16 |
| Friday | 0x20 | 32 |
| Saturday | 0X40 | 64 |

When reading or writing your own XML for a task, the days of the week are specified using the [DaysOfWeek](https://learn.microsoft.com/windows/desktop/TaskSchd/taskschedulerschema-daysofweek-weeklyscheduletype-element) element of the Task Scheduler schema.

## See also

[IWeeklyTrigger](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iweeklytrigger)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)