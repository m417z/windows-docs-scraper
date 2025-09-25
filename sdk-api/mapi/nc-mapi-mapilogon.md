# MAPILOGON callback function

## Description

[The use of this function is discouraged. It may be altered or unavailable in subsequent versions of Windows.]

The **MAPILogon** function begins a Simple MAPI session, loading the default message store and address book providers.

## Parameters

### `ulUIParam` [in]

Parent window handle or zero, indicating that if a dialog box is displayed, it is application modal. If the *ulUIParam* parameter contains a parent window handle, it is of type HWND (cast to a ULONG_PTR). If no dialog box is displayed during the call,  *ulUIParam* is ignored.

### `lpszProfileName` [in, optional]

Pointer to a **null**-terminated profile name string, limited to 256 characters or less. This is the profile to use when logging on. If the *lpszProfileName* parameter is **NULL** or points to an empty string, and the *flFlags* parameter is set to MAPI_LOGON_UI, **MAPILogon** displays a logon dialog box with an empty name field.

### `lpszPassword` [in, optional]

Pointer to a **null**-terminated credential string, limited to 256 characters or less. If the messaging system does not require password credentials, or if it requires that the user enter them, the *lpszPassword* parameter should be **NULL** or point to an empty string. When the user must enter credentials, the *flFlags* parameter must be set to MAPI_LOGON_UI to allow a logon dialog box to be displayed.

### `flFlags` [in]

Bitmask of option flags. The following flags can be set.

| Value | Meaning |
| --- | --- |
| **MAPI_FORCE_DOWNLOAD** | An attempt should be made to download all of the user's messages before returning. If the MAPI_FORCE_DOWNLOAD flag is not set, messages can be downloaded in the background after the function call returns. |
| **MAPI_NEW_SESSION** | An attempt should be made to create a new session rather than acquire the environment's shared session. If the MAPI_NEW_SESSION flag is not set, **MAPILogon** uses an existing shared session. |
| **MAPI_LOGON_UI** | A logon dialog box should be displayed to prompt the user for logon information. If the user needs to provide a password and profile name to enable a successful logon, MAPI_LOGON_UI must be set. |
| **MAPI_PASSWORD_UI** | **MAPILogon** should only prompt for a password and not allow the user to change the profile name. Either MAPI_PASSWORD_UI or MAPI_LOGON_UI should not be set, since the intent is to select between two different dialog boxes for logon. |

### `ulReserved`

Reserved; must be zero.

### `lplhSession` [out]

Simple MAPI session handle.

## Return value

This function returns one of the following values.

| Return code | Description |
| --- | --- |
| **MAPI_E_FAILURE** | One or more unspecified errors occurred during logon. No session handle was returned. |
| **MAPI_E_INSUFFICIENT_MEMORY** | There was insufficient memory to proceed. No session handle was returned. |
| **MAPI_E_LOGIN_FAILURE** | There was no default logon, and the user failed to log on successfully when the logon dialog box was displayed. No session handle was returned. |
| **MAPI_E_TOO_MANY_SESSIONS** | The user had too many sessions open simultaneously. No session handle was returned. |
| **MAPI_E_USER_ABORT** | The user canceled the logon dialog box. No session handle was returned. |
| **SUCCESS_SUCCESS** | The call succeeded and a Simple MAPI session was established. |

## Remarks

The **MAPILogon** function begins a session with the messaging system, returning a handle that can be used in subsequent MAPI calls to explicitly provide user credentials to the messaging system. To request the display of a logon dialog box if the credentials presented fail to validate the session, set the *flFlags* parameter to MAPI_LOGON_UI.

The client application tests for an existing session by calling **MAPILogon** with a **NULL** value for the *lpszProfileName* parameter, a **NULL** value for the *lpszPassword* parameter and by not setting the MAPI_LOGON_UI flag in *flFlags*. If there is an existing session, the call succeeds and returns a valid LHANDLE for the session. Otherwise, the call fails.

## See also

[MAPILogoff](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapilogoff)

[Simple MAPI](https://learn.microsoft.com/previous-versions/dd296734(v=vs.85))