# TASK_LOGON_TYPE enumeration

## Description

Defines what logon technique is required to run a task.

## Constants

### `TASK_LOGON_NONE:0`

The logon method is not specified. Used for non-NT credentials.

### `TASK_LOGON_PASSWORD:1`

Use a password for logging on the user. The password must be supplied at registration time.

### `TASK_LOGON_S4U:2`

The service will log the user on using Service For User (S4U), and the task will run in a non-interactive desktop. When an S4U logon is used, no password is stored by the system and there is no access to either the network or to encrypted files.

### `TASK_LOGON_INTERACTIVE_TOKEN:3`

 User must already be logged on. The task will be run only in an existing interactive session.

### `TASK_LOGON_GROUP:4`

Group activation. The **groupId** field specifies the group.

### `TASK_LOGON_SERVICE_ACCOUNT:5`

Indicates that a Local System, Local Service, or Network Service account is being used as a security context to run the task.

### `TASK_LOGON_INTERACTIVE_TOKEN_OR_PASSWORD:6`

Not in use; currently identical to TASK_LOGON_PASSWORD.

**Windows 10, version 1511, Windows 10, version 1507, Windows 8.1, Windows Server 2012 R2, Windows 8, Windows Server 2012, Windows Vista and Windows Server 2008:** First use the interactive token. If the user is not logged on (no interactive token is available), then the password is used. The password must be specified when a task is registered. This flag is not recommended for new tasks because it is less reliable than TASK_LOGON_PASSWORD.

## See also

[Task Scheduler Enumerated Types](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-enumerated-types)