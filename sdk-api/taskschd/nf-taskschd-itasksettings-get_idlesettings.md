# ITaskSettings::get_IdleSettings

## Description

Gets or sets the information that specifies how the Task Scheduler performs tasks when the computer is in an idle condition. For information about idle conditions, see [Task Idle Conditions](https://learn.microsoft.com/windows/desktop/TaskSchd/task-idle-conditions).

This property is read/write.

## Parameters

## Remarks

When reading or writing XML for a task, this setting is specified in the [IdleSettings](https://learn.microsoft.com/windows/desktop/TaskSchd/taskschedulerschema-idlesettings-settingstype-element) element of the Task Scheduler schema.

When battery saver is on, Windows Task Scheduler tasks are triggered only if the task is:

* Not set to **Start the task only if the computer is idle...** (task doesn't use **IdleSettings**)
* Not set to run during automatic maintenance (task doesn't use [MaintenanceSettings](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-itasksettings3-get_maintenancesettings))
* Is set to **Run only when user is logged on** (task [LogonType](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-iprincipal-get_logontype) is **TASK_LOGON_INTERACTIVE_TOKEN** or **TASK_LOGON_GROUP**)

All other triggers are delayed until battery saver is off. For more information about accessing battery saver status in your application, see [SYSTEM_POWER_STATUS](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-system_power_status). For general information about battery saver, see [battery saver (in the hardware component guidelines)](https://learn.microsoft.com/windows-hardware/design/component-guidelines/battery-saver).

## See also

[ITaskSettings](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itasksettings)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)