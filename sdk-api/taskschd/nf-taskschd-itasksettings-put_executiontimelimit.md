# ITaskSettings::put_ExecutionTimeLimit

## Description

Gets or sets the amount of time that is allowed to complete the task. By default, a task will be stopped 72 hours after it starts to run. You can change this by changing this setting.

This property is read/write.

## Parameters

## Remarks

The format for this string is PnYnMnDTnHnMnS, where nY is the number of years, nM is the number of months, nD is the number of days, 'T' is the date/time separator, nH is the number of hours, nM is the number of minutes, and nS is the number of seconds (for example, PT5M specifies 5 minutes and P1M4DT2H5M specifies one month, four days, two hours, and five minutes). A value of PT0S will enable the task to run indefinitely.

**Note** If a task is started on demand, the ExecutionTimeLimit setting is bypassed. Therefore, a task that is started on demand will not be terminated if it exceeds the ExecutionTimeLimit.

When reading or writing XML for a task, this setting is specified in the [ExecutionTimeLimit](https://learn.microsoft.com/windows/desktop/TaskSchd/taskschedulerschema-executiontimelimit-settingstype-element) element of the Task Scheduler schema.

## See also

[ITaskSettings](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itasksettings)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)