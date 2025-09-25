# WLX_CLIENT_CREDENTIALS_INFO_V1_0 structure

## Description

[The WLX_CLIENT_CREDENTIALS_INFO_V1_0 structure is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **WLX_CLIENT_CREDENTIALS_INFO_V1_0** structure contains the client [credentials](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) returned by a call to
[WlxQueryClientCredentials](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_query_client_credentials) or
[WlxQueryInetConnectorCredentials](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_query_ic_credentials).

This allows a network client session to pass client credentials for automatic logon.

**Note** [WlxQueryClientCredentials](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_query_client_credentials) is called when Terminal Services is enabled.

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

**Windows XP/2000:** [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)) is not supported. Overwrite the memory allocated for *pszPassword* to clear the sensitive information.

For more information about protecting passwords, see [Handling Passwords](https://learn.microsoft.com/windows/desktop/SecBP/handling-passwords).

### `fPromptForPassword`

Forces a prompt for the password due to an administration override. This allows the distinction of auto logon with no password.

## See also

[LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree)

[WlxQueryClientCredentials](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_query_client_credentials)

[WlxQueryInetConnectorCredentials](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_query_ic_credentials)