# NetDfsRemoveFtRoot function

## Description

Removes the specified root target from a domain-based Distributed File System (DFS) namespace. If the last root target of the DFS namespace is being removed, the function also deletes the DFS namespace. A DFS namespace can be deleted without first deleting all the links in it.

## Parameters

### `ServerName` [in]

Pointer to a string that specifies the server name of the root target to be removed. The server must host the root of a domain-based DFS namespace. This parameter is required.

### `RootShare` [in]

Pointer to a string that specifies the name of the DFS root target share to be removed. This parameter is required.

### `FtDfsName` [in]

Pointer to a string that specifies the name of the domain-based DFS namespace from which to remove the root target. This parameter is required. Typically, it is the same as the *RootShare* parameter.

### `Flags`

This parameter is reserved and must be zero.

## Return value

If the function succeeds, the return value is **NERR_Success**.

If the function fails, the return value is a system error code. For a list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The root target server must be available and accessible; otherwise, the call to the **NetDfsRemoveFtRoot** function will fail.

The caller must have permission to update the DFS container in the directory service and must have Administrator privilege on the DFS host (root) server.

## See also

[Distributed File System (DFS) Functions](https://learn.microsoft.com/previous-versions/windows/desktop/dfs/distributed-file-system-dfs-functions)

[NetDfsAddFtRoot](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsaddftroot)

[NetDfsRemove](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsremove)

[NetDfsRemoveFtRootForced](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsremoveftrootforced)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)