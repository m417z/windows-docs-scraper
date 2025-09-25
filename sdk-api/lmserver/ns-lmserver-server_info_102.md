# SERVER_INFO_102 structure

## Description

The
**SERVER_INFO_102** structure contains information about the specified server, including name, platform, type of server, attributes, and associated software.

## Members

### `sv102_platform_id`

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

### `sv102_name`

Type: **LPWSTR**

A pointer to a Unicode string specifying the name of a server.

### `sv102_version_major`

Type: **DWORD**

The major version number and the server type.

The major release version number of the operating system is specified in the least significant 4 bits. The server type is specified in the most significant 4 bits. The **MAJOR_VERSION_MASK** bitmask defined in the *Lmserver.h* header should be used by an application to obtain the major version number from this member.

### `sv102_version_minor`

Type: **DWORD**

The minor release version number of the operating system.

### `sv102_type`

Type: **DWORD**

The type of software the computer is running.

Possible values for this member are listed in the *Lmserver.h* header file.
This member can be a combination of some of the following values.

| Value | Meaning |
| --- | --- |
| **SV_TYPE_WORKSTATION**<br><br>0x00000001 | A workstation. |
| **SV_TYPE_SERVER**<br><br>0x00000002 | A server. |
| **SV_TYPE_SQLSERVER**<br><br>0x00000004 | A server running with Microsoft SQL Server. |
| **SV_TYPE_DOMAIN_CTRL**<br><br>0x00000008 | A primary domain controller. |
| **SV_TYPE_DOMAIN_BAKCTRL**<br><br>0x00000010 | A backup domain controller. |
| **SV_TYPE_TIME_SOURCE**<br><br>0x00000020 | A server running the Timesource service. |
| **SV_TYPE_AFP**<br><br>0x00000040 | A server running the Apple Filing Protocol (AFP) file service. |
| **SV_TYPE_NOVELL**<br><br>0x00000080 | A Novell server. |
| **SV_TYPE_DOMAIN_MEMBER**<br><br>0x00000100 | A LAN Manager 2.x domain member. |
| **SV_TYPE_PRINTQ_SERVER**<br><br>0x00000200 | A server that shares a print queue. |
| **SV_TYPE_DIALIN_SERVER**<br><br>0x00000400 | A server that runs a dial-in service. |
| **SV_TYPE_XENIX_SERVER**<br><br>0x00000800 | A Xenix or Unix server. |
| **SV_TYPE_NT**<br><br>0x00001000 | A workstation or server. |
| **SV_TYPE_WFW**<br><br>0x00002000 | A computer that runs Windows for Workgroups. |
| **SV_TYPE_SERVER_MFPN**<br><br>0x00004000 | A server that runs the Microsoft File and Print for NetWare service. |
| **SV_TYPE_SERVER_NT**<br><br>0x00008000 | Any server that is not a domain controller. |
| **SV_TYPE_POTENTIAL_BROWSER**<br><br>0x00010000 | A computer that can run the browser service. |
| **SV_TYPE_BACKUP_BROWSER**<br><br>0x00020000 | A server running a browser service as backup. |
| **SV_TYPE_MASTER_BROWSER**<br><br>0x00040000 | A server running the master browser service. |
| **SV_TYPE_DOMAIN_MASTER**<br><br>0x00080000 | A server running the domain master browser. |
| **SV_TYPE_SERVER_OSF**<br><br>0x00100000 | A computer that runs OSF. |
| **SV_TYPE_SERVER_VMS**<br><br>0x00200000 | A computer that runs VMS. |
| **SV_TYPE_WINDOWS**<br><br>0x00400000 | A computer that runs Windows. |
| **SV_TYPE_DFS**<br><br>0x00800000 | A server that is the root of a DFS tree. |
| **SV_TYPE_CLUSTER_NT**<br><br>0x01000000 | A server cluster available in the domain. |
| **SV_TYPE_TERMINALSERVER**<br><br>0x02000000 | A server that runs the Terminal Server service. |
| **SV_TYPE_CLUSTER_VS_NT**<br><br>0x04000000 | Cluster virtual servers available in the domain.<br><br>**Windows 2000:** This value is not supported. |
| **SV_TYPE_DCE**<br><br>0x10000000 | A server that runs the DCE Directory and Security Services or equivalent. |
| **SV_TYPE_ALTERNATE_XPORT**<br><br>0x20000000 | A server that is returned by an alternate transport. |
| **SV_TYPE_LOCAL_LIST_ONLY**<br><br>0x40000000 | A server that is maintained by the browser. |
| **SV_TYPE_DOMAIN_ENUM**<br><br>0x80000000 | A primary domain. |

The **SV_TYPE_ALL** constant is defined to 0xFFFFFFFF in the *Lmserver.h* header file. This constant can be used to check for all server types when used with the [NetServerEnum](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netserverenum) function.

### `sv102_comment`

Type: **LPWSTR**

A pointer to a Unicode string specifying a comment describing the server. The comment can be null.

### `sv102_users`

Type: **DWORD**

The number of users who can attempt to log on to the system server. Note that it is the license server that determines how many of these users can actually log on.

### `sv102_disc`

Type: **LONG**

The auto-disconnect time, in minutes. A session is disconnected if it is idle longer than the period of time specified by the **sv102_disc** member. If the value of **sv102_disc** is SV_NODISC, auto-disconnect is not enabled.

### `sv102_hidden`

Type: **BOOL**

A value that indicates whether the server is visible to other computers in the same network domain. This member can be one of the following values defined in the *Lmserver.h* header file.

| Value | Meaning |
| --- | --- |
| **SV_VISIBLE** | The server is visible. |
| **SV_HIDDEN** | The server is not visible. |

### `sv102_announce`

Type: **DWORD**

The network announce rate, in seconds. This rate determines how often the server is announced to other computers on the network. For more information about how much the announce rate can vary from the period of time specified by this member, see
[SERVER_INFO_1018](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_info_1018).

### `sv102_anndelta`

Type: **DWORD**

The delta value for the announce rate, in milliseconds. This value specifies how much the announce rate can vary from the period of time specified in the **sv102_announce** member.

The delta value allows randomly varied announce rates. For example, if the **sv102_announce** member has the value 10 and the **sv102_anndelta** member has the value 1, the announce rate can vary from 9.999 seconds to 10.001 seconds.

### `sv102_licenses`

Type: **DWORD**

The number of users per license. By default, this number is SV_USERS_PER_LICENSE.

### `sv102_userpath`

Type: **LPWSTR**

A pointer to a Unicode string specifying the path to user directories.

## Remarks

To retrieve a value that indicates whether a share is the root volume in a Dfs tree structure, you must call the
[NetShareGetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharegetinfo) function and specify information level 1005.

## See also

[NetServerGetInfo](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservergetinfo)

[NetServerSetInfo](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netserversetinfo)

[NetShareGetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharegetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[SERVER_INFO_1018](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_info_1018)

[Server Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/server-functions)