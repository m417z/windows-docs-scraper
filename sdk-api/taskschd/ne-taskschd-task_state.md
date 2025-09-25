# TASK_STATE enumeration

## Description

Defines the different states that a registered task can be in.

## Constants

### `TASK_STATE_UNKNOWN:0`

The state of the task is unknown.

### `TASK_STATE_DISABLED:1`

The task is registered but is disabled and no instances of the task are queued or running. The task cannot be run until it is enabled.

### `TASK_STATE_QUEUED:2`

Instances of the task are queued.

### `TASK_STATE_READY:3`

The task is ready to be executed, but no instances are queued or running.

### `TASK_STATE_RUNNING:4`

One or more instances of the task is running.

## See also

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)

[Task Scheduler Enumerated Types](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-enumerated-types)