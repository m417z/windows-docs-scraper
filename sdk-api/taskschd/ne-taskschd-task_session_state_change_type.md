# TASK_SESSION_STATE_CHANGE_TYPE enumeration

## Description

Defines what kind of Terminal Server session state change you can use to trigger a task to start. These changes are used to specify the type of state change in the [ISessionStateChangeTrigger](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-isessionstatechangetrigger) interface.

## Constants

### `TASK_CONSOLE_CONNECT:1`

Terminal Server console connection state change. For example, when you connect to a user session on the local computer by switching users on the computer.

### `TASK_CONSOLE_DISCONNECT:2`

Terminal Server console disconnection state change. For example, when you disconnect to a user session on the local computer by switching users on the computer.

### `TASK_REMOTE_CONNECT:3`

Terminal Server remote connection state change. For example, when a user connects to a user session by using the Remote Desktop Connection program from a remote computer.

### `TASK_REMOTE_DISCONNECT:4`

Terminal Server remote disconnection state change. For example, when a user disconnects from a user session while using the Remote Desktop Connection program from a remote computer.

### `TASK_SESSION_LOCK:7`

Terminal Server session locked state change. For example, this state change causes the task to run when the computer is locked.

### `TASK_SESSION_UNLOCK:8`

Terminal Server session unlocked state change. For example, this state change causes the task to run when the computer is unlocked.

## See also

[ISessionStateChangeTrigger](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-isessionstatechangetrigger)

[Task Scheduler Enumerated Types](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-enumerated-types)