# MAPIDELETEMAIL callback function

## Description

[The use of this function is discouraged. It may be altered or unavailable in subsequent versions of Windows.]

The **MAPIDeleteMail** function deletes a message.

## Parameters

### `lhSession` [in]

Session handle that represents a valid Simple MAPI session. The value of the *lhSession* parameter must represent a valid session; it cannot be zero.

### `ulUIParam` [in]

Parent window handle or zero, indicating that if a dialog box is displayed, it is application modal. If the *ulUIParam* parameter contains a parent window handle, it is of type HWND (cast to a ULONG_PTR). If no dialog box is displayed during the call,  *ulUIParam* is ignored.

### `lpszMessageID` [in]

The identifier for the message to be deleted. This identifier is messaging system-specific and will be invalid when **MAPIDeleteMail** successfully returns.

### `flFlags`

Reserved; must be zero.

### `ulReserved`

Reserved; must be zero.

## Return value

This function returns one of the following values.

| Return code | Description |
| --- | --- |
| **MAPI_E_FAILURE** | One or more unspecified errors occurred while deleting the message. No message was deleted. |
| **MAPI_E_INSUFFICIENT_MEMORY** | There was insufficient memory to proceed. No message was deleted. |
| **MAPI_E_INVALID_MESSAGE** | An invalid message identifier was passed in the *lpszMessageID* parameter. No message was deleted. |
| **MAPI_E_INVALID_SESSION** | An invalid session handle was passed in the *lhSession* parameter. No message was deleted. |
| **SUCCESS_SUCCESS** | The call succeeded and the message was deleted. |

## See also

[MAPIFindNext](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapifindnext)

[MAPILogon](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapilogon)

[MAPISaveMail](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapisavemail)

[Simple MAPI](https://learn.microsoft.com/previous-versions/dd296734(v=vs.85))