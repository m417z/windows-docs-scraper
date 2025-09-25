# CONNECTION_INFO_1 structure

## Description

Contains the identification number of a connection, number of open files, connection time, number of users on the connection, and the type of connection.

## Members

### `coni1_id`

Specifies a connection identification number.

### `coni1_type`

A combination of values that specify the type of connection made from the local device name to the shared resource.

One of the following values may be specified. You can isolate these values by using the **STYPE_MASK** value.

| Value | Meaning |
| --- | --- |
| **STYPE_DISKTREE** | Disk drive. |
| **STYPE_PRINTQ** | Print queue. |
| **STYPE_DEVICE** | Communication device. |
| **STYPE_IPC** | Interprocess communication (IPC). |

In addition, one or both of the following values may be specified.

| Value | Meaning |
| --- | --- |
| **STYPE_SPECIAL** | Special share reserved for interprocess communication (IPC$) or remote administration of the server (ADMIN$). Can also refer to administrative shares such as C$, D$, E$, and so forth. For more information, see [Network Share Functions](https://learn.microsoft.com/windows/desktop/NetShare/network-share-functions). |
| **STYPE_TEMPORARY** | A temporary share. |

### `coni1_num_opens`

Specifies the number of files currently open as a result of the connection.

### `coni1_num_users`

Specifies the number of users on the connection.

### `coni1_time`

Specifies the number of seconds that the connection has been established.

### `coni1_username`

Pointer to a string. If the server sharing the resource is running with user-level security, the **coni1_username** member describes which user made the connection. If the server is running with share-level security, **coni1_username** describes which computer (computername) made the connection. Note that Windows does not support share-level security.

This string is Unicode if **_WIN32_WINNT** or **FORCE_UNICODE** are defined.

### `coni1_netname`

Pointer to a string that specifies either the share name of the server's shared resource or the computername of the client. The value of this member depends on which name was specified as the *qualifier* parameter to the
[NetConnectionEnum](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netconnectionenum) function. The name not specified in the *qualifier* parameter to
**NetConnectionEnum** is automatically supplied to **coni1_netname**.

This string is Unicode if **_WIN32_WINNT** or **FORCE_UNICODE** are defined.

## See also

[NetConnectionEnum](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netconnectionenum)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[Network Share Functions](https://learn.microsoft.com/windows/desktop/NetShare/network-share-functions)