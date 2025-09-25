# IMonthlyTrigger::get_MonthsOfYear

## Description

Gets or sets the months of the year during which the task runs.

This property is read/write.

## Parameters

## Remarks

The following table shows the mapping of the bitwise mask that is used by this property.

| Month | Hex value | Decimal value |
| --- | --- | --- |
| January | 0X001 | 1 |
| February | 0x002 | 2 |
| March | 0X004 | 4 |
| April | 0x008 | 8 |
| May | 0X010 | 16 |
| June | 0X020 | 32 |
| July | 0x040 | 64 |
| August | 0X080 | 128 |
| September | 0X100 | 256 |
| October | 0X200 | 512 |
| November | 0X400 | 1024 |
| December | 0X800 | 2048 |

When reading or writing your own XML for a task, the months of the year are specified using the [Months](https://learn.microsoft.com/windows/desktop/TaskSchd/taskschedulerschema-months-monthlyscheduletype-element)  element of the Task Scheduler schema.

## See also

[IMonthlyTrigger](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-imonthlytrigger)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)