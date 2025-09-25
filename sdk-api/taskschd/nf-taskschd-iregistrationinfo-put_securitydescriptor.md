# IRegistrationInfo::put_SecurityDescriptor

## Description

Gets or sets the security descriptor of the task. If a different security descriptor is supplied during task registration, it will supersede the security descriptor that is set with this property.

This property is read/write.

## Parameters

## Remarks

When reading or writing XML for a task, the security descriptor of the task is specified using the [SecurityDescriptor](https://learn.microsoft.com/windows/desktop/TaskSchd/taskschedulerschema-securitydescriptor-registrationinfotype-element) element of the Task Scheduler schema.

If a different security descriptor is supplied when a task is registered, then it will supersede the *sddl* parameter that is set through this property.

If you try to pass an invalid security descriptor into the *sddl* parameter, then this method will return **E_INVALIDARG**.

## See also

[IRegistrationInfo](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iregistrationinfo)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)