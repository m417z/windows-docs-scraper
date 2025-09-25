# ITaskSettings::get_StartWhenAvailable

## Description

Gets or sets a Boolean value that indicates that the Task Scheduler can start the task at any time after its scheduled time has passed.

This property is read/write.

## Parameters

## Remarks

This property applies only to time-based tasks with an end boundary or time-based tasks that are set to repeat infinitely.

Tasks that are started after the scheduled time has passed (because of the **StartWhenAvailable** property being set to True) are queued in the Task Scheduler service's queue of tasks and they are started after a delay. The default delay is 10 minutes.

When reading or writing XML for a task, this setting is specified in the [StartWhenAvailable](https://learn.microsoft.com/windows/desktop/TaskSchd/taskschedulerschema-startwhenavailable-settingstype-element) element of the Task Scheduler schema.

## See also

[ITaskSettings](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itasksettings)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)