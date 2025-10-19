# MAPISENDMAILW callback function

## Description

Sends a Unicode message. This function replaces the ANSI function [MAPISendMail](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapisendmail).

**On Windows 7 and earlier:** Install the [Microsoft Windows Software Development Kit (SDK) for Windows 8](https://msdn.microsoft.com/windows/desktop/hh852363.aspx) and use [MAPISendMailHelper](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapiunicodehelp/nf-mapiunicodehelp-mapisendmailhelper) to send a message.

All information applies to both **MAPISendMailW** and [MAPISendMail](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapisendmail) unless otherwise specified.

## Parameters

### `lhSession` [in]

Type: **LHANDLE**

Handle to a Simple MAPI session or zero.

If the value of the *lhSession* parameter is zero, MAPI logs on the user and creates a session that exists only for the duration of the call. This temporary session can be an existing shared session or a new one. If necessary, the logon dialog box is displayed.

### `ulUIParam` [in]

Type: **[ULONG_PTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Parent window handle or zero.

If the *ulUIParam* parameter contains the parent window handle, the handle is type HWND (cast to a **ULONG_PTR**).

If no dialog box is displayed during the call, *ulUIParam* is ignored.

### `lpMessage` [in]

Type: **lpMapiMessageW**

Pointer to a **MAPISendMailW** structure containing the message to be sent.

**Note** For the [MAPISendMail](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapisendmail) function, this parameter points to a [MapiMessage](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapimessage) structure.

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

For more details about how the function handles recipient information, see [Handling Recipient Information](https://learn.microsoft.com/) in *Remarks*.

### `flFlags` [in]

Type: **FLAGS**

Bitmask of option flags. The following flags can be set.

| Value | Meaning |
| --- | --- |
| **MAPI_DIALOG**<br><br>0x00000008 | A application modal dialog box should be displayed to prompt the user for recipients and other sending options.<br><br>If neither **MAPI_DIALOG** nor **MAPI_DIALOG_MODELESS** is set, at least one recipient must be specified. |
| **MAPI_DIALOG_MODELESS**<br><br>0x00000004 | MAPI_DIALOG | **Available on Windows with next version of Office:** <br><br>A modeless dialog box should be displayed to prompt the user for recipients and other sending options.<br><br>If **MAPI_DIALOG_MODELESS** is set, the *lhSession* parameter should be set to zero. Otherwise, if this flag is set and *lhSession* is not zero, Outlook will raise an exception.<br><br>Additionally, if **MAPI_DIALOG_MODELESS** is set, the system ignores the **MAPI_NEW_SESSION** flag.<br><br>If neither **MAPI_DIALOG** nor **MAPI_DIALOG_MODELESS** is set, at least one recipient must be specified.<br><br>**Tip** To use this flag on Windows 7 or earlier you must have both [Windows SDK for Windows 8](https://msdn.microsoft.com/windows/desktop/hh852363.aspx) and next version of Office installed, and you must call [MAPISendMailHelper](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapiunicodehelp/nf-mapiunicodehelp-mapisendmailhelper) instead of **MAPISendMailW**. |
| **MAPI_LOGON_UI**<br><br>0x00000001 | A dialog box should be displayed to prompt the user to log on if required.<br><br>If the **MAPI_LOGON_UI** flag is not set, the client application does not display a logon dialog box and returns an error value if the user is not logged on.<br><br>If the *lpszMessageID* parameter is empty, the **MAPI_LOGON_UI** flag is ignored. |
| **MAPI_NEW_SESSION**<br><br>0x00000002 | An attempt is made to create a new session rather than acquire the environment's shared session. If the **MAPI_NEW_SESSION** flag is not set, the function uses an existing, shared session.<br><br>If you set the **MAPI_NEW_SESSION** flag (preventing the use of a shared session) and the profile requires a password, you must also set the **MAPI_LOGON_UI** flag or the function will fail. Your client application can avoid this failure by using the default profile without a password or by using an explicit profile without a password. |
| **MAPI_FORCE_UNICODE**<br><br>0x00040000 | Do not convert the message to ANSI if the provider does not support Unicode.<br><br>**Note** This flag is available for **MAPISendMailW** only. |

### `ulReserved`

Type: **[ULONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Reserved; must be zero.

## Return value

Type: **[ULONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

This function returns one of the following values.

| Return code/value | Description |
| --- | --- |
| **MAPI_E_AMBIGUOUS_RECIPIENT**<br><br>21 | A recipient matched more than one of the recipient descriptor structures and MAPI_DIALOG was not set. No message was sent. |
| **MAPI_E_ATTACHMENT_NOT_FOUND**<br><br>11 | The specified attachment was not found. No message was sent. |
| **MAPI_E_ATTACHMENT_OPEN_FAILURE**<br><br>12 | The specified attachment could not be opened. No message was sent. |
| **MAPI_E_ATTACHMENT_TOO_LARGE**<br><br>28 | The specified attachment was too large. No message was sent. |
| **MAPI_E_BAD_RECIPTYPE**<br><br>15 | The type of a recipient was not MAPI_TO, MAPI_CC, or MAPI_BCC. No message was sent. |
| **MAPI_E_FAILURE**<br><br>2 | One or more unspecified errors occurred. No message was sent. |
| **MAPI_E_INSUFFICIENT_MEMORY**<br><br>5 | There was insufficient memory to proceed. No message was sent. |
| **MAPI_E_INVALID_RECIPS**<br><br>25 | One or more recipients were invalid or did not resolve to any address. |
| **MAPI_E_LOGIN_FAILURE**<br><br>3 | There was no default logon, and the user failed to log on successfully when the logon dialog box was displayed. No message was sent. |
| **MAPI_E_TEXT_TOO_LARGE**<br><br>18 | The text in the message was too large. No message was sent. |
| **MAPI_E_TOO_MANY_FILES**<br><br>9 | There were too many file attachments. No message was sent. |
| **MAPI_E_TOO_MANY_RECIPIENTS**<br><br>10 | There were too many recipients. No message was sent. |
| **MAPI_E_UNICODE_NOT_SUPPORTED**<br><br>27 | The **MAPI_FORCE_UNICODE** flag is specified and Unicode is not supported.<br><br>**Note** This value can be returned by [MAPISendMailW](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapisendmailw) only. |
| **MAPI_E_UNKNOWN_RECIPIENT**<br><br>14 | A recipient did not appear in the address list. No message was sent. |
| **MAPI_E_USER_ABORT**<br><br>1 | The user canceled one of the dialog boxes. No message was sent. |
| **SUCCESS_SUCCESS**<br><br>0 | The call succeeded and the message was sent. |

## Remarks

The **MAPISendMailW** (Unicode) and [MAPISendMail](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapisendmail) (ANSI) functions both send a standard message, with or without any user interaction. The profile must be configured so that either function can open the default service providers without requiring user interaction.

Neither **MAPISendMailW** nor [MAPISendMail](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapisendmail) requires an originator-type recipient to send a message.

Your client application can provide a full or partial list of recipient names, subject text, file attachments, or message text. If any information is missing, the function you call (either **MAPISendMailW** or [MAPISendMail](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapisendmail)) can prompt the user for the missing information.

If no information is missing, the message can be sent as is or the user can be prompted to verify the information and change values if necessary.

Both **MAPISendMailW** and [MAPISendMail](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapisendmail) differ from the [MAPISendDocuments](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapisenddocuments) function in that they allow greater flexibility in message generation.

### Message text

Some client applications can truncate subject lines that are too long or contain carriage returns, line feeds, or form feeds.

Each paragraph should be terminated with a CR (0x0d), an LF (0x0a), or a CRLF pair (0x0d0a). Both **MAPISendMailW** and [MAPISendMail](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapisendmail) wrap lines as appropriate.

If the text exceeds system limits, the function returns the **MAPI_E_TEXT_TOO_LARGE** value.

### File attachments

The number of attachments per message can be limited in some messaging systems. If this limit is exceeded, the function fails and returns the **MAPI_E_TOO_MANY_FILES** value.

 File attachments are copied to the message before the function returns; therefore, later changes to the files do not affect the contents of the message. The files must be closed when they are copied.

Do not attempt to display attachments outside the range of the message text.

### Recipients

Some messaging systems can limit the number of recipients per message. If the client application passes a non-**NULL** value indicating a number of recipients exceeding the system limit, the function fails and returns the **MAPI_E_TOO_MANY_RECIPIENTS** value.

If your client application sends messages to one or more custom recipients and you want to avoid resolving the names of those recipients, you must specify the address of the custom recipient.

To specify an address of a recipient when you call **MAPISendMailW**, you must set the **lpszAddress** member of the [MapiRecipDescW](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapirecipdescw)
structure that contains the recipient's information to the custom address. This **MapiRecipDescW** structure is included in the array of recipients stored in the **lpRecips** member of the [MapiMessageW](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapimessagew) structure that is passed to the function by the
*lpMessage* parameter.

**Note** To specify the address of a recipient when you call [MAPISendMail](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapisendmail), follow the preceding directions for **MAPISendMailW**, but substitute the [MapiRecipDesc](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapirecipdesc) and [MapiMessage](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapimessage) structures.

A successful return from the function does not necessarily imply recipient validation. The message might not have been sent to all recipients. Depending on the transport provider, recipient validation can be a lengthy process.

### Handling recipient information

The **lpRecips** member of the [MapiMessageW](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapimessagew) or the [MapiMessage](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapimessage) structure can include either an entry identifier, the recipient's name, an address, or a name and address pair. The following table shows how the function handles each case.

| Recipient information | Action |
| --- | --- |
| Entry identifier | No name resolution; the name and address are ignored. |
| Name | Name resolved using the Simple MAPI resolution rules. |
| Address | No name resolution; address is used for both message delivery and for displaying the recipient name. |
| Name and address | No name resolution; name used only for displaying the recipient name. |

## See also

[MAPISendMailHelper](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapiunicodehelp/nf-mapiunicodehelp-mapisendmailhelper)

[Windows SDK for Windows 8](https://msdn.microsoft.com/windows/desktop/hh852363.aspx)