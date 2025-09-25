# IMonthlyDOWTrigger::get_DaysOfWeek

## Description

Gets or sets the days of the week during which the task runs.

This property is read/write.

## Parameters

## Remarks

The following table shows the mapping of the bitwise mask used by this property.

| Day of Week | Hex Value | Decimal Value |
| --- | --- | --- |
| Sunday | 0X01 | 1 |
| Monday | 0x02 | 2 |
| Tuesday | 0X04 | 4 |
| Wednesday | 0X08 | 8 |
| Thursday | 0X10 | 16 |
| Friday | 0X20 | 32 |
| Saturday | 0X40 | 64 |

When reading or writing XML for a task, the days of the week of a monthly day-of-week calendar are specified by the [DaysOfWeek](https://learn.microsoft.com/windows/desktop/TaskSchd/taskschedulerschema-daysofweek-monthlydayofweekscheduletype-element) element.

## See also

[IMonthlyDOWTrigger](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-imonthlydowtrigger)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)