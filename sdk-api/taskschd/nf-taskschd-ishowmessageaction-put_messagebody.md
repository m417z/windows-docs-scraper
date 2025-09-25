# IShowMessageAction::put_MessageBody

## Description

[This interface is no longer supported. You can use IExecAction with the Windows scripting [MsgBox function](https://learn.microsoft.com/previous-versions/sfw6660x(v=vs.85)) to show a message in the user session.]

Gets or sets the message text that is displayed in the body of the message box.

This property is read/write.

## Parameters

## Remarks

Parameterized strings can be used in the message text of the message box. For more information, see the Examples section in [ValueQueries](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-ieventtrigger-get_valuequeries) property of [IEventTrigger](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-ieventtrigger).

When setting this property value, the value can be text that is retrieved from a resource .dll file. A specialized string is used to reference the text from the resource file. The format of the string is $(@ [Dll], [ResourceID]) where [Dll] is the path to the .dll file that contains the resource and [ResourceID] is the identifier for the resource text. For example, the setting this property value to $(@ %SystemRoot%\System32\ResourceName.dll, -101) will set the property to the value of the resource text with an identifier equal to -101 in the %SystemRoot%\System32\ResourceName.dll file.

## See also

[IShowMessageAction](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-ishowmessageaction)