# DFS_INFO_9 structure

## Description

Contains the name, status, **GUID**, time-out, property flags, metadata size, DFS target information, link
reparse point security descriptor, and a list of DFS targets for a root or link. This structure is only for use
with the [NetDfsGetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsgetinfo) and
[NetDfsEnum](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsenum) functions.

## Members

### `EntryPath`

Pointer to a null-terminated Unicode string that specifies the Universal Naming Convention (UNC) path of a
DFS root or link.

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
is set. The **DFS_VOLUME_FLAVORS** bitmask (0x00000300) must be used to extract the DFS
namespace flavor, and the **DFS_VOLUME_STATES** bitmask (0x0000000F) must be used to
extract the DFS root or link state from this member. For an example that describes the interpretation of the
flags, see the Remarks section of [DFS_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_2).

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

Specifies the **GUID** of the DFS root or link.

### `PropertyFlags`

Specifies a set of flags that describe specific properties of a DFS namespace, root, or link.

#### DFS_PROPERTY_FLAG_INSITE_REFERRALS (0x00000001)

Scope: Domain roots, stand-alone roots, and links. If this flag is set at the DFS root, it applies to all
links; otherwise, the value of this flag is considered for each individual link.

When this flag is set, a DFS referral response from a DFS server for a DFS root or link with the "INSITE"
option enabled contains only those targets which are in the same site as the DFS client requesting the
referral. Targets in the two global priority classes are always returned, regardless of their site
location.

#### DFS_PROPERTY_FLAG_ROOT_SCALABILITY (0x00000002)

Scope: The entire DFS namespace for a domain-based DFS namespace only.

By default, a DFS root target server polls the PDS to detect changes to the DFS metadata. To prevent heavy
server load on the PDC, root scalability can be enabled for the DFS namespace. Setting this flag will cause
the DFS server to poll the nearest domain controller instead of the PDC for DFS metadata changes for the
common namespace. Note that any changes made to the metadata must still occur on the PDC, however.

#### DFS_PROPERTY_FLAG_SITE_COSTING (0x00000004)

Scope: The entire DFS namespace for both domain-based and stand-alone DFS namespaces.

By default, targets returned in a referral response from a DFS server to a DFS client for a DFS root or
link consists of two groups: targets in the same site as the client, and targets outside the site.

If site-costing is enabled for the Active Directory, the response can have more than two groups, with each
group containing targets with the same site cost for the specific DFS client requesting the referral. The
groups are ordered by increasing site cost. For more information about how site-costing is used to prioritize
targets, see
[DFS Server Target Prioritization](https://learn.microsoft.com/previous-versions/windows/desktop/dfs/dfs-server-target-prioritization).

#### DFS_PROPERTY_FLAG_TARGET_FAILBACK (0x00000008)

Scope: Domain-based DFS roots, stand-alone DFS roots, and DFS links. If this flag is set at the DFS root,
it applies to all links; otherwise, the value of this flag is considered for each individual link.

When this flag is set, optimal target failback is enabled for V4 DFS clients, allowing them to fail back to
an optimal target after failing over to a non-optimal one. The target failback setting is provided to the DFS
client in a V4 referral response by a DFS server.

#### DFS_PROPERTY_FLAG_CLUSTER_ENABLED (0x00000010)

Scope: Stand-alone DFS roots and links only.

The DFS root is clustered to provide high availability for storage failover. This flag cannot be set using
the [NetDfsSetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfssetinfo) function.

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
blob, in bytes. For stand-alone DFS namespaces, this field specifies the size of the metadata stored in the
registry, including the key names and value names, in addition to the specific data items associated with
them.

This field is valid for DFS roots only.

### `SecurityDescriptorLength`

### `pSecurityDescriptor.size_is`

### `pSecurityDescriptor.size_is.SecurityDescriptorLength`

### `SdLengthReserved`

This member is reserved for system use.

### `pSecurityDescriptor`

Pointer to a [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)
structure that specifies a self-relative security descriptor to be associated with the DFS link's reparse point.
This field is valid for DFS links only.

### `NumberOfStorages`

Specifies the number of targets for the DFS root or link. These targets are contained in the
**Storage** member of this structure.

### `Storage.size_is`

### `Storage.size_is.NumberOfStorages`

### `Storage`

Specifies an array of [DFS_STORAGE_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_storage_info_1)
structures that contain the DFS target information.

## See also

[Distributed File System Functions](https://learn.microsoft.com/previous-versions/windows/desktop/dfs/distributed-file-system-dfs-functions)

[NetDfsGetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsgetinfo)