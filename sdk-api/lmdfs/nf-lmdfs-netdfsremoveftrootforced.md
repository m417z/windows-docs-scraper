# NetDfsRemoveFtRootForced function

## Description

Removes the specified root target from a domain-based Distributed File System (DFS) namespace, even if the root target server is offline. If the last root target of the DFS namespace is being removed, the function also deletes the DFS namespace. A DFS namespace can be deleted without first deleting all the links in it.

**Note** The
**NetDfsRemoveFtRootForced** function does not update the registry on the DFS root target server. For more information, see the Remarks section.

## Parameters

### `DomainName` [in]

Pointer to a string that specifies the name of the Active Directory domain that contains the domain-based DFS namespace to be removed. This parameter is required.

### `ServerName` [in]

Pointer to a string that specifies the name of the DFS root target server to be removed. The server must host a root of the domain-based DFS namespace. This parameter is required.

### `RootShare` [in]

Pointer to a string that specifies the name of the DFS root target share to be removed. This parameter is required.

### `FtDfsName` [in]

Pointer to a string that specifies the name of the domain-based DFS namespace from which to remove the root target. This parameter is required. Typically, it is the same as the *RootShare* parameter.

### `Flags`

Must be zero.

## Return value

If the function succeeds, the return value is **NERR_Success**.

If the function fails, the return value is a system error code. For a list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The caller must have permission to update the DFS container in the directory service and must have Administrator privilege on the DFS host (root) server.

The **NetDfsRemoveFtRootForced** function forcibly removes a domain-based DFS root target from a DFS namespace. It is used to delete a domain-based DFS namespace when the root target servers of the namespace are no longer available (for example, because they have been decommissioned).

Because the DFS root target is removed by contacting the primary domain controller (PDC) and not by removing the DFS root target server, **NetDfsRemoveFtRootForced** does not update the registry of the root target server. Under normal circumstances, you can remove the root target from a DFS domain root by calling the
[NetDfsRemoveFtRoot](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsremoveftroot) function.

## See also

[Distributed File System (DFS) Functions](https://learn.microsoft.com/previous-versions/windows/desktop/dfs/distributed-file-system-dfs-functions)

[NetDfsAddFtRoot](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsaddftroot)

[NetDfsRemoveFtRoot](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsremoveftroot)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)