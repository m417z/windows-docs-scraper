# ITaskSettings::put_AllowDemandStart

## Description

Gets or sets a Boolean value that indicates that the task can be started by using either the Run command or the Context menu.

This property is read/write.

## Parameters

## Remarks

When this property is set to True, the task can be started independent of when any triggers start the task.

When reading or writing XML for a task, this setting is specified in the [AllowStartOnDemand](https://learn.microsoft.com/windows/desktop/TaskSchd/taskschedulerschema-allowstartondemand-settingstype-element) element of the Task Scheduler schema.

## See also

[ITaskSettings](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itasksettings)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)