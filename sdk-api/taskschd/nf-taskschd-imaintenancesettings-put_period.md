# IMaintenanceSettings::put_Period

## Description

Gets or sets the amount of time the task needs to be once executed during regular Automatic maintenance.

This property is read/write.

## Parameters

## Remarks

The minimum value for this property is 1 day (*P1D*).

When reading or writing XML for a task, this setting is specified in the [Period](https://learn.microsoft.com/windows/desktop/TaskSchd/taskschedulerschema-period-element) element of the Task Scheduler schema.

## See also

[IMaintenanceSettings](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-imaintenancesettings)