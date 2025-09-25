# DFS_INFO_103 structure

## Description

Contains properties that set specific behaviors for a DFS root or link. This structure can
only be used with the [NetDfsSetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfssetinfo) function.

## Members

### `PropertyFlagMask`

Specifies a mask value that indicates which flags are valid for evaluation in the
**PropertyFlags** field.

### `PropertyFlags`

Bitfield, with each bit responsible for a specific property applicable to the whole DFS namespace, the DFS
root, or an individual DFS link, depending on the actual property. Any combination of bits is allowed unless
indicated otherwise.

#### DFS_PROPERTY_FLAG_INSITE_REFERRALS (0x00000001)

Referral response from a DFS server for a DFS root or link that contains only those targets in the same
site as the client requesting the referral. Targets in the two global priority classes are always returned,
regardless of their site location. This flag applies to domain-based DFS roots, stand-alone DFS roots, and
DFS links. If this flag is set at the DFS root, it applies to all links; otherwise, it applies to an
individual link. The setting at the link does not override the root setting.

#### DFS_PROPERTY_FLAG_ROOT_SCALABILITY (0x00000002)

If this flag is set, the DFS server polls the nearest domain controller (DC) instead of the primary domain
controller (PDC) to check for DFS namespace changes for that namespace. Any modification to the DFS metadata
by the DFS server is not controlled by this flag but is sent to the PDC. This flag is valid for the entire
namespace and applies only to domain-based DFS namespaces.

#### DFS_PROPERTY_FLAG_SITE_COSTING (0x00000004)

Set this flag to enable Active Directory site costing of targets. Targets returned from the DFS server to
the requesting DFS client are grouped by inter-site cost with respect to the DFS client. The groups are
ordered in terms of increasing site cost with the first group consisting of targets in the same site as the
client. Targets within each group are ordered randomly.

If this flag is not enabled, the default return is two sets: one set of targets in the same site as the
client, and one set of all remaining targets. This flag is valid for the entire DFS namespace and applies to
both domain-based and stand-alone DFS namespaces.

Target priorities can further influence target ordering. For more information on how site-costing is used
to prioritize targets, see
[DFS Server Target Prioritization](https://learn.microsoft.com/previous-versions/windows/desktop/dfs/dfs-server-target-prioritization).

#### DFS_PROPERTY_FLAG_TARGET_FAILBACK (0x00000008)

Set this flag to enable V4 DFS clients to fail back to a more optimal (lower cost or higher priority)
target. If this flag is set at the DFS root, it applies to all links; otherwise, it applies to an individual
link. An individual link setting will not override a root setting. The target failback setting is provided to
the DFS client in a V4 referral response by the DFS server. This flag applies to domain-based roots,
stand-alone roots, and links.

#### DFS_PROPERTY_FLAG_CLUSTER_ENABLED (0x00000010)

If this flag is set, the DFS root is clustered to provide high availability for storage failover. This
flag cannot be set using the [NetDfsSetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfssetinfo) function
and applies only to stand-alone DFS roots and links.

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

## See also

[DFS Server Target Prioritization](https://learn.microsoft.com/previous-versions/windows/desktop/dfs/dfs-server-target-prioritization)

[Distributed File System (DFS) Functions](https://learn.microsoft.com/previous-versions/windows/desktop/dfs/distributed-file-system-dfs-functions)

[NetDfsSetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfssetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)