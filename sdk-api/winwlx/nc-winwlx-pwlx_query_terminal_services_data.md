# PWLX_QUERY_TERMINAL_SERVICES_DATA callback function

## Description

[The WlxQueryTerminalServicesData function is no longer available for use as of Windows Server 2008 and Windows Vista.]

Called by [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) to retrieve Terminal Services user configuration information after a user has logged on.

**Note** GINA DLLs are ignored in Windows Vista.

## Parameters

### `hWlx` [in]

Specifies the Winlogon handle passed to GINA in the
[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize) call.

### `pTSData` [out]

Points to a structure that will contain the user configuration information specific to Terminal Services.

### `UserName` [in]

Pointer to a null-terminated wide character string that specifies the name of the newly logged-on user.

### `Domain` [in]

Pointer to a null-terminated wide character string that specifies the newly logged-on user's domain.

## Return value

The **WlxQueryTerminalServicesData** function returns zero if the user-configuration information was retrieved successfully. Otherwise, it returns an error code.

## Remarks

**WlxQueryTerminalServicesData** should be called from within GINA's implementation of
[WlxLoggedOutSAS](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxloggedoutsas) after a user has been authenticated.

In order to access this function, the GINA DLL must use the
[WLX_DISPATCH_VERSION_1_3](https://learn.microsoft.com/windows/desktop/api/winwlx/ns-winwlx-wlx_dispatch_version_1_3) structure, and set the Winlogon version to at least WLX_VERSION_1_3 in its
[WlxNegotiate](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxnegotiate) call.

## See also

[WLX_DISPATCH_VERSION_1_3](https://learn.microsoft.com/windows/desktop/api/winwlx/ns-winwlx-wlx_dispatch_version_1_3)

[WlxDisconnect](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_disconnect)

[WlxLoggedOutSAS](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxloggedoutsas)

[WlxNegotiate](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxnegotiate)

[WlxQueryClientCredentials](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_query_client_credentials)

[WlxWin31Migrate](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_win31_migrate)