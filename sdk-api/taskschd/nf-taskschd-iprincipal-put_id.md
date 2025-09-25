# IPrincipal::put_Id

## Description

Gets or sets the identifier of the principal.

This property is read/write.

## Parameters

## Remarks

This identifier is also used when specifying the [IActionCollection::Context](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-iactioncollection-get_context) property.

When reading or writing XML for a task, the identifier of the principal is specified in the Id attribute of the [Principal](https://learn.microsoft.com/windows/desktop/TaskSchd/taskschedulerschema-principal-principaltype-element) element of the Task Scheduler schema.

## See also

[IActionCollection.Context](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-iactioncollection-get_context)

[IPrincipal](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iprincipal)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)