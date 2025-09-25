# DFS_INFO_50 structure

## Description

Contains the DFS metadata version and capabilities of an existing DFS namespace. This
structure is only for use with the [NetDfsGetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsgetinfo)
function.

## Members

### `NamespaceMajorVersion`

The major version of the DFS metadata.

### `NamespaceMinorVersion`

The minor version of the DFS metadata.

### `NamespaceCapabilities`

Specifies a set of flags that describe specific capabilities of a DFS namespace.

#### DFS_NAMESPACE_CAPABILITY_ABDE (0x0000000000000001)

The DFS namespace supports associating a security descriptor with a DFS link for Access-Based Directory
Enumeration (ABDE) purposes.

## See also

[Distributed File System Functions](https://learn.microsoft.com/previous-versions/windows/desktop/dfs/distributed-file-system-dfs-functions)

[NetDfsGetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsgetinfo)