# TASK_RUN_FLAGS enumeration

## Description

Defines how a task is run.

## Constants

### `TASK_RUN_NO_FLAGS:0`

The task is run with all flags ignored.

### `TASK_RUN_AS_SELF:0x1`

The task is run as the user who is calling the [Run](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-iregisteredtask-run) method.

### `TASK_RUN_IGNORE_CONSTRAINTS:0x2`

The task is run regardless of constraints such as "do not run on batteries" or "run only if idle".

### `TASK_RUN_USE_SESSION_ID:0x4`

The task is run using a terminal server session identifier.

### `TASK_RUN_USER_SID:0x8`

The task is run using a security identifier.

## See also

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)

[Task Scheduler Enumerated Types](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-enumerated-types)