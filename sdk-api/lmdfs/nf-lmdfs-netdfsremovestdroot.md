# NetDfsRemoveStdRoot function

## Description

Deletes a stand-alone Distributed File System (DFS) namespace.

## Parameters

### `ServerName` [in]

Pointer to a string that specifies the DFS root target server name of the stand-alone DFS namespace to be removed. This parameter is required.

### `RootShare` [in]

Pointer to a string that specifies the DFS root target share name of the stand-alone DFS namespace to be removed. This parameter is required.

### `Flags` [in]

Must be zero.

## Return value

If the function succeeds, the return value is **NERR_Success**.

If the function fails, the return value is a system error code. For a list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The caller must have Administrator privilege on the DFS server. For more information about calling functions that require administrator privileges, see [Running with Special Privileges](https://learn.microsoft.com/windows/desktop/SecBP/running-with-special-privileges).

## See also

[Distributed File System (DFS) Functions](https://learn.microsoft.com/previous-versions/windows/desktop/dfs/distributed-file-system-dfs-functions)

[NetDfsAddStdRoot](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsaddstdroot)

[NetDfsRemove](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsremove)

[NetDfsRemoveFtRoot](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsremoveftroot)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)