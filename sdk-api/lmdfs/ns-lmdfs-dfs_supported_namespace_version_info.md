## Description

Contains version information for a DFS namespace.

## Members

### `DomainDfsMajorVersion`

The major version of the domain-based DFS namespace.

### `DomainDfsMinorVersion`

The minor version of the domain-based DFS namespace.

### `DomainDfsCapabilities`

Specifies a set of flags that describe specific capabilities of a domain-based DFS namespace.

#### DFS_NAMESPACE_CAPABILITY_ABDE (0x0000000000000001)

The DFS namespace supports associating a security descriptor with a DFS link for Access-Based Directory Enumeration (ABDE) purposes.

### `StandaloneDfsMajorVersion`

The major version of the stand-alone DFS namespace.

### `StandaloneDfsMinorVersion`

The minor version of the stand-alone DFS namespace.

### `StandaloneDfsCapabilities`

Specifies a set of flags that describe specific capabilities of a stand-alone DFS namespace.

#### DFS_NAMESPACE_CAPABILITY_ABDE (0x0000000000000001)

The DFS namespace supports associating a security descriptor with a DFS link for ABDE purposes.

## See also

[DFS_NAMESPACE_VERSION_ORIGIN](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/ne-lmdfs-dfs_namespace_version_origin)

[Distributed File System Functions](https://learn.microsoft.com/previous-versions/windows/desktop/dfs/distributed-file-system-dfs-functions)

[NetDfsAddRootTarget](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsaddroottarget)

[NetDfsGetSupportedNamespaceVersion](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsgetsupportednamespaceversion)