# SHARE_INFO_501 structure

## Description

Contains information about the shared resource including the name and type of the resource, and a comment associated with the resource.

## Members

### `shi501_netname`

Pointer to a Unicode string specifying the name of a shared resource.

### `shi501_type`

A combination of values that specify the type of share.

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

### `shi501_remark`

Pointer to a Unicode string specifying an optional comment about the shared resource.

### `shi501_flags`

Reserved; must be zero.

## See also

[NetShareGetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharegetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[Network Share Functions](https://learn.microsoft.com/windows/desktop/NetShare/network-share-functions)