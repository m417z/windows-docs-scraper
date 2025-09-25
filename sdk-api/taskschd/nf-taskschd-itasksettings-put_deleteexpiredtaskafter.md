# ITaskSettings::put_DeleteExpiredTaskAfter

## Description

Gets or sets the amount of time that the Task Scheduler will wait before deleting the task after it expires. If no value is specified for this property, then the Task Scheduler service will not delete the task.

This property is read/write.

## Parameters

## Remarks

A task expires after the end boundary has been exceeded for all triggers associated with the task. The end boundary for a trigger is specified by the [EndBoundary](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-itrigger-get_endboundary) property inherited by all trigger interfaces.

When reading or writing XML for a task, this setting is specified in the [DeleteExpiredTaskAfter (settingsType)](https://learn.microsoft.com/windows/desktop/TaskSchd/taskschedulerschema-deleteexpiredtaskafter-settingstype-element) element of the Task Scheduler schema.

## See also

[ITaskSettings](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itasksettings)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)