# DFS_INFO_101 structure

## Description

Describes the state of storage on a DFS root, link, root target, or link target.

## Members

### `State`

Specifies a set of bit flags that describe the status of the host server. Following are valid values for this member. Note that the **DFS_STORAGE_STATE_OFFLINE** and **DFS_STORAGE_STATE_ONLINE** values are mutually exclusive.

The storage states can only be set on DFS root targets or DFS link targets. The DFS volume states can only be set on a DFS namespace root or DFS link and not on individual targets.

#### DFS_STORAGE_STATE_OFFLINE (0x00000001)

The DFS storage is offline.

#### DFS_STORAGE_STATE_ONLINE (0x00000002)

The DFS storage is online.

#### DFS_STORAGE_STATE_ACTIVE (0x00000004)

The DFS storage is active. This value is only for use with the [NetDfsSetClientInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfssetclientinfo) function.

#### DFS_VOLUME_STATE_OK (0x00000001)

The specified DFS root or link is in the normal state.

#### DFS_VOLUME_STATE_INCONSISTENT (0x00000002)

The internal DFS database is inconsistent with the specified DFS root or link. Attempts to repair the inconsistency have failed. This value is read-only.

#### DFS_VOLUME_STATE_OFFLINE (0x00000003)

The specified DFS root or link is offline or unavailable.

#### DFS_VOLUME_STATE_ONLINE (0x00000004)

The specified DFS root or link is available.

#### DFS_VOLUME_STATE_RESYNCHRONIZE (0x00000010)

Forces a resynchronization on the DFS root target. This flag is valid only for a DFS root target, and is write-only.

#### DFS_VOLUME_STATE_STANDBY (0x00000020)

Puts a root volume in standby mode. This flag is valid for a clustered DFS namespace only.

## See also

[Distributed File System (DFS) Functions](https://learn.microsoft.com/previous-versions/windows/desktop/dfs/distributed-file-system-dfs-functions)

[NetDfsSetClientInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfssetclientinfo)

[NetDfsSetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfssetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)