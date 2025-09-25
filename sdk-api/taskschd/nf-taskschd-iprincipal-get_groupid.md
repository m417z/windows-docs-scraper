# IPrincipal::get_GroupId

## Description

Gets or sets the identifier of the user group that is required to run the tasks that are associated with the principal.

This property is read/write.

## Parameters

## Remarks

Do not set this property if a user identifier is specified in the [UserId](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-iprincipal-get_userid) property.

When reading or writing XML for a task, the group identifier for a principal is specified in the [GroupId](https://learn.microsoft.com/windows/desktop/TaskSchd/taskschedulerschema-groupid-principaltype-element) element of the Task Scheduler schema.

## See also

[IPrincipal](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iprincipal)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)

[UserId](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-iprincipal-get_userid)