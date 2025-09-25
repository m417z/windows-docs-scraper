# SendToFaxRecipient function

## Description

Called by an application to fax a file.

## Parameters

### `sndMode`

Type: **[SendToMode](https://learn.microsoft.com/previous-versions/windows/desktop/api/fxsutility/ne-fxsutility-sendtomode)**

A value specifying how to send the fax. For Windows Vista, this must be [SEND_TO_FAX_RECIPIENT_ATTACHMENT](https://learn.microsoft.com/previous-versions/windows/desktop/api/fxsutility/ne-fxsutility-sendtomode).

### `lpFileName`

Type: **LPCWSTR**

Pointer to a constant null-terminated string representing the name of the file to fax.

## Return value

Type: **DWORD**

Zero, if the operation is successful.

## Remarks

Call [CanSendToFaxRecipient](https://learn.microsoft.com/previous-versions/windows/desktop/api/fxsutility/nf-fxsutility-cansendtofaxrecipient) first to determine if faxing from within an application is possible on the computer.

## See also

[CanSendToFaxRecipient](https://learn.microsoft.com/previous-versions/windows/desktop/api/fxsutility/nf-fxsutility-cansendtofaxrecipient)

[SendToMode](https://learn.microsoft.com/previous-versions/windows/desktop/api/fxsutility/ne-fxsutility-sendtomode)

[Shell Fax Extension Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-shell-fax-extension-functions)