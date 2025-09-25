# MAPISAVEMAIL callback function

## Description

[The use of this function is discouraged. It may be altered or unavailable in subsequent versions of Windows.]

The **MAPISaveMail** function saves a message into the message store.

## Parameters

### `lhSession` [in]

Handle for a Simple MAPI session or zero. The value of the *lhSession* parameter must not be zero if the *lpszMessageID* parameter contains a valid message identifier. However, if *lpszMessageID* does not contain a valid message identifier, and the value of *lhSession* is zero, MAPI logs on the user and creates a session that exists only for the duration of the call. This temporary session can be an existing shared session or a new one. If necessary, the logon dialog box is displayed.

### `ulUIParam` [in]

Parent window handle or zero, indicating that if a dialog box is displayed, it is application modal. If the *ulUIParam* parameter contains a parent window handle, it is of type **HWND** (cast to a **ULONG_PTR**). If no dialog box is displayed during the call, *ulUIParam* is ignored.

### `lpMessage` [in]

Input parameter pointing to a [MapiMessage](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapimessage) structure containing the contents of the message to be saved. The **lpOriginator** member is ignored. Applications can either ignore the **flFlags** member, or if the message has never been saved, can set the MAPI_SENT and MAPI_UNREAD flags.

### `flFlags` [in]

Bitmask of option flags. The following flags can be set.

| Value | Meaning |
| --- | --- |
| **MAPI_LOGON_UI** | A dialog box should be displayed to prompt the user to logon if required. When the MAPI_LOGON_UI flag is not set, the client application does not display a logon dialog box and returns an error value if the user is not logged on. **MAPISaveMail** ignores this flag if the *lpszMessageID* parameter is empty. |
| **MAPI_LONG_MSGID** | The returned message identifier is expected to be 512 characters. If this flag is set, the *lpszMessageID* parameter must be large enough to accommodate 512 characters. |
| **MAPI_NEW_SESSION** | An attempt should be made to create a new session rather than acquire the environment's shared session. If the MAPI_NEW_SESSION flag is not set, **MAPISaveMail** uses an existing shared session. |

### `ulReserved`

Reserved; must be zero.

### `lpszMessageID` [in]

Pointer to either the message identifier to be replaced by the save operation or an empty string, indicating that a new message is to be created. The string must be allocated by the caller and must be able to hold at least 512 characters if the *flFlags* parameter is set to MAPI_LONG_MSGID. If the *flFlags* parameter is not set to MAPI_LONG_MSGID, the message identifier string can hold 64 characters.

## Return value

This function returns one of the following values.

| Return code | Description |
| --- | --- |
| **MAPI_E_ATTACHMENT_NOT_FOUND** | An attachment could not be located at the specified path. Either the drive letter was invalid, the path was not found on that drive, or the file was not found in that path. |
| **MAPI_E_BAD_RECIPTYPE** | The recipient type in the *lpMessage* was invalid. |
| **MAPI_E_FAILURE** | One or more unspecified errors occurred while saving the message. No message was saved. |
| **MAPI_E_INSUFFICIENT_MEMORY** | There was insufficient memory to save the message. No message was saved. |
| **MAPI_E_INVALID_MESSAGE** | An invalid message identifier was passed in the *lpszMessageID* parameter; no message was saved. |
| **MAPI_E_INVALID_RECIPS** | One or more recipients of the message were invalid or could not be identified. |
| **MAPI_E_INVALID_SESSION** | An invalid session handle was passed in the *lhSession* parameter. No message was saved. |
| **MAPI_E_LOGIN_FAILURE** | There was no default logon, and the user failed to log on successfully when the logon dialog box was displayed. No message was saved. |
| **MAPI_E_NOT_SUPPORTED** | The operation was not supported by the underlying messaging system. |
| **MAPI_E_USER_ABORT** | The user canceled one of the dialog boxes. No message was saved. |
| **SUCCESS_SUCCESS** | The call succeeded and the message was saved. |

## Remarks

The **MAPISaveMail** function saves a message, optionally replacing an existing message. Before calling **MAPISaveMail**, use the [MAPIFindNext](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapifindnext) function to verify that the message to be saved is the one you want saved. The elements of the message identified by the *lpszMessageID* parameter are replaced by the elements in the *lpMessage* parameter. If *lpszMessageID* is empty, a new message is created. All replaced messages are saved in their appropriate folders. New messages are saved in the folder appropriate for incoming messages of that class.

Not all messaging systems support storing messages. If the underlying messaging system does not support message storage, **MAPISaveMail** returns the MAPI_E_NOT_SUPPORTED value.

Because message identifiers are system-specific and opaque and can be invalidated at any time, **MAPISaveMail** considers a message identifier to be valid only for the current Simple MAPI session. **MAPISaveMail** handles invalid message identifiers by returning the MAPI_E_INVALID_MESSAGE value.

## See also

[MAPIFindNext](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapifindnext)

[MAPILogon](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapilogon)

[MapiMessage](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapimessage)

[Simple MAPI](https://learn.microsoft.com/previous-versions/dd296734(v=vs.85))