# IExecAction::put_Path

## Description

Gets or sets the path to an executable file.

This property is read/write.

## Parameters

## Remarks

This action performs a command-line operation. For example, the action could run a script or launch an executable.

When reading or writing XML, the command-line operation path is specified in the [Command](https://learn.microsoft.com/windows/desktop/TaskSchd/taskschedulerschema-command-exectype-element) element of the Task Scheduler schema.

The path is checked to make sure it is valid when the task is registered, not when this property is set.

## See also

[IExecAction](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iexecaction)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)