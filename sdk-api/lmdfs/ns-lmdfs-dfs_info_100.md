# DFS_INFO_100 structure

## Description

Contains a comment associated with a Distributed File System (DFS) root or link.

## Members

### `Comment`

Pointer to a null-terminated Unicode string that contains the comment associated with the specified DFS
root or link. The comment is associated with the DFS namespace root or link and not with a specific DFS root
target or link target.

## Remarks

The DFS functions use the **DFS_INFO_100** structure to
retrieve and set information about a DFS root or link.

## See also

[Distributed File System (DFS) Functions](https://learn.microsoft.com/previous-versions/windows/desktop/dfs/distributed-file-system-dfs-functions)

[NetDfsGetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsgetinfo)

[NetDfsSetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfssetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)