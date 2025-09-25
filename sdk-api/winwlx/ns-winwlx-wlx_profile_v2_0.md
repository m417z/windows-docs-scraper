# WLX_PROFILE_V2_0 structure

## Description

[The WLX_PROFILE_V2_0 structure is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **WLX_PROFILE_V2_0** structure contains profile information in addition to the information provided by
[WLX_PROFILE_V1_0](https://learn.microsoft.com/windows/desktop/api/winwlx/ns-winwlx-wlx_profile_v1_0).

## Members

### `dwType`

Must be set to WLX_PROFILE_TYPE_V2_0.

### `pszProfile`

Pointer to the profile path (for example, "%SystemRoot%\system32\config\AprilM001", or a network path such as "\\server\share\profiles\floating\AprilM.usr").

The string pointed to by **pszProfile** must be separately allocated by your GINA DLL. It will be deallocated by Winlogon.

### `pszPolicy`

Pointer to the policy file that will be applied to the user logging on.

The string pointed to by **pszPolicy** must be separately allocated by your [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) DLL. It will be deallocated by [Winlogon](https://learn.microsoft.com/windows/desktop/SecGloss/w-gly).

### `pszNetworkDefaultUserProfile`

If a new profile is to be created, a pointer to the path of the default profile to use.

The string pointed to by **pszNetworkDefaultUserProfile** must be separately allocated by your GINA DLL. It will be deallocated by Winlogon.

### `pszServerName`

Pointer to the name of the server that validated the logon. This name will be used to enumerate the global groups of which the user is a member.

The string pointed to by **pszServerName** must be separately allocated by your GINA DLL. It will be deallocated by Winlogon.

### `pszEnvironment`

Pointer to the default environment variables to include in the construction of the environment of the user. This member is a series of null-terminated strings using any of the following forms.

```cpp
Variable=Value
variable=%other variable%
variable=%othervariable%\additional text

```

For example:

```cpp
logonServer=\\pdc
homepath=%logonServer%\share

```

## Remarks

This structure is returned to Winlogon by your GINA DLL.

Your GINA DLL may use two structures to provide profile information: **WLX_PROFILE_V2_0** and
[WLX_PROFILE_V1_0](https://learn.microsoft.com/windows/desktop/api/winwlx/ns-winwlx-wlx_profile_v1_0). The information in **WLX_PROFILE_V1_0** only includes the profile type and path to the profile.

## See also

[WLX_PROFILE_V1_0](https://learn.microsoft.com/windows/desktop/api/winwlx/ns-winwlx-wlx_profile_v1_0)