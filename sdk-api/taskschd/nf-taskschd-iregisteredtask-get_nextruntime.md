# IRegisteredTask::get_NextRunTime

## Description

Gets the time when the registered task is next scheduled to run.

This property is read-only.

## Parameters

## Remarks

If the registered task contains triggers that are individually disabled, these triggers will still affect the next scheduled run time that is returned even though they are disabled.

## See also

[IRegisteredTask](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iregisteredtask)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)