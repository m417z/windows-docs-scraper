# ITaskFolder::RegisterTaskDefinition

## Description

Registers (creates) a task in a specified location using the [ITaskDefinition](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itaskdefinition) interface to define a task.

## Parameters

### `path` [in]

The name of the task. If this value is **NULL**, the task will be registered in the root task folder and the task name will be a GUID value created by the Task Scheduler service.

A task name cannot begin or end with a space character. The '.' character cannot be used to specify the current task folder and the '..' characters cannot be used to specify the parent task folder in the path.

### `pDefinition` [in]

The definition of the registered task.

### `flags` [in]

A [TASK_CREATION](https://learn.microsoft.com/windows/desktop/api/taskschd/ne-taskschd-task_creation) constant.

| Value | Meaning |
| --- | --- |
| **TASK_VALIDATE_ONLY**<br><br>0x1 | Task Scheduler verifies the syntax of the XML that describes the task, but does not register the task. This constant cannot be combined with the **TASK_CREATE**, **TASK_UPDATE**, or **TASK_CREATE_OR_UPDATE** values. |
| **TASK_CREATE**<br><br>0x2 | Task Scheduler registers the task as a new task. |
| **TASK_UPDATE**<br><br>0x4 | Task Scheduler registers the task as an updated version of an existing task. When a task with a registration trigger is updated, the task will execute after the update occurs. |
| **TASK_CREATE_OR_UPDATE**<br><br>0x6 | Task Scheduler either registers the task as a new task or as an updated version if the task already exists. Equivalent to TASK_CREATE \| TASK_UPDATE. |
| **TASK_DISABLE**<br><br>0x8 | Task Scheduler disables the existing task. |
| **TASK_DONT_ADD_PRINCIPAL_ACE**<br><br>0x10 | Task Scheduler is prevented from adding the allow access-control entry (ACE) for the context principal. When the **ITaskFolder::RegisterTaskDefinition** function is called with this flag to update a task, the Task Scheduler service does not add the ACE for the new context principal and does not remove the ACE from the old context principal. |
| **TASK_IGNORE_REGISTRATION_TRIGGERS**<br><br>0x20 | The Task Scheduler creates the task, but ignores the registration triggers in the task. By ignoring the registration triggers, the task will not execute when it is registered unless a time-based trigger causes it to execute on registration. |

### `userId` [in]

The user credentials used to register the task. If present, these credentials take priority over the credentials specified in the task definition object pointed to by the *pDefinition* parameter.

**Note** If the task is defined as a Task Scheduler 1.0 task, then do not use a group name (rather than a specific user name) in this userId parameter. A task is defined as a Task Scheduler 1.0 task when the [Compatibility](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-itasksettings-get_compatibility) property is set to TASK_COMPATIBILITY_V1 in the task's settings.

### `password` [in]

The password for the userId used to register the task. When the TASK_LOGON_SERVICE_ACCOUNT logon type is used, the password must be an empty **VARIANT** value such as **VT_NULL** or **VT_EMPTY**.

### `logonType` [in]

Defines what logon technique is used to run the registered task.

| Value | Meaning |
| --- | --- |
| **TASK_LOGON_NONE**<br><br>0 | The logon method is not specified. Used for non-NT credentials. |
| **TASK_LOGON_PASSWORD**<br><br>1 | Use a password for logging on the user. The password must be supplied at registration time. |
| **TASK_LOGON_S4U**<br><br>2 | Use an existing interactive token to run a task. The user must log on using a service for user (S4U) logon. When an S4U logon is used, no password is stored by the system and there is no access to either the network or to encrypted files. |
| **TASK_LOGON_INTERACTIVE_TOKEN**<br><br>3 | User must already be logged on. The task will be run only in an existing interactive session. |
| **TASK_LOGON_GROUP**<br><br>4 | Group activation. The **groupId** field specifies the group. |
| **TASK_LOGON_SERVICE_ACCOUNT**<br><br>5 | Indicates that a Local System, Local Service, or Network Service account is being used as a security context to run the task. |
| **TASK_LOGON_INTERACTIVE_TOKEN_OR_PASSWORD**<br><br>6 | First use the interactive token. If the user is not logged on (no interactive token is available), then the password is used. The password must be specified when a task is registered. This flag is not recommended for new tasks because it is less reliable than TASK_LOGON_PASSWORD. |

### `sddl` [in, optional]

The security descriptor that is associated with the registered task. You can specify the access control list (ACL) in the security descriptor for a task in order to allow or deny certain users and groups access to a task.

**Note** If the Local System account is denied access to a task, then the Task Scheduler service can produce unexpected results.

### `ppTask` [out]

An [IRegisteredTask](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iregisteredtask) interface that represents the new task.

Pass in a reference to a **NULL** [IRegisteredTask](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iregisteredtask) interface pointer. Referencing a non-**NULL** pointer can cause a memory leak because the pointer will be overwritten.

## Return value

This method can return one of these values.

| Return code/value | Description |
| --- | --- |
| **S_OK**<br><br>0x0 | The operation completed successfully. |
| **E_ACCESS_DENIED**<br><br>0x80070005 | Access is denied to connect to the Task Scheduler service. |
| **E_OUTOFMEMORY**<br><br>0x8007000e | The application does not have enough memory to complete the operation or the *user* or *password* has at least one **null** and one non-**null** value. |
| **SCHED_S_BATCH_LOGON_PROBLEM**<br><br>0x0004131C | The task is registered, but may fail to start. Batch logon privilege needs to be enabled for the task principal. |
| **SCHED_S_SOME_TRIGGERS_FAILED**<br><br>0x0004131B | The task is registered, but not all specified triggers will start the task. |

## Remarks

For a task, that contains a message box action, the message box will be displayed if the task is activated and the task has an interactive logon type. To set the task logon type to be interactive, specify **TASK_LOGON_INTERACTIVE_TOKEN** or **TASK_LOGON_GROUP** in the [LogonType](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-iprincipal-get_logontype) property of the task principal, or in the *logonType* parameter of [ITaskFolder::RegisterTask](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-itaskfolder-registertask) or **ITaskFolder::RegisterTaskDefinition**.

Only a member of the Administrators group can create a task with a boot trigger.

You can successfully register a task with a group specified in the *userId* parameter and **TASK_LOGON_INTERACTIVE_TOKEN** specified in the *logonType* parameter of [ITaskFolder::RegisterTask](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-itaskfolder-registertask) or **ITaskFolder::RegisterTaskDefinition**, but the task will not run.

Passing the TASK_VALIDATE_ONLY and TASK_IGNORE_REGISTRATION_TRIGGERS values together to the *flags* parameter is an invalid argument.

The **ITaskFolder::RegisterTaskDefinition** method returns error 80070534 when called by the System account with the *user* parameter equal to **NULL**, the *password* parameter equal to **NULL**, and the *logonType* parameter equal to TASK_LOGON_SERVICE_ACCOUNT.

If a task defines a network that does not exist in the [NetworkSettings](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-itasksettings-get_networksettings) settings of the task, the **ITaskFolder::RegisterTaskDefinition** method will return error 0x8000ffff when the task is registered.

## See also

[IRegisteredTask](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iregisteredtask)

[ITaskFolder](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itaskfolder)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)