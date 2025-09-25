# ILogonTrigger::put_UserId

## Description

Gets or sets the identifier of the user.

This property is read/write.

## Parameters

## Remarks

If you want a task to be triggered when any member of a group logs on to the computer rather than when a specific user logs on, then do not assign a value to the **UserId** property. Instead, create a logon trigger with an empty **UserId** property and assign a value to the principal for the task using the [GroupId](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-iprincipal-get_groupid) property.

When reading or writing XML for a task, the logon user identifier is specified using the [UserId](https://learn.microsoft.com/windows/desktop/TaskSchd/taskschedulerschema-userid-logontriggertype-element) element of the Task Scheduler schema.

## See also

[ILogonTrigger](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-ilogontrigger)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)