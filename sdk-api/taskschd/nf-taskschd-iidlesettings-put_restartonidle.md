# IIdleSettings::put_RestartOnIdle

## Description

Gets or sets a Boolean value that indicates whether the task is restarted when the computer cycles into an idle condition more than once.

This property is read/write.

## Parameters

## Remarks

This property is only used if the [StopOnIdleEnd](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-iidlesettings-get_stoponidleend) property is set to True.

When reading or writing XML for a task, this setting is specified in the [RestartOnIdle](https://learn.microsoft.com/windows/desktop/TaskSchd/taskschedulerschema-restartonidle-idlesettingstype-element) element of the Task Scheduler schema.

## See also

[IIdleSettings](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iidlesettings)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)