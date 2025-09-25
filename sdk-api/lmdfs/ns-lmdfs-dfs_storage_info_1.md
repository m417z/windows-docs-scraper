# DFS_STORAGE_INFO_1 structure

## Description

Contains information about a DFS target, including the DFS target server name and share name as well as the target's state and priority.

## Members

### `State`

State of the target. This member can be one of the following values.

#### DFS_STORAGE_STATE_OFFLINE (0x00000001)

The DFS storage is offline.

#### DFS_STORAGE_STATE_ONLINE (0x00000002)

The DFS storage is online.

#### DFS_STORAGE_STATES (0x0000000F)

Mask value that indicates which storage flags are set.

### `ServerName`

Pointer to a null-terminated Unicode string that specifies the DFS root target or link target server name.

### `ShareName`

Pointer to a null-terminated Unicode string that specifies the DFS root target or link target share name.

### `TargetPriority`

[DFS_TARGET_PRIORITY](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_target_priority) structure that contains a DFS target's priority class and rank.

## Remarks

This structure is used as the **Storage** member of the [DFS_INFO_6](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_6) structure.

## See also

[DFS_INFO_6](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_6)