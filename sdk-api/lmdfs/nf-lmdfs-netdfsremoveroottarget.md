# NetDfsRemoveRootTarget function

## Description

Removes a DFS root target from a domain-based DFS namespace. If the root target is the last root target
in the DFS namespace, this function removes the DFS namespace. This function can also be used to remove a
stand-alone DFS namespace.

## Parameters

### `pDfsPath` [in]

Pointer to a string that specifies the Universal Naming Convention (UNC) path of a DFS namespace.

For a stand-alone DFS namespace, this string should be in the following form:

\\*ServerName*\*DfsName*

where *ServerName* is the name of the server that hosts the DFS root target and
*DfsName* is the name of the DFS namespace.

For a domain-based DFS namespace, this string should be in the following form:

\\*DomainName*\*DomDfsName*

where *DomainName* is the name of the domain that hosts the domain-based DFS
namespace and *DomDfsName* is the name of the DFS namespace.

### `pTargetPath` [in, optional]

Pointer to a null-terminated Unicode string that specifies the UNC path of a DFS root target for the DFS
namespace that is specified in the *pDfsPath* parameter.

For a stand-alone DFS namespace, this parameter must be **NULL**. For a domain-based
DFS namespace, the string should be in the following form:

\\*ServerName*\*RootShare*

where *ServerName* is the name of the server that hosts the DFS root target and
*RootShare* is the name of the folder on the server.

### `Flags` [in]

A flag that specifies the type of removal operation. For a stand-alone DFS namespace, this parameter must
be zero. For a domain-based DFS namespace, it can be zero or the following value. If it is zero, this indicates
a normal removal operation.

#### DFS_FORCE_REMOVE (0x80000000)

If this flag is specified for a domain-based DFS namespace, the root target is removed even if it is not
accessible.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value is a system error code. For a list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The caller must have Administrator privileges on the DFS server.

The following list shows which parameter values you should specify, according to the desired result.

| *pDfsPath* parameter | *pTargetPath* parameter | Result |
| --- | --- | --- |
| \\*DomainName*\*DomDfsName* | \\*ServerName*\*RootShare* | Delete a Windows 2000 mode or Windows Server 2008 mode domain-based DFS root target. If the target is the last root target for the DFS namespace, the function also deletes the DFS namespace. |
| \\*ServerName*\*DfsName* | **NULL** | Delete a stand-alone DFS namespace. |

## See also

[Distributed File System (DFS) Functions](https://learn.microsoft.com/previous-versions/windows/desktop/dfs/distributed-file-system-dfs-functions)

[NetDfsAddRootTarget](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsaddroottarget)

[Network Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)