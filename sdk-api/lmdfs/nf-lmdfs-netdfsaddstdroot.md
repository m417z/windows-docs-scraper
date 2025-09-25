# NetDfsAddStdRoot function

## Description

Creates a new stand-alone Distributed File System (DFS) namespace.

## Parameters

### `ServerName` [in]

Pointer to a string that specifies the name of the server that will host the new stand-alone DFS namespace. This parameter is required.

### `RootShare` [in]

Pointer to a string that specifies the name of the shared folder for the new stand-alone DFS namespace on the server that will host the namespace. This parameter is required.

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

The caller must have Administrator privilege on the DFS server. For more information about calling functions that require administrator privileges, see
[Running with Special Privileges](https://learn.microsoft.com/windows/desktop/SecBP/running-with-special-privileges).

## See also

[Distributed File System (DFS) Functions](https://learn.microsoft.com/previous-versions/windows/desktop/dfs/distributed-file-system-dfs-functions)

[NetDfsAddFtRoot](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsaddftroot)

[NetDfsAddRootTarget](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsaddroottarget)

[NetDfsRemoveStdRoot](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsremovestdroot)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)