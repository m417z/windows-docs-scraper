# IPrincipal::get_LogonType

## Description

Gets or sets the security logon method that is required to run the tasks that are associated with the principal.

This property is read/write.

## Parameters

## Remarks

This property is valid only when a user identifier is specified by the [UserId](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-iprincipal-get_userid) property.

When reading or writing XML for a task, the logon type is specified in the [\<LogonType>](https://learn.microsoft.com/windows/desktop/TaskSchd/taskschedulerschema-logontype-principaltype-element) element of the Task Scheduler schema.

For a task, that contains a message box action, the message box will be displayed if the task is activated and the task has an interactive logon type. To set the task logon type to be interactive, specify **TASK_LOGON_INTERACTIVE_TOKEN** or **TASK_LOGON_GROUP** in the **LogonType** property of the task principal, or in the *logonType* parameter of [ITaskFolder::RegisterTask](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-itaskfolder-registertask) or [ITaskFolder::RegisterTaskDefinition](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-itaskfolder-registertaskdefinition).

When battery saver is on, Windows Task Scheduler tasks are triggered only if the task is:

* Not set to **Start the task only if the computer is idle...** (task doesn't use [IdleSettings](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-itasksettings-get_idlesettings))
* Not set to run during automatic maintenance (task doesn't use [MaintenanceSettings](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-itasksettings3-get_maintenancesettings))
* Is set to **Run only when user is logged on** (task **LogonType** is **TASK_LOGON_INTERACTIVE_TOKEN** or **TASK_LOGON_GROUP**)

All other triggers are delayed until battery saver is off. For more information about accessing battery saver status in your application, see [SYSTEM_POWER_STATUS](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-system_power_status). For general information about battery saver, see [battery saver (in the hardware component guidelines)](https://learn.microsoft.com/windows-hardware/design/component-guidelines/battery-saver).

## See also

[IPrincipal](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iprincipal)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)