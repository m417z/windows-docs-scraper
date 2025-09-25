# IMaintenanceSettings::get_Exclusive

## Description

Indicates whether the Task scheduler must start the task during the Automatic maintenance in exclusive mode.

The exclusivity is guaranteed only between other maintenance tasks and doesn't grant any ordering priority of the task. If exclusivity is not specified, the task is started in parallel with other maintenance tasks.

This property is read/write.

## Parameters

## Remarks

Starting a task in exclusive mode means that no other maintenance task is get started in parallel with this one. Exclusivity does not guarantee the task any priority in order of execution.

When reading or writing XML for a task, this setting is specified in the [Exclusive](https://learn.microsoft.com/windows/desktop/TaskSchd/taskschedulerschema-exclusive-element) element of the Task Scheduler schema.

## See also

[IMaintenanceSettings](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-imaintenancesettings)