# IEventTrigger::get_Delay

## Description

Gets or sets a value that indicates the amount of time between when the event occurs and when the task is started. The format for this string is PnYnMnDTnHnMnS, where nY is the number of years, nM is the number of months, nD is the number of days, 'T' is the date/time separator, nH is the number of hours, nM is the number of minutes, and nS is the number of seconds (for example, PT5M specifies 5 minutes and P1M4DT2H5M specifies one month, four days, two hours, and five minutes).

This property is read/write.

## Parameters

## Remarks

When reading or writing your own XML for a task, the event delay is specified using the [Delay](https://learn.microsoft.com/windows/desktop/TaskSchd/taskschedulerschema-delay-eventtriggertype-element) element of the Task Scheduler schema.

## See also

[IEventTrigger](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-ieventtrigger)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)