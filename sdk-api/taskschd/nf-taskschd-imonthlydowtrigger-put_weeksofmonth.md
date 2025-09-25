# IMonthlyDOWTrigger::put_WeeksOfMonth

## Description

Gets or sets the weeks of the month during which the task runs.

This property is read/write.

## Parameters

## Remarks

The following table shows the mapping of the bitwise mask used by this property. Note that you can explicitly specify the last week of the month, regardless of what week it is, by specifying 0X10 (16).

| Week | Hex value | Decimal value |
| --- | --- | --- |
| First | 0X01 | 1 |
| Second | 0x02 | 2 |
| Third | 0X04 | 4 |
| Fourth | 0X08 | 8 |
| Last | 0X10 | 16 |

When reading or writing XML for a task, the weeks of the month of a monthly day-of-week calendar are specified by the [Weeks](https://learn.microsoft.com/windows/desktop/TaskSchd/taskschedulerschema-weeks-monthlydayofweekscheduletype-element) element of the Task Scheduler schema.

## See also

[IMonthlyDOWTrigger](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-imonthlydowtrigger)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)