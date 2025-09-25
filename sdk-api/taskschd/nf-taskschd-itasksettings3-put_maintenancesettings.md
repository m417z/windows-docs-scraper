# ITaskSettings3::put_MaintenanceSettings

## Description

Gets or sets a pointer to pointer to an [IMaintenanceSettings](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-imaintenancesettings) object that Task scheduler uses to perform a task during Automatic maintenance.

This property is read/write.

## Parameters

## Remarks

When battery saver is on, Windows Task Scheduler tasks are triggered only if the task is:

* Not set to **Start the task only if the computer is idle...** (task doesn't use [IdleSettings](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-itasksettings-get_idlesettings))
* Not set to run during automatic maintenance (task doesn't use **MaintenanceSettings**)
* Is set to **Run only when user is logged on** (task [LogonType](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-iprincipal-get_logontype) is **TASK_LOGON_INTERACTIVE_TOKEN** or **TASK_LOGON_GROUP**)

All other triggers are delayed until battery saver is off. For more information about accessing battery saver status in your application, see [SYSTEM_POWER_STATUS](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-system_power_status). For general information about battery saver, see [battery saver (in the hardware component guidelines)](https://learn.microsoft.com/windows-hardware/design/component-guidelines/battery-saver).

## See also

[ITaskSettings3](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itasksettings3)