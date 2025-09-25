# IEmailAction::put_Body

## Description

[This interface is no longer supported. Please use IExecAction with the powershell [Send-MailMessage](https://learn.microsoft.com/powershell/module/microsoft.powershell.utility/send-mailmessage) cmdlet as a workaround.]

Gets or sets the body of the email that contains the email message.

This property is read/write.

## Parameters

## Remarks

When setting this property value, the value can be text that is retrieved from a resource .dll file. A specialized string is used to reference the text from the resource file. The format of the string is $(@ [Dll], [ResourceID]) where [Dll] is the path to the .dll file that contains the resource and [ResourceID] is the identifier for the resource text. For example, the setting this property value to $(@ %SystemRoot%\System32\ResourceName.dll, -101) will set the property to the value of the resource text with an identifier equal to -101 in the %SystemRoot%\System32\ResourceName.dll file.

## See also

[IEmailAction](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iemailaction)