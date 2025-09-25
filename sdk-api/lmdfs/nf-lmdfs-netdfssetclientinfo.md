# NetDfsSetClientInfo function

## Description

Modifies information about a Distributed File System (DFS) root or link in the cache maintained by the DFS client.

## Parameters

### `DfsEntryPath` [in]

Pointer to a string that specifies the Universal Naming Convention (UNC) path of a DFS root or link.

For a link, the string can be in one of two forms. The first form is as follows:

\\*ServerName*\*DfsName*\*link_path*

where *ServerName* is the name of the root target server that hosts the stand-alone DFS namespace; *DfsName* is the name of the DFS namespace; and *link_path* is a DFS link.

The second form is as follows:

\\*DomainName*\*DomDfsname*\*link_path*

where *DomainName* is the name of the domain that hosts the domain-based DFS namespace; *DomDfsname* is the name of the DFS namespace; and *link_path* is a DFS link.

For a root, the string can be in one of two forms:

\\*ServerName*\*DfsName*

or

\\*DomainName*\*DomDfsname*

where the values of the names are the same as those described previously.

This parameter is required.

### `ServerName` [in, optional]

Pointer to a string that specifies the DFS link target server name. This parameter is optional. For more information, see the Remarks section.

### `ShareName` [in, optional]

Pointer to a string that specifies the DFS link target share name. This parameter is optional. For additional information, see the following Remarks section.

### `Level` [in]

Specifies the information level of the request. This parameter can be one of the following values.

#### 101

Set the local DFS link's storage status. The *Buffer* parameter points to a
[DFS_INFO_101](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_101) structure.

#### 102

Set the local DFS link time-out. The *Buffer* parameter points to a
[DFS_INFO_102](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_102) structure. For more information, see the following Remarks section.

### `Buffer` [in]

Pointer to a buffer that contains the information to be set. The format of this information depends on the value of the *Level* parameter. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers).

## Return value

If the function succeeds, the return value is **NERR_Success**.

If the function fails, the return value is a system error code. For a list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The caller must have Administrator privilege on the DFS server. For more information about calling functions that require administrator privileges, see [Running with Special Privileges](https://learn.microsoft.com/windows/desktop/SecBP/running-with-special-privileges).

Setting the time-out to zero may not immediately delete the local cached copy of the DFS link, because threads may be referencing the entry.

Because there is only one time-out on a DFS link, the *ServerName* and *ShareName* parameters are ignored for level 102.

The **DFS_STORAGE_STATE_ONLINE** and **DFS_STORAGE_STATE_OFFLINE** bits will be ignored. The **DFS_STORAGE_STATE_ACTIVE** bit is valid only if no files are open to the active computer.

## See also

[DFS_INFO_101](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_101)

[DFS_INFO_102](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_102)

[Distributed File System (DFS) Functions](https://learn.microsoft.com/previous-versions/windows/desktop/dfs/distributed-file-system-dfs-functions)

[NetDfsGetClientInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsgetclientinfo)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)