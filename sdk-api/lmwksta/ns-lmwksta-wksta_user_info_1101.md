# WKSTA_USER_INFO_1101 structure

## Description

The
**WKSTA_USER_INFO_1101** structure contains information about the domains accessed by a workstation.

## Members

### `wkui1101_oth_domains`

Specifies the list of operating system domains browsed by the workstation. The domain names are separated by blanks.

This string is Unicode if **_WIN32_WINNT** or **FORCE_UNICODE** are defined.

## See also

[NetWkstaUserGetInfo](https://learn.microsoft.com/windows/desktop/api/lmwksta/nf-lmwksta-netwkstausergetinfo)

[NetWkstaUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmwksta/nf-lmwksta-netwkstausersetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[Workstation and Workstation User Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/workstation-and-workstation-user-functions)