# MONTHLYDOW structure

## Description

 Defines the date(s) that the task runs by month, week, and day of the week.

## Members

### `wWhichWeek`

Specifies the week of the month when the task runs. This value is exclusive and is one of the following flags.

| Flag | Meaning |
| --- | --- |
| **TASK_FIRST_WEEK** | The task will run between the first and seventh day of the month. |
| **TASK_SECOND_WEEK** | The task will run between the eighth and 14th day of the month. |
| **TASK_THIRD_WEEK** | The task will run between the 15th and 21st day of the month. |
| **TASK_FOURTH_WEEK** | The task will run between the 22nd and 28th of the month. |
| **TASK_LAST_WEEK** | The task will run between the last seven days of the month. |

### `rgfDaysOfTheWeek`

Specifies the day(s) of the week (specified in **wWhichWeek**) when the task runs. This value is a combination of the following flags.

| Flag | Meaning |
| --- | --- |
| **TASK_SUNDAY** | The task will run on Sunday. |
| **TASK_MONDAY** | The task will run on Monday. |
| **TASK_TUESDAY** | The task will run on Tuesday. |
| **TASK_WEDNESDAY** | The task will run on Wednesday. |
| **TASK_THURSDAY** | The task will run on Thursday. |
| **TASK_FRIDAY** | The task will run on Friday. |
| **TASK_SATURDAY** | The task will run on Saturday. |

### `rgfMonths`

Value that describes the month(s) when the task runs. This value is a combination of the following flags.

| Flag | Meaning |
| --- | --- |
| **TASK_JANUARY** | The task will run in January. |
| **TASK_FEBRUARY** | The task will run in February. |
| **TASK_MARCH** | The task will run in March. |
| **TASK_APRIL** | The task will run in April. |
| **TASK_MAY** | The task will run in May. |
| **TASK_JUNE** | The task will run in June. |
| **TASK_JULY** | The task will run in July. |
| **TASK_AUGUST** | The task will run in August. |
| **TASK_SEPTEMBER** | The task will run in September. |
| **TASK_OCTOBER** | The task will run in October. |
| **TASK_NOVEMBER** | The task will run in November. |
| **TASK_DECEMBER** | The task will run in December. |

## Remarks

The
[TRIGGER_TYPE_UNION](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-trigger_type_union) union uses an instance of this structure as part of the **Type** member of the
[TASK_TRIGGER](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-task_trigger) structure definition.

The following C++ example shows how to combine these flags. The example runs a task on the Monday and the Friday of the third week of every third month.

```cpp
MONTHLYDOW example;
example.wWhichWeek = TASK_THIRD_WEEK;
example.rgfDaysOfTheWeek = TASK_FRIDAY | TASK_MONDAY;
example.rgfMonths = TASK_JANUARY | TASK_APRIL | TASK_JULY | TASK_OCTOBER;
```

## See also

[IMonthlyDOWTrigger](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-imonthlydowtrigger)

[TASK_TRIGGER](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-task_trigger)

[TRIGGER_TYPE_UNION](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-trigger_type_union)