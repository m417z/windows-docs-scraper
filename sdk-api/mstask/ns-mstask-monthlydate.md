# MONTHLYDATE structure

## Description

 Defines the day of the month the task will run.

## Members

### `rgfDays`

Specifies the day of the month a task runs. This value is a bitfield that specifies the day(s) the task will run. Bit 0 corresponds to the first of the month, bit 1 to the second, and so forth.

### `rgfMonths`

Specifies the month(s) when the task runs. This value is a combination of the following flags. See Remarks for an example of setting multiple flags.

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

The following C++ example shows how to combine the flags. The example runs a task quarterly.

```cpp
MONTHLYDATE example;
example.rgfDays = 1;
example.rgfMonths = TASK_JANUARY | TASK_APRIL | TASK_JULY | TASK_OCTOBER;
```

## See also

[TASK_TRIGGER](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-task_trigger)

[TRIGGER_TYPE_UNION](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-trigger_type_union)