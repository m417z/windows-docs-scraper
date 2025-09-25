# DFS_INFO_106 structure

## Description

Contains the storage state and priority for a DFS root target or link target. This structure is only for use with the [NetDfsSetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfssetinfo) function.

## Members

### `State`

State of the target as one of the following values.

#### DFS_STORAGE_STATE_OFFLINE (0x00000001)

The DFS storage is offline.

#### DFS_STORAGE_STATE_ONLINE (0x00000002)

The DFS storage is online.

#### DFS_STORAGE_STATES (0x0000000F)

Mask value that indicates which storage flags are set.

### `TargetPriority`

[DFS_TARGET_PRIORITY](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_target_priority) structure that contains the specific priority class and rank of a DFS target.

## See also

[Distributed File System (DFS) Functions](https://learn.microsoft.com/previous-versions/windows/desktop/dfs/distributed-file-system-dfs-functions)

[NetDfsSetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfssetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)