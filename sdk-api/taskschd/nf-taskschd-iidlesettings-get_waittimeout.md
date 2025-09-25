# IIdleSettings::get_WaitTimeout

## Description

Gets or sets a value that indicates the amount of time that the Task Scheduler will wait for an idle condition to occur. If no value is specified for this property, then the Task Scheduler service will wait indefinitely for an idle condition to occur.

This property is read/write.

## Parameters

## Remarks

When reading or writing XML for a task, this setting is specified in the [WaitTimeout](https://learn.microsoft.com/windows/desktop/TaskSchd/taskschedulerschema-waittimeout-idlesettingstype-element) element of the Task Scheduler schema.

If a task is triggered by an idle trigger, then the **WaitTimeout** property of the [IIdleSettings](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iidlesettings) interface is ignored.

## See also

[IIdleSettings](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iidlesettings)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)