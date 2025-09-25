# IWeeklyTrigger::get_WeeksInterval

## Description

Gets or sets the interval between the weeks in the schedule.

This property is read/write.

## Parameters

## Remarks

An interval of 1 produces a weekly schedule. An interval of 2 produces an every-other week schedule.

When reading or writing your own XML for a task, the interval for a weekly schedule is specified using the [WeeksInterval](https://learn.microsoft.com/windows/desktop/TaskSchd/taskschedulerschema-weeksinterval-weeklyscheduletype-element) element of the Task Scheduler schema.

## See also

[IWeeklyTrigger](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iweeklytrigger)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)