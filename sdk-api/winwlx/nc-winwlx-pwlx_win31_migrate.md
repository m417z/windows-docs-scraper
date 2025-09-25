# PWLX_WIN31_MIGRATE callback function

## Description

[The WlxWin31Migrate function is no longer available for use as of Windows Server 2008 and Windows Vista.]

Called by a replacement GINA DLL if Terminal Services is enabled.
[GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) calls this function to complete the setup of the Terminal Services client.

**Note** GINA DLLs are ignored in Windows Vista.

## Parameters

### `hWlx` [in]

Specify the handle received in the call to
[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize).

## Remarks

GINA needs to call this function before starting the shell, so that the migration and setup will be complete before the shell starts, but after it has processed any logon scripts.

In order to use this function, the GINA DLL must specify the
[WLX_DISPATCH_VERSION_1_3](https://learn.microsoft.com/windows/desktop/api/winwlx/ns-winwlx-wlx_dispatch_version_1_3) structure in its call to
[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize), and set the Winlogon version to at least WLX_VERSION_1_3 in its
[WlxNegotiate](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxnegotiate) call.

Other Winlogon support functions that may be called when Terminal Services is enabled are [WlxDisconnect](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_disconnect), [WlxQueryClientCredentials](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_query_client_credentials), and [WlxQueryInetConnectorCredentials](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_query_ic_credentials).

## See also

[WLX_DISPATCH_VERSION_1_3](https://learn.microsoft.com/windows/desktop/api/winwlx/ns-winwlx-wlx_dispatch_version_1_3)

[WlxDisconnect](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_disconnect)

[WlxNegotiate](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxnegotiate)

[WlxQueryClientCredentials](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_query_client_credentials)

[WlxQueryInetConnectorCredentials](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_query_ic_credentials)