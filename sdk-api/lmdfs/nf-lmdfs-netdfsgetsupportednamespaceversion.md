# NetDfsGetSupportedNamespaceVersion function

## Description

Determines the supported metadata version number.

## Parameters

### `Origin` [in]

A [DFS_NAMESPACE_VERSION_ORIGIN](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/ne-lmdfs-dfs_namespace_version_origin) enumeration value that specifies the origin of the DFS namespace version.

### `pName` [in]

A string that specifies the server name or domain name. If the value of the *Origin* parameter is **DFS_NAMESPACE_VERSION_ORIGIN_DOMAIN**, this string must be an AD DS domain name. Otherwise, it must be a server name. This parameter is required and cannot be **NULL**.

### `ppVersionInfo` [out]

A pointer to a [DFS_SUPPORTED_NAMESPACE_VERSION_INFO](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_supported_namespace_version_info) structure that receives the DFS metadata version number.

## Return value

If the function succeeds, the return value is **NERR_Success**.

If the function fails, the return value is a system error code. For a list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

This function is useful in determining an appropriate version number to pass to the [NetDfsAddRootTarget](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsaddroottarget) function.

The version number of the DFS metadata that can be used for a new DFS namespace depends on the following:

* For domain-based DFS namespaces, the version supported by the DFS metadata schema that is being used in the AD DS domain.
* The version supported by the server that is to host the DFS root target.

Thus, the maximum DFS metadata version number that can be used for a new DFS namespace is the minimum of the version supported by the AD DS domain and the version supported by the server. This maximum can be determined by calling the **NetDfsGetSupportedNamespaceVersion** function with the *pName* parameter set to the name of the server that is to host the new DFS root target and the *Origin* parameter set to **DFS_NAMESPACE_VERSION_ORIGIN_COMBINED**.

## See also

[DFS_NAMESPACE_VERSION_ORIGIN](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/ne-lmdfs-dfs_namespace_version_origin)

[DFS_SUPPORTED_NAMESPACE_VERSION_INFO](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_supported_namespace_version_info)

[Distributed File System (DFS) Functions](https://learn.microsoft.com/previous-versions/windows/desktop/dfs/distributed-file-system-dfs-functions)

[NetDfsAddRootTarget](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsaddroottarget)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)