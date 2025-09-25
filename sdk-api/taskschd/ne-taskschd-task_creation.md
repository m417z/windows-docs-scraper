# TASK_CREATION enumeration

## Description

Defines how the Task Scheduler service creates, updates, or disables the task.

## Constants

### `TASK_VALIDATE_ONLY:0x1`

The Task Scheduler service checks the syntax of the XML that describes the task but does not register the task. This constant cannot be combined with the **TASK_CREATE**, **TASK_UPDATE**, or **TASK_CREATE_OR_UPDATE** values.

### `TASK_CREATE:0x2`

The Task Scheduler service registers the task as a new task.

### `TASK_UPDATE:0x4`

The Task Scheduler service registers the task as an updated version of an existing task. When a task with a registration trigger is updated, the task will execute after the update occurs.

### `TASK_CREATE_OR_UPDATE`

The Task Scheduler service either registers the task as a new task or as an updated version if the task already exists. Equivalent to TASK_CREATE \| TASK_UPDATE.

### `TASK_DISABLE:0x8`

The Task Scheduler service registers the disabled task. A disabled task cannot run until it is enabled. For more information, see [Enabled Property of ITaskSettings](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-itasksettings-get_enabled) and [Enabled Property of IRegisteredTask](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-iregisteredtask-get_enabled).

### `TASK_DONT_ADD_PRINCIPAL_ACE:0x10`

The Task Scheduler service is prevented from adding the allow access-control entry (ACE) for the context principal. When the [ITaskFolder::RegisterTaskDefinition](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-itaskfolder-registertaskdefinition) or [ITaskFolder::RegisterTask](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-itaskfolder-registertask) functions are called with this flag to update a task, the Task Scheduler service does not add the ACE for the new context principal and does not remove the ACE from the old context principal.

### `TASK_IGNORE_REGISTRATION_TRIGGERS:0x20`

The Task Scheduler service creates the task, but ignores the registration triggers in the task. By ignoring the registration triggers, the task will not execute when it is registered unless a time-based trigger causes it to execute on registration.

## See also

[Task Scheduler Enumerated Types](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-enumerated-types)