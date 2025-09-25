# ITrigger::put_ExecutionTimeLimit

## Description

Gets or sets the maximum amount of time that the task launched by this trigger is allowed to run.

This property is read/write.

## Parameters

## Remarks

The format for this string is PnYnMnDTnHnMnS, where nY is the number of years, nM is the number of months, nD is the number of days, 'T' is the date/time separator, nH is the number of hours, nM is the number of minutes, and nS is the number of seconds (for example, PT5M specifies 5 minutes and P1M4DT2H5M specifies one month, four days, two hours, and five minutes).

When reading or writing XML for a task, the execution time limit is specified in the [ExecutionTimeLimit](https://learn.microsoft.com/windows/desktop/TaskSchd/taskschedulerschema-executiontimelimit-triggerbasetype-element) element of the Task Scheduler schema.

## See also

[ITrigger](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itrigger)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)