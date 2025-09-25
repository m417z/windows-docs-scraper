# MAPIRESOLVENAME callback function

## Description

[The use of this function is discouraged. It may be altered or unavailable in subsequent versions of Windows.]

The **MAPIResolveName** function transforms a message recipient's name as entered by a user to an unambiguous address list entry.

## Parameters

### `lhSession` [in]

Handle that represents a Simple MAPI session or zero. If the value of the *lhSession* parameter is zero, MAPI logs on the user and creates a session that exists only for the duration of the call. This temporary session can be an existing shared session or a new one. If necessary, the logon dialog box is displayed.

### `ulUIParam` [in]

Parent window handle or zero, indicating that if a dialog box is displayed, it is application modal. If the *ulUIParam* parameter contains a parent window handle, it is of type **HWND** (cast to a **ULONG_PTR**). If no dialog box is displayed during the call,  *ulUIParam* is ignored.

### `lpszName` [in]

Pointer to the name to be resolved.

### `flFlags` [in]

Bitmask of option flags. The following flags can be set.

| Value | Meaning |
| --- | --- |
| **MAPI_AB_NOMODIFY** | The caller is requesting that the dialog box be read-only, prohibiting changes. **MAPIResolveName** ignores this flag if MAPI_DIALOG is not set. |
| **MAPI_DIALOG** | A dialog box should be displayed for name resolution. If this flag is not set and the name cannot be resolved, **MAPIResolveName** returns the MAPI_E_AMBIGUOUS_RECIPIENT value. |
| **MAPI_LOGON_UI** | A dialog box should be displayed to prompt the user to log on if required. When the MAPI_LOGON_UI flag is not set, the client application does not display a logon dialog box and returns an error value if the user is not logged on. |
| **MAPI_NEW_SESSION** | An attempt should be made to create a new session rather than acquire the environment's shared session. If the MAPI_NEW_SESSION flag is not set, **MAPIResolveName** uses an existing shared session. |

### `ulReserved`

Reserved; must be zero.

### `*lppRecip` [out]

Pointer to a recipient structure if the resolution results in a single match. The recipient structure contains the resolved name and related information. Memory for this structure must be freed using the [MAPIFreeBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nf-mapi-mapifreebuffer) function.

## Return value

This function returns one of the following values.

| Return code | Description |
| --- | --- |
| **MAPI_E_AMBIGUOUS_RECIPIENT** | The recipient requested has not been or could not be resolved to a unique address list entry. |
| **MAPI_E_UNKNOWN_RECIPIENT** | The recipient could not be resolved to any address. The recipient might not exist or might be unknown. |
| **MAPI_E_FAILURE** | One or more unspecified errors occurred. The name was not resolved. |
| **MAPI_E_INSUFFICIENT_MEMORY** | There was insufficient memory to proceed. The name was not resolved. |
| **MAPI_E_LOGIN_FAILURE** | There was no default logon, and the user failed to log on successfully when the logon dialog box was displayed. The name was not resolved. |
| **MAPI_E_NOT_SUPPORTED** | The operation was not supported by the underlying messaging system. |
| **MAPI_E_USER_ABORT** | The user canceled one of the dialog boxes. The name was not resolved. |
| **SUCCESS_SUCCESS** | The call succeeded and the name was resolved. |

## Remarks

The **MAPIResolveName** function resolves a message recipient's name (as entered by a user) to an unambiguous address list entry, optionally prompting the user to choose between possible entries, if necessary. A recipient descriptor structure containing fully resolved information about the entry is allocated and returned. The caller should free this [MapiRecipDesc](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapirecipdesc) structure at some point by calling the [MAPIFreeBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nf-mapi-mapifreebuffer) function. If **MAPIResolveName** returns an error value, it is not necessary to deallocate memory with **MAPIFreeBuffer**.

## See also

[MAPIFreeBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nf-mapi-mapifreebuffer)

[MAPILogon](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapilogon)

[MapiRecipDesc](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapirecipdesc)

[Simple MAPI](https://learn.microsoft.com/previous-versions/dd296734(v=vs.85))