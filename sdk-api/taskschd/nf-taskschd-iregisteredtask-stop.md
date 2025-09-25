# IRegisteredTask::Stop

## Description

Stops the registered task immediately.

## Parameters

### `flags` [in]

Reserved. Must be zero.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | All instances of the registered task that user has permissions to stop were stopped. |
| **S_FALSE** | The user cannot successfully stop instances of the task. |

## Remarks

The **IRegisteredTask::Stop** function stops all instances of the task.

System account users can stop a task, users with Administrator group privileges can stop a task, and if a user has rights to execute and read a task, then the user can stop the task. A user can stop the task instances that are running under the same credentials as the user account. In all other cases, the user is denied access to stop the task.

## See also

[IRegisteredTask](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iregisteredtask)