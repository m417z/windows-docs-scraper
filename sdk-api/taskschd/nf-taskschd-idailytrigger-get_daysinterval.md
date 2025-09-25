# IDailyTrigger::get_DaysInterval

## Description

Gets or sets the interval between the days in the schedule.

This property is read/write.

## Parameters

## Remarks

An interval of 1 produces a daily schedule. An interval of 2 produces an every-other day schedule.

When reading or writing your own XML for a task, the interval for a daily schedule is specified using the [DaysInterval](https://learn.microsoft.com/windows/desktop/TaskSchd/taskschedulerschema-daysinterval-dailyscheduletype-element) element of the Task Scheduler schema.

## See also

[IDailyTrigger](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-idailytrigger)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)