# PWLX_QUERY_TS_LOGON_CREDENTIALS callback function

## Description

Called by a replacement
[GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) DLL to retrieve [credentials](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) information if Terminal Services is enabled.
The GINA DLL can then use this information to fill in a logon box automatically and attempt to log the user in.

**Note** GINA DLLs are ignored in Windows Vista.

## Parameters

### `pCred` [out]

When the return value is **TRUE**, *pCred* specifies a pointer to a [WLX_CLIENT_CREDENTIALS_INFO_V2_0](https://learn.microsoft.com/windows/win32/api/winwlx/ns-winwlx-wlx_client_credentials_info_v2_0) structure that contains the credentials to use for auto logon.

## Return value

The **WlxQueryTsLogonCredentials** function returns one of the following values.

| Return code | Description |
| --- | --- |
| **TRUE** | The credentials information was retrieved and returned in *pCred*. |
| **FALSE** | The credentials information was not retrieved. |

## Remarks

This function supersedes the [WlxQueryClientCredentials](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_query_client_credentials) and [WlxQueryInetConnectorCredentials](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_query_ic_credentials) functions.

To access this function, the GINA DLL must use the
[WLX_DISPATCH_VERSION_1_4](https://learn.microsoft.com/windows/desktop/api/winwlx/ns-winwlx-wlx_dispatch_version_1_4) structure and set the Winlogon version to at least WLX_VERSION_1_4 in its
[WlxNegotiate](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxnegotiate) call.

Other Winlogon support functions that may be called when Terminal Services is enabled are [WlxDisconnect](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_disconnect), [WlxQueryClientCredentials](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_query_client_credentials),
[WlxQueryTerminalServicesData](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_query_terminal_services_data), and
[WlxWin31Migrate](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_win31_migrate).

## See also

[WLX_CLIENT_CREDENTIALS_INFO_V2_0](https://learn.microsoft.com/windows/win32/api/winwlx/ns-winwlx-wlx_client_credentials_info_v2_0)

[WlxDisconnect](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_disconnect)

[WlxQueryClientCredentials](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_query_client_credentials)

[WlxQueryTerminalServicesData](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_query_terminal_services_data)

[WlxWin31Migrate](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_win31_migrate)