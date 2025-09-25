# IPrincipal::get_UserId

## Description

Gets or sets the user identifier that is required to run the tasks that are associated with the principal.

This property is read/write.

## Parameters

## Remarks

Do not set this property if a group identifier is specified in the [GroupId](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-iprincipal-get_groupid) property.

When reading or writing XML for a task, the user identifier for a principal is specified in the [UserId](https://learn.microsoft.com/windows/desktop/TaskSchd/taskschedulerschema-userid-principaltype-element) element of the Task Scheduler schema.

## See also

[GroupId Property of IPrincipal](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-iprincipal-get_groupid)

[IPrincipal](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iprincipal)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)