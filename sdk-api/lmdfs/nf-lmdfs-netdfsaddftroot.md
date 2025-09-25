# NetDfsAddFtRoot function

## Description

Creates a new domain-based Distributed File System (DFS) namespace. If the namespace already exists, the function adds the specified root target to it.

## Parameters

### `ServerName` [in]

Pointer to a string that specifies the name of the server that will host the new DFS root target. This value cannot be an IP address. This parameter is required.

### `RootShare` [in]

Pointer to a string that specifies the name of the shared folder on the server that will host the new DFS root target. This parameter is required.

### `FtDfsName` [in]

Pointer to a string that specifies the name of the new or existing domain-based DFS namespace. This parameter is required. For compatibility reasons, it should specify the same string as the *RootShare* parameter.

### `Comment` [in, optional]

Pointer to a string that contains an optional comment associated with the DFS namespace.

### `Flags` [in]

This parameter is reserved and must be zero.

## Return value

If the function succeeds, the return value is **NERR_Success**.

If the function fails, the return value is a system error code. For a list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The share specified by the *RootShare* parameter must already exist on the server that will host the new DFS root target. This function does not create a new share.

The caller must have permission to update the DFS container in the directory service and must have Administrator privilege on the DFS host (root) server.

## See also

[Distributed File System (DFS) Functions](https://learn.microsoft.com/previous-versions/windows/desktop/dfs/distributed-file-system-dfs-functions)

[NetDfsAdd](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsadd)

[NetDfsAddRootTarget](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsaddroottarget)

[NetDfsAddStdRoot](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsaddstdroot)

[NetDfsRemoveFtRoot](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsremoveftroot)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)