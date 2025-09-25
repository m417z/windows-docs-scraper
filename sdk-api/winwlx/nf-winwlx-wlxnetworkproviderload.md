# WlxNetworkProviderLoad function

## Description

[The WlxNetworkProviderLoad function is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **WlxNetworkProviderLoad** function must be implemented by a replacement [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) DLL. [Winlogon](https://learn.microsoft.com/windows/desktop/SecGloss/w-gly) calls this function to collect valid authentication and identification information.

**Note** GINA DLLs are ignored in Windows Vista.

## Parameters

### `pWlxContext` [in]

Pointer to the GINA context associated with this window station. The GINA returns this context value when Winlogon calls
[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize) for this station.

### `pNprNotifyInfo` [out]

Points to an
[WLX_MPR_NOTIFY_INFO](https://learn.microsoft.com/windows/desktop/api/winwlx/ns-winwlx-wlx_mpr_notify_info) structure that contains domain, user name, and password information for the user. Winlogon will use this information to provide identification and authentication information to network providers.

The GINA is not required to return password information. Any **NULL** fields within the structure will be ignored by Winlogon. Use [LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc) to allocate each string; Winlogon will free them when they are no longer needed.

## Return value

| Return code | Description |
| --- | --- |
| **TRUE** | Return **TRUE** if the user was authenticated. |
| **FALSE** | Return **FALSE** if the user was not authenticated. |

## See also

[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize)