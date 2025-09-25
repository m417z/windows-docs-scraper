# WLX_PROFILE_V1_0 structure

## Description

[The WLX_PROFILE_V1_0 structure is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **WLX_PROFILE_V1_0** structure contains information used for setting up the initial environment.

## Members

### `dwType`

Must be set to WLX_PROFILE_TYPE_V1_0.

### `pszProfile`

Pointer to the profile path (for example, "%SystemRoot%\system32\config\AprilM001").

The string pointed to by **pszProfile** must be separately allocated by your [GINA](https://learn.microsoft.com/windows/win32/SecGloss/g-gly) DLL, using [LocalAlloc](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-localalloc). It will be deallocated by [Winlogon](https://learn.microsoft.com/windows/win32/SecGloss/w-gly).

## Remarks

The **WLX_PROFILE_V1_0** structure is returned to Winlogon by your GINA DLL following authentication. Winlogon uses the path specified by **pszProfile** to load the profile of the newly logged-on user.

GINA uses two structures to provide profile information: [WLX_PROFILE_V2_0](https://learn.microsoft.com/windows/desktop/api/winwlx/ns-winwlx-wlx_profile_v2_0) and **WLX_PROFILE_V1_0**.

## See also

[WLX_PROFILE_V2_0](https://learn.microsoft.com/windows/win32/api/winwlx/ns-winwlx-wlx_profile_v2_0)