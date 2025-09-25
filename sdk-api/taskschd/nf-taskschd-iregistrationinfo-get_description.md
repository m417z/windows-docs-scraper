# IRegistrationInfo::get_Description

## Description

Gets or sets the description of the task.

This property is read/write.

## Parameters

## Remarks

When reading or writing XML for a task, the description of the task is specified using the [Description](https://learn.microsoft.com/windows/desktop/TaskSchd/taskschedulerschema-description-registrationinfotype-element) element of the Task Scheduler schema.

When setting this property value, the value can be text that is retrieved from a resource .dll file. A specialized string is used to reference the text from the resource file. The format of the string is $(@ [Dll], [ResourceID]) where [Dll] is the path to the .dll file that contains the resource and [ResourceID] is the identifier for the resource text. For example, the setting this property value to $(@ %SystemRoot%\System32\ResourceName.dll, -101) will set the property to the value of the resource text with an identifier equal to -101 in the %SystemRoot%\System32\ResourceName.dll file.

## See also

[IRegistrationInfo](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iregistrationinfo)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)