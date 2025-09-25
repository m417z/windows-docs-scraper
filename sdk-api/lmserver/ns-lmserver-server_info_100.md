# SERVER_INFO_100 structure

## Description

The
**SERVER_INFO_100** structure contains information about the specified server, including the name and platform.

## Members

### `sv100_platform_id`

Type: **DWORD**

The information level to use for platform-specific information.

Possible values for this member are listed in the *Lmcons.h* header file.

| Value | Meaning |
| --- | --- |
| **PLATFORM_ID_DOS**<br><br>300 | The MS-DOS platform. |
| **PLATFORM_ID_OS2**<br><br>400 | The OS/2 platform. |
| **PLATFORM_ID_NT**<br><br>500 | The Windows NT platform. |
| **PLATFORM_ID_OSF**<br><br>600 | The OSF platform. |
| **PLATFORM_ID_VMS**<br><br>700 | The VMS platform. |

### `sv100_name`

Type: **LPWSTR**

A pointer to a Unicode string that specifies the name of the server.

## See also

[NetServerDiskEnum](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netserverdiskenum)

[NetServerEnum](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netserverenum)

[NetServerGetInfo](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservergetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[Server Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/server-functions)