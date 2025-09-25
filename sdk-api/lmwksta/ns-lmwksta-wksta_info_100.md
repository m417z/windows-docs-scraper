# WKSTA_INFO_100 structure

## Description

The
**WKSTA_INFO_100** structure contains information about a workstation environment, including platform-specific information, the names of the domain and the local computer, and information concerning the operating system.

## Members

### `wki100_platform_id`

Type: **DWORD**

The information level to use to retrieve platform-specific information.

Possible values for this member are listed in the *Lmcons.h* header file.

| Value | Meaning |
| --- | --- |
| **PLATFORM_ID_DOS**<br><br>300 | The MS-DOS platform. |
| **PLATFORM_ID_OS2**<br><br>400 | The OS/2 platform. |
| **PLATFORM_ID_NT**<br><br>500 | The Windows NT platform. |
| **PLATFORM_ID_OSF**<br><br>600 | The OSF platform. |
| **PLATFORM_ID_VMS**<br><br>700 | The VMS platform. |

### `wki100_computername`

Type: **LMSTR**

A pointer to a string specifying the name of the local computer.

This string is Unicode if **_WIN32_WINNT** or **FORCE_UNICODE** are defined.

### `wki100_langroup`

Type: **LMSTR**

A pointer to a string specifying the name of the domain to which the computer belongs.

This string is Unicode if **_WIN32_WINNT** or **FORCE_UNICODE** are defined.

### `wki100_ver_major`

Type: **DWORD**

The major version number of the operating system running on the computer.

### `wki100_ver_minor`

Type: **DWORD**

The minor version number of the operating system running on the computer.

## See also

[NetWkstaGetInfo](https://learn.microsoft.com/windows/desktop/api/lmwksta/nf-lmwksta-netwkstagetinfo)

[NetWkstaSetInfo](https://learn.microsoft.com/windows/desktop/api/lmwksta/nf-lmwksta-netwkstasetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[Workstation and Workstation User Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/workstation-and-workstation-user-functions)