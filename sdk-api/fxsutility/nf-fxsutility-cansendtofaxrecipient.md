# CanSendToFaxRecipient function

## Description

Called by an application to determine whether to make a menu item or other UI available that calls the Windows Vista function [SendToFaxRecipient](https://learn.microsoft.com/previous-versions/windows/desktop/api/fxsutility/nf-fxsutility-sendtofaxrecipient).

## Return value

Type: **BOOL**

**TRUE**, if the following conditions are met; otherwise **FALSE**.

* The operating system is Windows Vista or later.
* The fax service is installed.
* The current user has a fax account setup with the fax service.

## Remarks

Typically, this function is called when the application launches.

## See also

[SendToFaxRecipient](https://learn.microsoft.com/previous-versions/windows/desktop/api/fxsutility/nf-fxsutility-sendtofaxrecipient)

[Shell Fax Extension Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-shell-fax-extension-functions)