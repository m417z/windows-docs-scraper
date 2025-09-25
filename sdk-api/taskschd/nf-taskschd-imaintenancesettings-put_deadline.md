# IMaintenanceSettings::put_Deadline

## Description

Gets or sets the amount of time after which the Task scheduler attempts to run the task during emergency Automatic maintenance, if the task failed to complete during regular Automatic maintenance.

This property is read/write.

## Parameters

## Remarks

The value of this property must be greater than the value of the [Period](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-imaintenancesettings-get_period) property.

When reading or writing XML for a task, this setting is specified in the [Deadline](https://learn.microsoft.com/windows/desktop/TaskSchd/taskschedulerschema-deadline-element) element of the Task Scheduler schema.

## See also

[IMaintenanceSettings](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-imaintenancesettings)