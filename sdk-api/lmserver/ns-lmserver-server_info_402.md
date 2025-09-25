# SERVER_INFO_402 structure

## Description

The
**SERVER_INFO_402** structure contains information about a specified server.

## Members

### `sv402_ulist_mtime`

Type: **DWORD**

The last time the user list was modified. The value is expressed as the number of seconds that have elapsed since 00:00:00, January 1, 1970, GMT, and applies to servers running with user-level security.

### `sv402_glist_mtime`

Type: **DWORD**

The last time the group list was modified. The value is expressed as the number of seconds that have elapsed since 00:00:00, January 1, 1970, GMT, and applies to servers running with user-level security.

### `sv402_alist_mtime`

Type: **DWORD**

The last time the access control list was modified. The value is expressed as the number of seconds that have elapsed since 00:00:00, January 1, 1970, GMT, and applies to servers running with user-level security.

### `sv402_alerts`

Type: **LPWSTR**

A pointer to a Unicode string that specifies the list of user names on the server. Spaces separate the names.

### `sv402_security`

Type: **DWORD**

The security type of the server. This member can be one of the following values. Note that Windows NT, Windows 2000, Windows XP, and Windows Server 2003 operating systems do not support share-level security.

| Value | Meaning |
| --- | --- |
| **SV_SHARESECURITY** | Share-level security |
| **SV_USERSECURITY** | User-level security |

### `sv402_numadmin`

Type: **DWORD**

The number of administrators the server can accommodate at one time.

### `sv402_lanmask`

Type: **DWORD**

The order in which the network device drivers are served.

### `sv402_guestacct`

Type: **LPWSTR**

A pointer to a Unicode string that specifies the name of a reserved account for guest users on the server. The constant UNLEN specifies the maximum number of characters in the string.

### `sv402_chdevs`

Type: **DWORD**

The number of character-oriented devices that can be shared on the server.

### `sv402_chdevq`

Type: **DWORD**

The number of character-oriented device queues that can coexist on the server.

### `sv402_chdevjobs`

Type: **DWORD**

The number of character-oriented device jobs that can be pending at one time on the server.

### `sv402_connections`

Type: **DWORD**

The number of connections allowed on the server.

### `sv402_shares`

Type: **DWORD**

The number of share names the server can accommodate.

### `sv402_openfiles`

Type: **DWORD**

The number of files that can be open at once on the server.

### `sv402_sessopens`

Type: **DWORD**

The number of files that one session can open.

### `sv402_sessvcs`

Type: **DWORD**

The maximum number of virtual circuits permitted per client.

### `sv402_sessreqs`

Type: **DWORD**

The number of simultaneous requests a client can make on a single virtual circuit.

### `sv402_opensearch`

Type: **DWORD**

The number of search operations that can be carried out simultaneously.

### `sv402_activelocks`

Type: **DWORD**

The number of file locks that can be active at the same time.

### `sv402_numreqbuf`

Type: **DWORD**

The number of server buffers provided.

### `sv402_sizreqbuf`

Type: **DWORD**

The size, in bytes, of each server buffer.

### `sv402_numbigbuf`

Type: **DWORD**

The number of 64K server buffers provided.

### `sv402_numfiletasks`

Type: **DWORD**

The number of processes that can access the operating system at one time.

### `sv402_alertsched`

Type: **DWORD**

The interval, in seconds, for notifying an administrator of a network event.

### `sv402_erroralert`

Type: **DWORD**

The number of entries that can be written to the error log, in any one interval, before notifying an administrator. The interval is specified by the **sv402_alertsched** member.

### `sv402_logonalert`

Type: **DWORD**

The number of invalid logon attempts to allow a user before notifying an administrator.

### `sv402_accessalert`

Type: **DWORD**

The number of invalid file access attempts to allow before notifying an administrator.

### `sv402_diskalert`

Type: **DWORD**

The point at which the system sends a message notifying an administrator that free space on a disk is low. This value is expressed as the number of kilobytes of free disk space remaining on the disk.

### `sv402_netioalert`

Type: **DWORD**

The network I/O error ratio, in tenths of a percent, that is allowed before notifying an administrator.

### `sv402_maxauditsz`

Type: **DWORD**

The maximum size, in kilobytes, of the audit file. The audit file traces user activity.

### `sv402_srvheuristics`

Type: **LPWSTR**

A pointer to a Unicode string containing flags that control operations on a server.

## See also

[NetServerGetInfo](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservergetinfo)

[NetServerSetInfo](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netserversetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[Server Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/server-functions)