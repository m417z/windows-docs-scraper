# IEmailAction::put_Server

## Description

[This interface is no longer supported. Please use IExecAction with the powershell [Send-MailMessage](https://learn.microsoft.com/powershell/module/microsoft.powershell.utility/send-mailmessage) cmdlet as a workaround.]

Gets or sets the name of the SMTP server that you use to send email from.

This property is read/write.

## Parameters

## Remarks

Make sure the SMTP server that sends the email is setup correctly. E-mail is sent using NTLM authentication for Windows SMTP servers, which means that the security credentials used for running the task must also have privileges on the SMTP server to send email message. If the SMTP server is a non-Windows based server, then the email will be sent if the server allows anonymous access. For information about setting up the SMTP server, see [SMTP Server Setup](https://www.microsoft.com/technet/prodtechnol/WindowsServer2003/Library/IIS/e4cf06f5-9a36-474b-ba78-3f287a2b88f2.mspx?mfr=true), and for information about managing SMTP server settings, see [SMTP Administration](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2003/cc758258(v=ws.10)).

## See also

[IEmailAction](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iemailaction)