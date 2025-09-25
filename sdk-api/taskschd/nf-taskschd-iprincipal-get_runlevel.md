# IPrincipal::get_RunLevel

## Description

Gets or sets the identifier that is used to specify the privilege level that is required to run the tasks that are associated with the principal.

This property is read/write.

## Parameters

## Remarks

If a task is registered using the Builtin\Administrator account or the Local System or Local Service accounts, then the **RunLevel** property will be ignored. The property value will also be ignored if User Account Control (UAC) is turned off.

If a task is registered using the Administrators group for the security context of the task, then you must also set the **RunLevel** property to **TASK_RUNLEVEL_HIGHEST** if you want to run the task. For more information, see [Security Contexts for Tasks](https://learn.microsoft.com/windows/desktop/TaskSchd/security-contexts-for-running-tasks).

## See also

[IPrincipal](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iprincipal)