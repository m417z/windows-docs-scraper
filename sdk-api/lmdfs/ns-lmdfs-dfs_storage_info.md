# DFS_STORAGE_INFO structure

## Description

Contains information about a DFS root or link target in a DFS namespace or from the cache maintained
by the DFS client. Information about a DFS root or link target in a DFS namespace is retrieved by
calling the [NetDfsGetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsgetinfo) function. Information about a
DFS root or link target from the cache maintained by the DFS client is retrieved by calling the
[NetDfsGetClientInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsgetclientinfo) function.

## Members

### `State`

State of the target.

When this structure is returned as a result of calling the
[NetDfsGetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsgetinfo) function, this member can be one of the
following values.

#### DFS_STORAGE_STATE_OFFLINE (0x00000001)

The DFS root or link target is offline.

#### DFS_STORAGE_STATE_ONLINE (0x00000002)

The DFS root or link target is online.

When this structure is returned as a result of calling the
[NetDfsGetClientInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsgetclientinfo) function, the
**DFS_STORAGE_STATE_ONLINE** (0x00000002) state is set by default. If the target is the
active target in the DFS client cache, the following value is logically combined with the default value via the
**OR** operator.

#### DFS_STORAGE_STATE_ACTIVE (0x00000004)

The DFS root or link target is the active target.

### `ServerName`

Pointer to a null-terminated Unicode string that specifies the DFS root target or link target server
name.

### `ShareName`

Pointer to a null-terminated Unicode string that specifies the DFS root target or link target share
name.

## Remarks

The [DFS_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_3) and
[DFS_INFO_4](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_4) structures each contain one or more
**DFS_STORAGE_INFO** structures, one for each DFS target.
Only one target can be marked as the active target. It is possible that no targets will be marked active.

## See also

[DFS_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_3)

[Distributed File System (DFS) Functions](https://learn.microsoft.com/previous-versions/windows/desktop/dfs/distributed-file-system-dfs-functions)

[NetDfsEnum](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsenum)

[NetDfsGetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsgetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)