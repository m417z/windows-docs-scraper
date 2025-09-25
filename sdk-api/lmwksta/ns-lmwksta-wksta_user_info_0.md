# WKSTA_USER_INFO_0 structure

## Description

The
**WKSTA_USER_INFO_0** structure contains the name of the user on a specified workstation.

## Members

### `wkui0_username`

Specifies the name of the user currently logged on to the workstation.

This string is Unicode if **_WIN32_WINNT** or **FORCE_UNICODE** are defined.

## See also

[NetWkstaUserEnum](https://learn.microsoft.com/windows/desktop/api/lmwksta/nf-lmwksta-netwkstauserenum)

[NetWkstaUserGetInfo](https://learn.microsoft.com/windows/desktop/api/lmwksta/nf-lmwksta-netwkstausergetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[Workstation and Workstation User Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/workstation-and-workstation-user-functions)