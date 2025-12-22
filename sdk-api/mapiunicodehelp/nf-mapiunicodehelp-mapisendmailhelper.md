# MAPISendMailHelper function

## Description

Takes Unicode message information and sends the message using [MAPISendMailW](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapisendmailw) or, if necessary, converts the message to ANSI and sends the message using [MAPISendMail](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapisendmail). **On Windows 8 and later:** Call [MAPISendMailW](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapisendmailw) directly to send a message.

## Parameters

### `lhSession` [in]

Handle to a Simple MAPI session or zero.

If the value of the *lhSession* parameter is zero, MAPI logs on the user and creates a session that exists only for the duration of the call. This temporary session can be an existing shared session or a new one. If necessary, the logon dialog box is displayed.

### `ulUIParam` [in]

Parent window handle or zero.

If the value of the *ulUIParam* parameter is zero and a dialog box is displayed, the dialog box is application modal. If the *ulUIParam* parameter contains a parent window handle, it is of type HWND (cast to a **ULONG_PTR**). If no dialog box is displayed during the call, *ulUIParam* is ignored.

### `lpMessage` [in]

Pointer to a [MAPISendMailW](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapisendmailw) structure containing the message to be sent.

If the registered mail provider requires the message to use ANSI encoding, **MAPISendMailHelper** converts this message to the ANSI [MapiMessage](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapimessage) structure calls [MAPISendMail](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapisendmail) to send the message.

When you call the function, please note the following information about message structure members:

| Member | Notes |
| --- | --- |
| **lpFiles** | Set this member to **NULL** when the message does not have file attachments. |
| **lpszMessageType** | Used by applications that do not handle interpersonal messages. If your application handles interpersonal messages, set the **lpszMessageType** member to **NULL** or set it to point to an empty string. |
| **lpszSubject** | A value of **NULL** means that there is no text for the subject of the message. |
| **lpszNoteText** | A value of **NULL** means that there is no text in the body of the message. |
| **lpRecips** | A value of **NULL** means that there are no recipients. Additionally, when this member is **NULL**, the **nRecipCount** member must be zero. |
| **nRecipCount** | A value of zero means that there are no recipients. Additionally, when this member is zero, the **lpRecips** member must be **NULL**. |

**Tip** When you call the function and there are no recipients, you must set either the **MAPI_DIALOG** flag or the **MAPI_DIALOG_MODELESS** flag to prompt the user for recipient information.

If either **MAPI_DIALOG** or **MAPI_DIALOG_MODELESS** is not set, the **nRecipCount** and **lpRecips** members of the structure must be valid for successful message delivery. Client applications can set the **flFlags** member to **MAPI_RECEIPT_REQUESTED** to request a read report.

For more details about how the function handles recipient information, see [Handling recipient information](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapisendmailw) in **MAPISendMailW**.

### `flFlags` [in]

Bitmask of option flags. The following flags can be set.

| Value | Meaning |
| --- | --- |
| **MAPI_DIALOG**<br><br>0x00000008 | A dialog box should be displayed to prompt the user for recipients and other sending options.<br><br>If neither **MAPI_DIALOG** nor **MAPI_DIALOG_MODELESS** is set, at least one recipient must be specified. |
| **MAPI_DIALOG_MODELESS**<br><br>0x00000004 \| MAPI_DIALOG | **Available on Windows 7 or earlier with next version of Office:** A modeless dialog box should be displayed to prompt the user for recipients and other sending options.<br><br>If **MAPI_DIALOG_MODELESS** is set, the *lhSession* parameter should be set to zero. Otherwise, if this flag is set and *lhSession* is not zero, Outlook will raise an exception.<br><br>Additionally, if **MAPI_DIALOG_MODELESS** is set, the system ignores the **MAPI_NEW_SESSION** flag.<br><br>If neither **MAPI_DIALOG** nor **MAPI_DIALOG_MODELESS** is set, at least one recipient must be specified. |
| **MAPI_LOGON_UI**<br><br>0x00000001 | A dialog box should be displayed to prompt the user to log on if required.<br><br>If the **MAPI_LOGON_UI** flag is not set, the client application does not display a logon dialog box and returns an error value if the user is not logged on.<br><br>If the *lpszMessageID* parameter is empty, the **MAPI_LOGON_UI** flag is ignored. |
| **MAPI_NEW_SESSION**<br><br>0x00000002 | An attempt is made to create a new session rather than acquire the environment's shared session. If the **MAPI_NEW_SESSION** flag is not set, the function uses an existing, shared session.<br><br>If you set the **MAPI_NEW_SESSION** flag (preventing the use of a shared session) and the profile requires a password, you must also set the **MAPI_LOGON_UI** flag or the function will fail. Your client application can avoid this failure by using the default profile without a password or by using an explicit profile without a password. |
| **MAPI_FORCE_UNICODE**<br><br>0x00040000 | Do not convert the message to ANSI if the provider does not support Unicode. |

### `ulReserved` [in]

Reserved; must be zero.

## Return value

This function returns one of the following values.

| Return code/value | Description |
| --- | --- |
| **MAPI_E_AMBIGUOUS_RECIPIENT**<br><br>21 | A recipient matched more than one of the recipient descriptor structures and MAPI_DIALOG was not set. No message was sent. |
| **MAPI_E_ATTACHMENT_NOT_FOUND**<br><br>11 | The specified attachment was not found. No message was sent. |
| **MAPI_E_ATTACHMENT_OPEN_FAILURE**<br><br>12 | The specified attachment could not be opened. No message was sent. |
| **MAPI_E_BAD_RECIPTYPE**<br><br>15 | The type of a recipient was not MAPI_TO, MAPI_CC, or MAPI_BCC. No message was sent. |
| **MAPI_E_FAILURE**<br><br>2 | One or more unspecified errors occurred. No message was sent. |
| **MAPI_E_INSUFFICIENT_MEMORY**<br><br>5 | There was insufficient memory to proceed. No message was sent. |
| **MAPI_E_INVALID_RECIPS**<br><br>25 | One or more recipients were invalid or did not resolve to any address. |
| **MAPI_E_LOGIN_FAILURE**<br><br>3 | There was no default logon, and the user failed to log on successfully when the logon dialog box was displayed. No message was sent. |
| **MAPI_E_TEXT_TOO_LARGE**<br><br>18 | The text in the message was too large. No message was sent. |
| **MAPI_E_TOO_MANY_FILES**<br><br>9 | There were too many file attachments. No message was sent. |
| **MAPI_E_TOO_MANY_RECIPIENTS**<br><br>10 | There were too many recipients. No message was sent. |
| **MAPI_E_UNICODE_NOT_SUPPORTED**<br><br>27 | The **MAPI_FORCE_UNICODE** flag is specified and Unicode is not supported.<br><br>**Note** This value can be returned only if [MAPISendMailW](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapisendmailw) is called to send the message. |
| **MAPI_E_UNKNOWN_RECIPIENT**<br><br>14 | A recipient did not appear in the address list. No message was sent. |
| **MAPI_E_USER_ABORT**<br><br>1 | The user canceled one of the dialog boxes. No message was sent. |
| **SUCCESS_SUCCESS**<br><br>0 | The call succeeded and the message was sent. |

## Remarks

For more information about MAPI send mail functions, see [MAPISendMailW](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapisendmailw).

## See also

[MAPISendMailW](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapisendmailw)

[Windows SDK for Windows 8](https://msdn.microsoft.com/windows/desktop/hh852363.aspx)