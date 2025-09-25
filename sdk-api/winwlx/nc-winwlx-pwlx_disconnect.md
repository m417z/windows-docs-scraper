# PWLX_DISCONNECT callback function

## Description

[The WlxDisconnect function is no longer available for use as of Windows Server 2008 and Windows Vista.]

Called by a replacement GINA DLL if Terminal Services is enabled. [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) calls this function to disconnect from a Terminal Services network session.

**Note** GINA DLLs are ignored in Windows Vista.

**WlxDisconnect** allows GINA to optionally support a disconnect dialog box.

## Parameters

## Return value

The **WlxDisconnect** function returns one of the following values.

| Return code | Description |
| --- | --- |
| **TRUE** | Terminal Services session was disconnected. |
| **FALSE** | Terminal Services session was not disconnected, or Terminal Services was not enabled. |

## Remarks

To access this function, the GINA DLL must use the
[WLX_DISPATCH_VERSION_1_3](https://learn.microsoft.com/windows/desktop/api/winwlx/ns-winwlx-wlx_dispatch_version_1_3) structure, and set the Winlogon version to at least WLX_VERSION_1_3 in its
[WlxNegotiate](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxnegotiate) call.

Other Winlogon support functions that may be called when Terminal Services is enabled are [WlxWin31Migrate](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_win31_migrate), [WlxQueryClientCredentials](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_query_client_credentials), and [WlxQueryInetConnectorCredentials](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_query_ic_credentials).

## See also

[WLX_DISPATCH_VERSION_1_3](https://learn.microsoft.com/windows/desktop/api/winwlx/ns-winwlx-wlx_dispatch_version_1_3)

[WlxNegotiate](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxnegotiate)

[WlxQueryClientCredentials](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_query_client_credentials)

[WlxQueryInetConnectorCredentials](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_query_ic_credentials)

[WlxWin31Migrate](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_win31_migrate)