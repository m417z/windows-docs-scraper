# WKSTA_USER_INFO_1 structure

## Description

The
**WKSTA_USER_INFO_1** structure contains user information as it pertains to a specific workstation. The information includes the name of the current user and the domains accessed by the workstation.

## Members

### `wkui1_username`

Specifies the name of the user currently logged on to the workstation.

This string is Unicode if **_WIN32_WINNT** or **FORCE_UNICODE** are defined.

### `wkui1_logon_domain`

Specifies the name of the domain in which the user is currently logged on.

This string is Unicode if **_WIN32_WINNT** or **FORCE_UNICODE** are defined.

### `wkui1_oth_domains`

Specifies the list of operating system domains browsed by the workstation. The domain names are separated by blanks.

This string is Unicode if **_WIN32_WINNT** or **FORCE_UNICODE** are defined.

### `wkui1_logon_server`

Specifies the name of the server that authenticated the user.

This string is Unicode if **_WIN32_WINNT** or **FORCE_UNICODE** are defined.

## See also

[NetWkstaUserEnum](https://learn.microsoft.com/windows/desktop/api/lmwksta/nf-lmwksta-netwkstauserenum)

[NetWkstaUserGetInfo](https://learn.microsoft.com/windows/desktop/api/lmwksta/nf-lmwksta-netwkstausergetinfo)

[NetWkstaUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmwksta/nf-lmwksta-netwkstausersetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[Workstation and Workstation User Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/workstation-and-workstation-user-functions)