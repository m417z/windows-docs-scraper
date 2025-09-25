# ITaskSettings::get_Compatibility

## Description

Gets or sets an integer value that indicates which version of Task Scheduler a task is compatible with.

This property is read/write.

## Parameters

## Remarks

 Task compatibility, which is set through the **Compatibility** property, should only be set to TASK_COMPATIBILITY_V1 if a task needs to be accessed or modified from a Windows XP, Windows Server 2003, or Windows 2000 computer. Otherwise, it is recommended that Task Scheduler 2.0 compatibility be used because the task will have more features.

Tasks compatible with the AT command can only have one time trigger.

Tasks compatible with Task Scheduler 1.0 can only have a time trigger, a logon trigger, or a boot trigger, and the task can only have an executable action.

For more information about task compatibility, see [What's New in Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/what-s-new-in-task-scheduler) and [Tasks](https://learn.microsoft.com/windows/desktop/TaskSchd/tasks).

## See also

[ITaskSettings](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itasksettings)

[TASK_COMPATIBILITY](https://learn.microsoft.com/windows/desktop/api/taskschd/ne-taskschd-task_compatibility)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)