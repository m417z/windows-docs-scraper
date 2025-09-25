# WLX_CLIENT_CREDENTIALS_INFO_V2_0 structure

## Description

The **WLX_CLIENT_CREDENTIALS_INFO_V2_0** structure contains the client [credentials](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) returned by a call to
[WlxQueryTsLogonCredentials](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_query_ts_logon_credentials).

The [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) DLL is responsible for calling
[LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) to free the resources used by this structure when the structure is no longer needed.

## Members

### `dwType`

Specifies the type of [credentials](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) structure allocated by the GINA DLL. Credential types are defined with the prefix WLX_CREDENTIAL_TYPE_xxx.

### `pszUserName`

A pointer to the name of the account logged onto.

### `pszDomain`

A pointer to the name of the domain used to log on.

### `pszPassword`

A pointer to the plaintext password of the user account. When you have finished using *pszPassword*, clear the sensitive information from memory by calling the [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)) function.

For more information about protecting passwords, see [Handling Passwords](https://learn.microsoft.com/windows/desktop/SecBP/handling-passwords).

### `fPromptForPassword`

Forces a prompt for the password due to an administration override. This allows the distinction of auto logon with no password.

### `fDisconnectOnLogonFailure`

Determines whether GINA allows the user to supply different credentials if the logon fails. If *fDisconnectOnLogonFailure* is **TRUE** and the logon fails, [WlxLoggedOutSAS](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxloggedoutsas) should return WLX_SAS_ACTION_LOGOFF. This will cause [Winlogon](https://learn.microsoft.com/windows/desktop/SecGloss/w-gly) to terminate the session. If *fDisconnectOnLogonFailure* is **FALSE** and the logon fails, GINA can allow the user to submit different credentials.

## See also

[WlxQueryTsLogonCredentials](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_query_ts_logon_credentials)