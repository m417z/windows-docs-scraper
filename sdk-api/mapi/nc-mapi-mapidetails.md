# MAPIDETAILS callback function

## Description

[The use of this function is discouraged. It may be altered or unavailable in subsequent versions of Windows.]

The **MAPIDetails** function displays a dialog box containing the details of a selected address list entry.

## Parameters

### `lhSession` [in]

Session handle that represents a Simple MAPI session or zero. If the value of the *lhSession* parameter is zero, MAPI logs on the user and creates a session that exists only for the duration of the call. This temporary session can be an existing shared session or a new one. If additional information is required from the user to successfully complete the logon, a dialog box is displayed.

### `ulUIParam` [in]

Parent window handle or zero, indicating that if a dialog box is displayed, it is application modal. If the *ulUIParam* parameter contains a parent window handle, it is of type HWND (cast to a ULONG_PTR). If no dialog box is displayed during the call,  *ulUIParam* is ignored.

### `lpRecip` [in]

Pointer to the recipient for which details are to be displayed. **MAPIDetails** ignores all members of this [MapiRecipDesc](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapirecipdesc) structure except the **ulEIDSize** and **lpEntryID** members. If the value of **ulEIDSize** is nonzero, **MAPIDetails** resolves the recipient entry. If the value of **ulEIDSize** is zero, **MAPIDetails** returns the MAPI_E_AMBIGUOUS_RECIP value.

### `flFlags` [in]

Bitmask of option flags. The following flags can be set.

| Value | Meaning |
| --- | --- |
| **MAPI_AB_NOMODIFY** | The caller is requesting that the dialog box be read-only, prohibiting changes. **MAPIDetails** might or might not honor the request. |
| **MAPI_LOGON_UI** | A dialog box should be displayed to prompt the user to log on if required. When the MAPI_LOGON_UI flag is not set, the client application does not display a logon dialog box and returns an error value if the user is not logged on. |
| **MAPI_NEW_SESSION** | An attempt should be made to create a new session rather than acquire the environment's shared session. If the MAPI_NEW_SESSION flag is not set, **MAPIDetails** uses an existing shared session. |

### `ulReserved`

Reserved; must be zero.

## Return value

This function returns one of the following values.

| Return code | Description |
| --- | --- |
| **MAPI_E_AMBIGUOUS_RECIPIENT** | The dialog box could not be displayed because the **ulEIDSize** member of the structure pointed to by the *lpRecips* parameter was zero. |
| **MAPI_E_FAILURE** | One or more unspecified errors occurred. No dialog box was displayed. |
| **MAPI_E_INSUFFICIENT_MEMORY** | There was insufficient memory to proceed. No dialog box was displayed. |
| **MAPI_E_INVALID_RECIPS** | The recipient specified in the *lpRecip* parameter was unknown or the recipient had an invalid **ulEIDSize** value. No dialog box was displayed. |
| **MAPI_E_LOGIN_FAILURE** | There was no default logon, and the user failed to log on successfully when the logon dialog box was displayed. No dialog box was displayed. |
| **MAPI_E_NOT_SUPPORTED** | The operation was not supported by the underlying messaging system. |
| **MAPI_E_USER_ABORT** | The user canceled either the logon dialog box or the details dialog box. |
| **SUCCESS_SUCCESS** | The call succeeded and the details dialog box was displayed. |

## Remarks

The **MAPIDetails** function presents a dialog box that shows the details of a particular address list entry. The display name and address are the minimum attributes that are displayed in the dialog box; more information can be shown, depending on the address book provider. The details dialog box cannot be suppressed, but the caller can request that it be read-only or modifiable.

Details can only be shown for resolved address list entries. An entry is resolved if the value of the **ulEIDSize** member of the [MapiRecipDesc](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapirecipdesc) structure is nonzero. Entries are resolved when they are returned by the [MAPIAddress](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapiaddress) or [MAPIResolveName](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapiresolvename) functions and as the result being recipients of read mail.

## See also

[MAPIAddress](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapiaddress)

[MAPILogon](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapilogon)

[MAPIResolveName](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapiresolvename)

[MapiRecipDesc](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapirecipdesc)

[Simple MAPI](https://learn.microsoft.com/previous-versions/dd296734(v=vs.85))