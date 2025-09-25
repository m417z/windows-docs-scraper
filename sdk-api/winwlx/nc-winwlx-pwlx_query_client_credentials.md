# PWLX_QUERY_CLIENT_CREDENTIALS callback function

## Description

[The WlxQueryClientCredentials function is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **WlxQueryClientCredentials** function is called by a replacement GINA DLL if Terminal Services is enabled.

**Note** GINA DLLs are ignored in Windows Vista.

[GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) calls this function to retrieve the [credentials](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) of remote Terminal Services clients that are not using an Internet connector license.

The GINA DLL can use this information to fill in a logon box automatically and attempt to log the user in.

## Parameters

### `pCred` [out]

Specifies a pointer to a
[WLX_CLIENT_CREDENTIALS_INFO_V1_0](https://learn.microsoft.com/windows/win32/api/winwlx/ns-winwlx-wlx_client_credentials_info_v1_0) structure that contains the credentials of the client on return.

## Return value

The **WlxQueryClientCredentials** function returns one of the following values.

| Return code | Description |
| --- | --- |
| **TRUE** | The credentials information was retrieved and returned in *pCred*. |
| **FALSE** | The credentials information was not retrieved. |

## Remarks

The GINA DLL is responsible for calling
[LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) to free the resources used by this structure when the structure is no longer needed.

In order to access this function, the GINA DLL must use the
[WLX_DISPATCH_VERSION_1_3](https://learn.microsoft.com/windows/desktop/api/winwlx/ns-winwlx-wlx_dispatch_version_1_3) structure, and set the Winlogon version to at least WLX_VERSION_1_3 in its
[WlxNegotiate](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxnegotiate) call.

If the Terminal Services client is using an Internet connector license, the GINA DLL must call
[WlxQueryInetConnectorCredentials](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_query_ic_credentials).

Other Winlogon support functions that may be called when Terminal Services is enabled are [WlxDisconnect](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_disconnect), [WlxQueryInetConnectorCredentials](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_query_ic_credentials), and [WlxWin31Migrate](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_win31_migrate).

## See also

[WLX_DISPATCH_VERSION_1_3](https://learn.microsoft.com/windows/desktop/api/winwlx/ns-winwlx-wlx_dispatch_version_1_3)

[WlxDisconnect](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_disconnect)

[WlxNegotiate](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxnegotiate)

[WlxQueryInetConnectorCredentials](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_query_ic_credentials)

[WlxWin31Migrate](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_win31_migrate)