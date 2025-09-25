# SERVER_INFO_403 structure

## Description

The
**SERVER_INFO_403** structure contains information about a specified server.

## Members

### `sv403_ulist_mtime`

Type: **DWORD**

The last time the user list was modified. The value is expressed as the number of seconds that have elapsed since 00:00:00, January 1, 1970, GMT, and applies to servers running with user-level security.

### `sv403_glist_mtime`

Type: **DWORD**

The last time the group list was modified. The value is expressed as the number of seconds that have elapsed since 00:00:00, January 1, 1970, GMT, and applies to servers running with user-level security.

### `sv403_alist_mtime`

Type: **DWORD**

The last time the access control list was modified. The value is expressed as the number of seconds that have elapsed since 00:00:00, January 1, 1970, GMT, and applies to servers running with user-level security.

### `sv403_alerts`

Type: **LMSTR**

A pointer to a string that specifies the list of user names on the server. Spaces separate the names.

This string is Unicode if **_WIN32_WINNT** or **FORCE_UNICODE** are defined.

### `sv403_security`

Type: **DWORD**

The security type of the server. This member can be one of the following values. Note that Windows NT, Windows 2000, Windows XP, and Windows Server 2003 operating systems do not support share-level security.

| Value | Meaning |
| --- | --- |
| **SV_SHARESECURITY** | Share-level security |
| **SV_USERSECURITY** | User-level security |

### `sv403_numadmin`

Type: **DWORD**

The number of administrators the server can accommodate at one time.

### `sv403_lanmask`

Type: **DWORD**

The order in which the network device drivers are served.

### `sv403_guestacct`

Type: **LPWSTR**

A pointer to a Unicode string that specifies the name of a reserved account for guest users on the server. The UNLEN constant specifies the maximum number of characters in the string.

### `sv403_chdevs`

Type: **DWORD**

The number of character devices that can be shared on the server.

### `sv403_chdevq`

Type: **DWORD**

The number of character device queues that can coexist on the server.

### `sv403_chdevjobs`

Type: **DWORD**

The number of character device jobs that can be pending at one time on the server.

### `sv403_connections`

Type: **DWORD**

The number of connections allowed on the server.

### `sv403_shares`

Type: **DWORD**

The number of share names the server can accommodate.

### `sv403_openfiles`

Type: **DWORD**

The number of files that can be open at once on the server.

### `sv403_sessopens`

Type: **DWORD**

The number of files that one session can open.

### `sv403_sessvcs`

Type: **DWORD**

The maximum number of virtual circuits permitted per client.

### `sv403_sessreqs`

Type: **DWORD**

The number of simultaneous requests a client can make on a single virtual circuit.

### `sv403_opensearch`

Type: **DWORD**

The number of search operations that can be carried out simultaneously.

### `sv403_activelocks`

Type: **DWORD**

The number of file locks that can be active at the same time.

### `sv403_numreqbuf`

Type: **DWORD**

The number of server buffers that are provided.

### `sv403_sizreqbuf`

Type: **DWORD**

The size, in bytes, of each server buffer.

### `sv403_numbigbuf`

Type: **DWORD**

The number of 64K server buffers provided.

### `sv403_numfiletasks`

Type: **DWORD**

The number of processes that can access the operating system at the same time.

### `sv403_alertsched`

Type: **DWORD**

The alert interval, in seconds, for notifying an administrator of a network event.

### `sv403_erroralert`

Type: **DWORD**

The number of entries that can be written to the error log, in any one interval, before notifying an administrator. The interval is specified by the **sv403_alertsched** member.

### `sv403_logonalert`

Type: **DWORD**

The number of invalid attempts that a user tries to logon before notifying an administrator.

### `sv403_accessalert`

Type: **DWORD**

The number of invalid file access attempts to allow before notifying an administrator.

### `sv403_diskalert`

Type: **DWORD**

The amount of free disk space at which the system sends a message notifying an administrator that free space on a disk is low. This value is expressed as the number of kilobytes of free disk space remaining on the disk.

### `sv403_netioalert`

Type: **DWORD**

The network I/O error ratio, in tenths of a percent, that is allowed before notifying an administrator.

### `sv403_maxauditsz`

Type: **DWORD**

The maximum audit file size in kilobytes. The audit file traces user activity.

### `sv403_srvheuristics`

Type: **LPWSTR**

A pointer to a Unicode string that contains flags that are used to control operations on a server.

### `sv403_auditedevents`

Type: **DWORD**

The audit event control mask.

### `sv403_autoprofile`

Type: **DWORD**

A value that controls the action of the server on the profile. The following values are predefined.

| Value | Meaning |
| --- | --- |
| **SW_AUTOPROF_LOAD_MASK** | The server loads the profile. |
| **SW_AUTOPROF_SAVE_MASK** | The server saves the profile. |

### `sv403_autopath`

Type: **LPWSTR**

A pointer to a Unicode string that contains the path for the profile.

## See also

[NetServerGetInfo](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservergetinfo)

[NetServerSetInfo](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netserversetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[Server Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/server-functions)