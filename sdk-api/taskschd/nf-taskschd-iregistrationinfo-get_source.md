# IRegistrationInfo::get_Source

## Description

Gets or sets where the task originated from. For example, a task may originate from a component, service, application, or user.

This property is read/write.

## Parameters

## Remarks

The Task Scheduler UI uses the source to sort tasks. For example, tasks could be sorted by component, service, application, or user.

When reading or writing XML for a task, the task source information is specified using the [Source](https://learn.microsoft.com/windows/desktop/TaskSchd/taskschedulerschema-source-registrationinfotype-element) element of the Task Scheduler schema.

When setting this property value, the value can be text that is retrieved from a resource .dll file. A specialized string is used to reference the text from the resource file. The format of the string is $(@ [Dll], [ResourceID]) where [Dll] is the path to the .dll file that contains the resource and [ResourceID] is the identifier for the resource text. For example, the setting this property value to $(@ %SystemRoot%\System32\ResourceName.dll, -101) will set the property to the value of the resource text with an identifier equal to -101 in the %SystemRoot%\System32\ResourceName.dll file.

## See also

[IRegistrationInfo](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iregistrationinfo)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)