# TASK_COMPATIBILITY enumeration

## Description

 Defines what versions of Task Scheduler or the AT command that the task is compatible with.

## Constants

### `TASK_COMPATIBILITY_AT:0`

The task is compatible with the AT command.

### `TASK_COMPATIBILITY_V1:1`

The task is compatible with Task Scheduler 1.0.

### `TASK_COMPATIBILITY_V2:2`

The task is compatible with Task Scheduler 2.0.

### `TASK_COMPATIBILITY_V2_1:3`

### `TASK_COMPATIBILITY_V2_2:4`

### `TASK_COMPATIBILITY_V2_3:5`

### `TASK_COMPATIBILITY_V2_4:6`

## Remarks

 Task compatibility, which is set through the [Compatibility](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-itasksettings-get_compatibility) property, should only be set to TASK_COMPATIBILITY_V1 if a task needs to be accessed or modified from a Windows XP, Windows Server 2003, or Windows 2000 computer. Otherwise, it is recommended that Task Scheduler 2.0 compatibility be used because the task will have more features.

Once the task [Compatibility](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-itasksettings-get_compatibility) property is set to TASK_COMPATIBILITY_V2 and the task is registered, then the task **Compatibility** property cannot be changed to TASK_COMPATIBILITY_V1.

## See also

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)

[Task Scheduler Enumerated Types](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-enumerated-types)