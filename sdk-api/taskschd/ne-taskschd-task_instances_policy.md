# TASK_INSTANCES_POLICY enumeration

## Description

Defines how the Task Scheduler handles existing instances of the task when it starts a new instance of the task.

## Constants

### `TASK_INSTANCES_PARALLEL:0`

Starts new instance while an existing instance is running.

### `TASK_INSTANCES_QUEUE:1`

Starts a new instance of the task after all other instances of the task are complete.

### `TASK_INSTANCES_IGNORE_NEW:2`

Does not start a new instance if an existing instance of the task is running.

### `TASK_INSTANCES_STOP_EXISTING:3`

Stops an existing instance of the task before it starts a new instance.

## See also

[Task Scheduler Enumerated Types](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-enumerated-types)