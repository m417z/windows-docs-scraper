# DFS_INFO_5 structure

## Description

Contains information about a Distributed File System (DFS) root or link. This structure contains the
name, status, **GUID**, time-out, namespace/root/link properties, metadata size, and number of targets for the root or
link. This structure is only for use with the [NetDfsEnum](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsenum),
[NetDfsGetClientInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsgetclientinfo), and
[NetDfsGetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsgetinfo) functions.

To retrieve information about the targets of the DFS namespace, use
[DFS_INFO_6](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_6) instead.

## Members

### `EntryPath`

Pointer to a null-terminated Unicode string that specifies the Universal Naming Convention (UNC) path
of a DFS root or link.

For a link, the string can be in one of two forms. The first form is as follows:

\\*ServerName*\*DfsName*\*link_path*

where *ServerName* is the name of the root target server that hosts the stand-alone
DFS namespace; *DfsName* is the name of the DFS namespace; and
*link_path* is a DFS link.

The second form is as follows:

\\*DomainName*\*DomDfsname*\*link_path*

where *DomainName* is the name of the domain that hosts the domain-based DFS
namespace; *DomDfsname* is the name of the DFS namespace; and
*link_path* is a DFS link.

For a root, the string can be in one of two forms:

\\*ServerName*\*DfsName*

or

\\*DomainName*\*DomDfsname*

where the values of the names are the same as those described previously.

### `Comment`

Pointer to a null-terminated Unicode string that contains a comment associated with the DFS root or
link.

### `State`

Specifies a set of bit flags that describe the DFS root or link. One
**DFS_VOLUME_STATE** flag is set, and one **DFS_VOLUME_FLAVOR** flag
is set. For an example that describes the interpretation of the flags, see the Remarks section of
[DFS_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_2).

#### DFS_VOLUME_STATE_OK (0x00000001)

The specified DFS root or link is in the normal state.

#### DFS_VOLUME_STATE_INCONSISTENT (0x00000002)

The internal DFS database is inconsistent with the specified DFS root or link. Attempts to repair the
inconsistency have failed.

#### DFS_VOLUME_STATE_OFFLINE (0x00000003)

The specified DFS root or link is offline or unavailable.

#### DFS_VOLUME_STATE_ONLINE (0x00000004)

The specified DFS root or link is available.

#### DFS_VOLUME_FLAVOR_STANDALONE (0x00000100)

The system sets this flag if the root is associated with a stand-alone DFS namespace.

#### DFS_VOLUME_FLAVOR_AD_BLOB (0x00000200)

The system sets this flag if the root is associated with a domain-based DFS namespace.

### `Timeout`

Specifies the time-out, in seconds, of the DFS root or link.

### `Guid`

Specifies the GUID of the DFS root or link.

### `PropertyFlags`

Specifies a set of flags describing specific properties of a DFS namespace, root, or link.

#### DFS_PROPERTY_FLAG_INSITE_REFERRALS (0x00000001)

Only targets in the same site as the client are returned. This flag is valid for both domain and
stand-alone roots and links.

#### DFS_PROPERTY_FLAG_ROOT_SCALABILITY (0x00000002)

The nearest domain controller is polled instead of the PDC for DFS namespace changes. This flag is only
valid for domain roots.

#### DFS_PROPERTY_FLAG_SITE_COSTING (0x00000004)

Active Directory site costing of targets is enabled, grouping targets into sets of increasing site costs
from DFS client to target. Each set has targets with the same cost. This flag is only valid for domain and
stand-alone roots.

#### DFS_PROPERTY_FLAG_TARGET_FAILBACK (0x00000008)

The DFS client fails back to a closer available target after failing over to a non-optimal target. This
flag is valid for both domain and stand-alone roots and links.

#### DFS_PROPERTY_FLAG_CLUSTER_ENABLED (0x00000010)

The DFS root is clustered. This flag cannot be set using the
[NetDfsSetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfssetinfo) function.

#### DFS_PROPERTY_FLAG_ABDE (0x00000020)

Scope: Domain-based DFS roots and stand-alone DFS roots.

When this flag is set, Access-Based Directory Enumeration (ABDE) mode support is enabled on the entire DFS
root target share of the DFS namespace. This flag is valid only for DFS namespaces for which the
**DFS_NAMESPACE_CAPABILITY_ABDE** capability flag is set. For more information, see
[DFS_INFO_50](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_50) and
[DFS_SUPPORTED_NAMESPACE_VERSION_INFO](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_supported_namespace_version_info).

The **DFS_PROPERTY_FLAG_ABDE** flag is valid only on the DFS namespace root and not
on root targets, links, or link targets. This flag must be enabled to associate a security descriptor with a
DFS link.

### `MetadataSize`

For domain-based DFS namespaces, this member specifies the size of the corresponding Active Directory data
blob, in bytes. For stand-alone DFS namespaces, this member specifies the size of the metadata stored in the
registry, including the key names and value names as well as the specific data items associated with them.

This member is valid for DFS roots only.

### `NumberOfStorages`

Specifies the number of targets for the DFS root or link.

## Remarks

To retrieve information about targets and target priorities, use the
[DFS_INFO_6](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_6) structure.
**DFS_INFO_5** is used to specify information about a DFS
namespace without target information.

## See also

[DFS_INFO_6](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_6)

[Distributed File System (DFS) Functions](https://learn.microsoft.com/previous-versions/windows/desktop/dfs/distributed-file-system-dfs-functions)

[NetDfsEnum](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsenum)

[NetDfsGetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsgetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)