# TASK_PROCESSTOKENSID_TYPE enumeration

## Description

Defines the types of process security identifier (SID) that can be used by tasks. These changes are used to specify the type of process SID in the [IPrincipal2](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iprincipal2) interface.

## Constants

### `TASK_PROCESSTOKENSID_NONE:0`

No changes will be made to the process token groups list.

### `TASK_PROCESSTOKENSID_UNRESTRICTED:1`

A task SID that is derived from the task name will be added to the process token groups list, and the token default discretionary access control list (DACL) will be modified to allow only the task SID and local system full control and the account SID read control.

### `TASK_PROCESSTOKENSID_DEFAULT:2`

A Task Scheduler will apply default settings to the task process.

## See also

[IPrincipal2](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iprincipal2)

[Task Scheduler Enumerated Types](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-enumerated-types)