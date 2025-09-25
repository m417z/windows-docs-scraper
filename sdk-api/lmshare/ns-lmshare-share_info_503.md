# SHARE_INFO_503 structure

## Description

Contains information about the shared resource. It is identical to the [SHARE_INFO_502](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_502) structure, except that it also contains the server name.

## Members

### `shi503_netname`

A pointer to a Unicode string specifying the name of a shared resource. Calls to the
[NetShareSetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharesetinfo) function ignore this member.

### `shi503_type`

A combination of values that specify the type of share. Calls to the
[NetShareSetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharesetinfo) function ignore this member.

One of the following values may be specified. You can isolate these values by using the **STYPE_MASK** value.

| Value | Meaning |
| --- | --- |
| **STYPE_DISKTREE**<br><br>0x00000000 | Disk drive. |
| **STYPE_PRINTQ**<br><br>0x00000001 | Print queue. |
| **STYPE_DEVICE**<br><br>0x00000002 | Communication device. |
| **STYPE_IPC**<br><br>0x00000003 | Interprocess communication (IPC). |

In addition, one or both of the following values may be specified.

| Value | Meaning |
| --- | --- |
| **STYPE_SPECIAL**<br><br>0x80000000 | Special share reserved for interprocess communication (IPC$) or remote administration of the server (ADMIN$). Can also refer to administrative shares such as C$, D$, E$, and so forth. For more information, see the network [share functions](https://learn.microsoft.com/windows/desktop/NetShare/network-share-functions). |
| **STYPE_TEMPORARY**<br><br>0x40000000 | A temporary share. |

### `shi503_remark`

A pointer to a Unicode string specifying an optional comment about the shared resource.

### `shi503_permissions`

Specifies a DWORD value that indicates the shared resource's permissions for servers running with share-level security. Note that Windows does not support share-level security. This member is ignored on a server running user-level security. For more information about controlling access to securable objects, see [Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control), [Privileges](https://learn.microsoft.com/windows/desktop/SecAuthZ/privileges), and [Securable Objects](https://learn.microsoft.com/windows/desktop/SecAuthZ/securable-objects).

Calls to the
[NetShareSetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharesetinfo) function ignore this member.

This member can be any of the following values.

| Value | Meaning |
| --- | --- |
| **ACCESS_READ**<br><br>0x00000001 | Permission to read data from a resource and, by default, to execute the resource. |
| **ACCESS_WRITE**<br><br>0x00000002 | Permission to write data to the resource. |
| **ACCESS_CREATE**<br><br>0x00000004 | Permission to create an instance of the resource (such as a file); data can be written to the resource as the resource is created. |
| **ACCESS_EXEC**<br><br>0x00000008 | Permission to execute the resource. |
| **ACCESS_DELETE**<br><br>0x00000010 | Permission to delete the resource. |
| **ACCESS_ATRIB**<br><br>0x00000020 | Permission to modify the resource's attributes (such as the date and time when a file was last modified). |
| **ACCESS_PERM**<br><br>0x00000040 | Permission to modify the permissions (read, write, create, execute, and delete) assigned to a resource for a user or application. |
| **ACCESS_ALL**<br><br>0x00008000 | Permission to read, write, create, execute, and delete resources, and to modify their attributes and permissions. |

### `shi503_max_uses`

Specifies a DWORD value that indicates the maximum number of concurrent connections that the shared resource can accommodate. The number of connections is unlimited if the value specified in this member is –1.

### `shi503_current_uses`

Specifies a DWORD value that indicates the number of current connections to the resource. Calls to the
[NetShareSetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharesetinfo) function ignore this member.

### `shi503_path`

A pointer to a Unicode string that contains the local path for the shared resource. For disks, this member is the path being shared. For print queues, this member is the name of the print queue being shared. Calls to the
[NetShareSetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharesetinfo) function ignore this member.

### `shi503_passwd`

A pointer to a Unicode string that specifies the share's password (when the server is running with share-level security). If the server is running with user-level security, this member is ignored. Note that Windows does not support share-level security.

This member can be no longer than SHPWLEN+1 bytes (including a terminating null character). Calls to the
[NetShareSetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharesetinfo) function ignore this member.

### `shi503_servername`

A pointer to a string that specifies the DNS or NetBIOS name of the remote server on which the shared resource resides. A value of "*" indicates no configured server name.

### `shi503_reserved`

Reserved; must be zero. Calls to the
[NetShareSetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharesetinfo) function ignore this member.

### `shi503_security_descriptor`

Specifies the
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) associated with this share.

## Remarks

The remote server specified in the **shi503_servername** member must have been bound to a transport protocol using the [NetServerTransportAddEx](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportaddex) function. In the call to **NetServerTransportAddEx**, either 2 or 3 must have been specified for the *level* parameter, and the **SVTI2_SCOPED_NAME** value must have been specified in the [SERVER_TRANSPORT_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_2) structure for the transport protocol.

## See also

[NetServerTransportAddEx](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportaddex)

[NetSessionDel](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsessiondel)

[NetShareAdd](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netshareadd)

[NetShareDelEx](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharedelex)

[NetShareEnum](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netshareenum)

[NetShareGetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharegetinfo)

[NetShareSetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharesetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[Network Share Functions](https://learn.microsoft.com/windows/desktop/NetShare/network-share-functions)