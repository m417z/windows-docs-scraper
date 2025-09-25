# IExecAction::put_WorkingDirectory

## Description

Gets or sets the directory that contains either the executable file or the files that are used by the executable file.

This property is read/write.

## Parameters

## Remarks

When reading or writing XML, the working directory of the application is specified in the [WorkingDirectory](https://learn.microsoft.com/windows/desktop/TaskSchd/taskschedulerschema-workingdirectory-exectype-element) element of the Task Scheduler schema.

The path is checked to make sure it is valid when the task is registered, not when this property is set.

## See also

[IExecAction](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iexecaction)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)