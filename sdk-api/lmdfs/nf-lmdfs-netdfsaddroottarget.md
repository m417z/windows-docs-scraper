# NetDfsAddRootTarget function

## Description

Creates a domain-based or stand-alone DFS namespace or adds a new root target to an existing domain-based namespace.

## Parameters

### `pDfsPath` [in]

Pointer to a string that specifies the Universal Naming Convention (UNC) path of a DFS namespace.

For a stand-alone DFS namespace, this string should be in the following format:

\\*ServerName*\*DfsName*

where *ServerName* is the name of the server that will host the new DFS root target and *DfsName* is the name of the DFS namespace.

For a domain-based DFS namespace, this string should be in the following format:

\\*DomainName*\*DomDfsName*

where *DomainName* is the name of the domain that hosts the domain-based DFS namespace and *DomDfsName* is the name of the new or existing domain-based DFS namespace. For compatibility reasons, *DomDfsName* should be the same as the name of the shared folder on the server that will host the new DFS root target.

### `pTargetPath` [in, optional]

Pointer to a null-terminated Unicode string that specifies the UNC path of a DFS root target for the DFS namespace that is specified in the *pDfsPath* parameter.

For a stand-alone DFS namespace, this parameter must be **NULL**. For a domain-based DFS namespace, the string should be in the following format:

\\*ServerName*\*RootShare*

where *ServerName* is the name of the server that will host the new DFS root target and *RootShare* is the name of the shared folder on the server. The share specified by *RootShare* must already exist on the server that will host the new DFS root target. This function does not create a new share.

### `MajorVersion` [in]

Specifies the DFS metadata version for the namespace.

**Note** This parameter is only for use when creating a new namespace.

If a stand-alone DFS namespace is being created, this parameter must be set to 1.

If a domain-based namespace is being created, this parameter should be set as follows:

* Set it to 1 to specify Windows 2000 mode.
* Set it to 2 or higher to specify Windows Server 2008 mode.

If a new root target is being added to an existing domain-based DFS namespace, this parameter must be set to zero.

### `pComment` [in, optional]

Pointer to a null-terminated Unicode string that contains a comment associated with the DFS root.

### `Flags` [in]

This parameter is reserved and must be zero.

## Return value

If the function succeeds, the return value is **NERR_Success**.

If the domain is not at the required functional level for the specified *MajorVersion*, the return value is **ERROR_DS_INCOMPATIBLE**. This return value applies only to domain roots and a *MajorVersion* of 2.

If the function fails, the return value is a system error code. For a list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The caller must have Administrator privilege on the DFS server.

To determine the DFS metadata version that can be specified in the *MajorVersion* parameter, use the [NetDfsGetSupportedNamespaceVersion](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsgetsupportednamespaceversion) function.

The following table shows which parameter values you should specify, according to the desired result.

| *pDfsPath* parameter | *pTargetPath* parameter | *MajorVersion* parameter | Result |
| --- | --- | --- | --- |
| \\*DomainName*\*DomDfsName* | \\*ServerName*\*RootShare* | 1 | Create a Windows 2000 mode domain-based DFS namespace or add a new root target to an existing one. |
| \\*DomainName*\*DomDfsName* | \\*ServerName*\*RootShare* | 2 | Create a Windows Server 2008 mode domain-based DFS namespace or add a new root target to an existing one. |
| \\*DomainName*\*DomDfsName* | \\*ServerName*\*RootShare* | 0 | Add a new root target to an existing Windows 2000 mode or Windows Server 2008 mode domain-based DFS namespace. |
| \\*ServerName*\*DfsName* | **NULL** | Must be 1. | Create a stand-alone DFS namespace. |

## See also

[DFS_NAMESPACE_VERSION_ORIGIN](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/ne-lmdfs-dfs_namespace_version_origin)

[DFS_SUPPORTED_NAMESPACE_VERSION_INFO](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_supported_namespace_version_info)

[Distributed File System (DFS) Functions](https://learn.microsoft.com/previous-versions/windows/desktop/dfs/distributed-file-system-dfs-functions)

[NetDfsAddFtRoot](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsaddftroot)

[NetDfsAddStdRoot](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsaddstdroot)

[NetDfsGetSupportedNamespaceVersion](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsgetsupportednamespaceversion)

[NetDfsRemoveRootTarget](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsremoveroottarget)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)