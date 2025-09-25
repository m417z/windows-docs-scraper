# WlxGetConsoleSwitchCredentials function

## Description

The **WlxGetConsoleSwitchCredentials** function must be implemented by a replacement [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) DLL. [Winlogon](https://learn.microsoft.com/windows/desktop/SecGloss/w-gly) calls this function to read the currently logged on user's credentials to transparently transfer them to a target session.

**Note** GINA DLLs are ignored in Windows Vista.

## Parameters

### `pWlxContext` [in]

Pointer to a GINA-specific context.

### `pCredInfo` [out]

Pointer to a [WLX_CONSOLESWITCH_CREDENTIALS_INFO_V1_0](https://learn.microsoft.com/windows/win32/api/winwlx/ns-winwlx-wlx_consoleswitch_credentials_info_v1_0) to return GINA relevant information.

## Return value

Returns **TRUE** on success and **FALSE** on failure.