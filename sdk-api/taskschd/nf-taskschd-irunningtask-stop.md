# IRunningTask::Stop

## Description

Stops this instance of the task.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The task was stopped. |
| **E_ACCESSDENIED** | The user does not have permission to stop the task, the task is disabled, or the task is not allowed to be run on demand. |

## See also

[IRunningTask](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-irunningtask)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)