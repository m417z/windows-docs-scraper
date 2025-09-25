# DFS_INFO_300 structure

## Description

Contains the name and type (domain-based or stand-alone) of a DFS namespace.

## Members

### `Flags`

Value that specifies the type of the DFS namespace. This member can be one of the following values.

#### DFS_VOLUME_FLAVOR_STANDALONE (0x00000100)

Specifies a stand-alone DFS namespace.

#### DFS_VOLUME_FLAVOR_AD_BLOB (0x00000200)

Specifies a domain-based DFS namespace.

### `DfsName`

Pointer to a null-terminated Unicode string that contains the name of a DFS namespace. This member can have one of the following two formats.

The first format is:

\*ServerName*\*DfsName*

where *ServerName* is the name of the root target server that hosts the stand-alone DFS namespace and *DfsName* is the name of the DFS namespace.

The second format is:

\*DomainName*\*DomDfsName*

where *DomainName* is the name of the domain that hosts the domain-based DFS namespace and *DomDfsname* is the name of the DFS namespace.

## Remarks

The DFS functions use the
**DFS_INFO_300** structure to enumerate DFS namespaces hosted on a machine.

## See also

[Distributed File System (DFS) Functions](https://learn.microsoft.com/previous-versions/windows/desktop/dfs/distributed-file-system-dfs-functions)

[NetDfsEnum](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsenum)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)