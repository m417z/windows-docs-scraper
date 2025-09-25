# IPrincipal::get_DisplayName

## Description

Gets or sets the name of the principal.

This property is read/write.

## Parameters

## Remarks

When reading or writing XML for a task, the display name for a principal is specified in the [DisplayName](https://learn.microsoft.com/windows/desktop/TaskSchd/taskschedulerschema-displayname-principaltype-element) element of the Task Scheduler schema.

When setting this property value, the value can be text that is retrieved from a resource .dll file. A specialized string is used to reference the text from the resource file. The format of the string is $(@ [Dll], [ResourceID]) where [Dll] is the path to the .dll file that contains the resource and [ResourceID] is the identifier for the resource text. For example, the setting this property value to $(@ %SystemRoot%\System32\ResourceName.dll, -101) will set the property to the value of the resource text with an identifier equal to -101 in the %SystemRoot%\System32\ResourceName.dll file.

## See also

[IPrincipal](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iprincipal)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)