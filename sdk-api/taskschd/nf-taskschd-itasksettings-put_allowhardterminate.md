# ITaskSettings::put_AllowHardTerminate

## Description

Gets or sets a Boolean value that indicates that the task may be terminated by the Task Scheduler service using [TerminateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-terminateprocess). The service will try to close the running task by sending the [WM_CLOSE](https://learn.microsoft.com/windows/desktop/winmsg/wm-close) notification, and if the task does not respond, the task will be terminated only if this property is set to true.

This property is read/write.

## Parameters

## Remarks

When reading or writing XML for a task, this setting is specified in the [AllowHardTerminate](https://learn.microsoft.com/windows/desktop/TaskSchd/taskschedulerschema-allowhardterminate-settingstype-element) element of the Task Scheduler schema.

## See also

[ITaskSettings](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itasksettings)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)

TaskSettings