# NetDfsGetClientInfo function

## Description

Retrieves information about a Distributed File System (DFS) root or link from the cache maintained by the DFS client.

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

Pointer to a string that specifies the name of the DFS root target or link target server. This parameter is optional.

### `ShareName` [in, optional]

Pointer to a string that specifies the name of the share corresponding to the DFS root target or link target. This parameter is optional.

### `Level` [in]

Specifies the information level of the request. This parameter can be one of the following values.

#### 1

Return the DFS root or DFS link name. The *Buffer* parameter points to a
[DFS_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_1) structure.

#### 2

Return the DFS root or DFS link name, status, and the number of DFS targets. The *Buffer* parameter points to a
[DFS_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_2) structure.

#### 3

Return the DFS root or DFS link name, status, and target information. The *Buffer* parameter points to a
[DFS_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_3) structure.

#### 4

Return the DFS root or DFS link name, status, **GUID**, time-out, and target information. The *Buffer* parameter points to a
[DFS_INFO_4](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_4) structure.

### `Buffer` [out]

Pointer to the address of a buffer that receives the requested information. This buffer is allocated by the system and must be freed using the
[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers) and
[Network Management Function Buffer Lengths](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffer-lengths).

## Return value

If the function succeeds, the return value is **NERR_Success**.

If the function fails, the return value is a system error code. For a list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

No special group membership is required for using the
**NetDfsGetClientInfo** function.

## See also

[DFS_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_1)

[DFS_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_2)

[DFS_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_3)

[DFS_INFO_4](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_4)

[Distributed File System (DFS) Functions](https://learn.microsoft.com/previous-versions/windows/desktop/dfs/distributed-file-system-dfs-functions)

[NetDfsSetClientInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfssetclientinfo)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)