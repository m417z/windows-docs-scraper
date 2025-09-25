# SHARE_INFO_502 structure

## Description

Contains information about the shared resource, including name of the resource, type and permissions, number of connections, and other pertinent information.

## Members

### `shi502_netname`

Pointer to a Unicode string specifying the name of a shared resource. Calls to the
[NetShareSetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharesetinfo) function ignore this member.

### `shi502_type`

A combination of values that specify the type of share. Calls to the
**NetShareSetInfo** function ignore this member.

One of the following values may be specified. You can isolate these values by using the **STYPE_MASK** value.

| Value | Meaning |
| --- | --- |
| **STYPE_DISKTREE** | Disk Drive. |
| **STYPE_PRINTQ** | Print Queue. |
| **STYPE_DEVICE** | Communication device. |
| **STYPE_IPC** | Interprocess communication (IPC). |

In addition, one or both of the following values may be specified.

| Value | Meaning |
| --- | --- |
| **STYPE_SPECIAL** | Special share reserved for interprocess communication (IPC$) or remote administration of the server (ADMIN$). Can also refer to administrative shares such as C$, D$, E$, and so forth. For more information, see the network [share functions](https://learn.microsoft.com/windows/desktop/NetShare/network-share-functions). |
| **STYPE_TEMPORARY** | A temporary share. |

### `shi502_remark`

Pointer to a Unicode string specifying an optional comment about the shared resource.

### `shi502_permissions`

Specifies a DWORD value that indicates the shared resource's permissions for servers running with share-level security. This member is ignored on a server running user-level security. This member can be any of the following values. Calls to the
[NetShareSetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharesetinfo) function ignore this member.

Note that Windows does not support share-level security. For more information about controlling access to securable objects, see [Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control), [Privileges](https://learn.microsoft.com/windows/desktop/SecAuthZ/privileges), and [Securable Objects](https://learn.microsoft.com/windows/desktop/SecAuthZ/securable-objects).

| Value | Meaning |
| --- | --- |
| **ACCESS_READ** | Permission to read data from a resource and, by default, to execute the resource. |
| **ACCESS_WRITE** | Permission to write data to the resource. |
| **ACCESS_CREATE** | Permission to create an instance of the resource (such as a file); data can be written to the resource as the resource is created. |
| **ACCESS_EXEC** | Permission to execute the resource. |
| **ACCESS_DELETE** | Permission to delete the resource. |
| **ACCESS_ATRIB** | Permission to modify the resource's attributes (such as the date and time when a file was last modified). |
| **ACCESS_PERM** | Permission to modify the permissions (read, write, create, execute, and delete) assigned to a resource for a user or application. |
| **ACCESS_ALL** | Permission to read, write, create, execute, and delete resources, and to modify their attributes and permissions. |

### `shi502_max_uses`

Specifies a DWORD value that indicates the maximum number of concurrent connections that the shared resource can accommodate. The number of connections is unlimited if the value specified in this member is –1.

### `shi502_current_uses`

Specifies a DWORD value that indicates the number of current connections to the resource. Calls to the
[NetShareSetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharesetinfo) function ignore this member.

### `shi502_path`

Pointer to a Unicode string that contains the local path for the shared resource. For disks, this member is the path being shared. For print queues, this member is the name of the print queue being shared. Calls to the
**NetShareSetInfo** function ignore this member.

### `shi502_passwd`

Pointer to a Unicode string that specifies the share's password (when the server is running with share-level security). If the server is running with user-level security, this member is ignored. Note that Windows does not support share-level security.

This member can be no longer than SHPWLEN+1 bytes (including a terminating null character). Calls to the
**NetShareSetInfo** function ignore this member.

### `shi502_reserved`

Reserved; must be zero. Calls to the
[NetShareSetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharesetinfo) function ignore this member.

### `shi502_security_descriptor`

Specifies the
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) associated with this share.

## See also

[NetShareAdd](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netshareadd)

[NetShareEnum](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netshareenum)

[NetShareGetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharegetinfo)

[NetShareSetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharesetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[Network Share Functions](https://learn.microsoft.com/windows/desktop/NetShare/network-share-functions)