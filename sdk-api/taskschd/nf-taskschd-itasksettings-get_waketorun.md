# ITaskSettings::get_WakeToRun

## Description

Gets or sets a Boolean value that indicates that the Task Scheduler will wake the computer when it is time to run the task, and keep the computer awake until the task is completed.

This property is read/write.

## Parameters

## Remarks

If a task has this property set to true, and is triggered when the computer is already awake, Task Scheduler will request the computer to stay awake until the task has completed running.

When the Task Scheduler service wakes the computer to run a task, the screen may remain off even though the computer is no longer in the sleep or hibernate mode. The screen will turn on when Windows Vista detects that a user has returned to use the computer.

When reading or writing XML for a task, this setting is specified in the [WakeToRun](https://learn.microsoft.com/windows/desktop/TaskSchd/taskschedulerschema-waketorun-settingstype-element) element of the Task Scheduler schema.

## See also

[ITaskSettings](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itasksettings)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)