# ITaskSettings::get_Hidden

## Description

Gets or sets a Boolean value that indicates that the task will not be visible in the UI. However, administrators can override this setting through the use of a 'master switch' that makes all tasks visible in the UI.

This property is read/write.

## Parameters

## Remarks

When reading or writing XML for a task, this setting is specified in the [Hidden (settingsType)](https://learn.microsoft.com/windows/desktop/TaskSchd/taskschedulerschema-hidden-settingstype-element) element of the Task Scheduler schema.

## See also

[ITaskSettings](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itasksettings)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)