# PWLX_QUERY_CONSOLESWITCH_CREDENTIALS callback function

## Description

Called by [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) to read the credentials transferred from the Winlogon of the temporary session to the Winlogon of the destination session.

**Note** GINA DLLs are ignored in Windows Vista.

## Parameters

### `pCred` [out]

Pointer to a
[WLX_CONSOLESWITCH_CREDENTIALS_INFO_V1_0](https://learn.microsoft.com/windows/win32/api/winwlx/ns-winwlx-wlx_consoleswitch_credentials_info_v1_0) structure to be filled with credentials information.

## Return value

Returns **TRUE** if credentials were transferred and **FALSE** if the transfer failed.

## Remarks

In order to access this function, the GINA DLL must use the
[WLX_DISPATCH_VERSION_1_4](https://learn.microsoft.com/windows/desktop/api/winwlx/ns-winwlx-wlx_dispatch_version_1_4) structure.