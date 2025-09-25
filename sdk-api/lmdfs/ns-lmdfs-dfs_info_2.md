# DFS_INFO_2 structure

## Description

Contains information about a Distributed File System (DFS) root or link. This structure contains the name,
status, and number of DFS targets for the root or link. This structure is only for use with the
[NetDfsEnum](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsenum),
[NetDfsGetClientInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsgetclientinfo), and
[NetDfsGetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsgetinfo) functions and the
[FSCTL_DFS_GET_PKT_ENTRY_STATE](https://learn.microsoft.com/windows/desktop/dfs/fsctl-dfs-get-pkt-entry-state) control
code.

## Members

### `EntryPath`

Pointer to a null-terminated Unicode string that specifies the Universal Naming Convention (UNC) path of a DFS root or link.

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

### `Comment`

Pointer to a null-terminated Unicode string that contains a comment associated with the DFS root or link.

### `State`

Specifies a set of bit flags that describe the DFS root or link. One **DFS_VOLUME_STATE** flag is set, and one **DFS_VOLUME_FLAVOR** flag is set. The **DFS_VOLUME_FLAVORS** bitmask (0x00000300) must be used to extract the DFS namespace flavor, and the **DFS_VOLUME_STATES** bitmask (0x0000000F) must be used to extract the DFS root or link state from this member. For an example that describes the interpretation of the flags, see the following Remarks section.

#### DFS_VOLUME_STATE_OK (0x00000001)

The specified DFS root or link is in the normal state.

#### DFS_VOLUME_STATE_INCONSISTENT (0x00000002)

The internal DFS database is inconsistent with the specified DFS root or link. Attempts to repair the inconsistency have failed.

#### DFS_VOLUME_STATE_OFFLINE (0x00000003)

The specified DFS root or link is offline or unavailable.

#### DFS_VOLUME_STATE_ONLINE (0x00000004)

The specified DFS root or link is available.

#### DFS_VOLUME_FLAVOR_STANDALONE (0x00000100)

The system sets this flag if the root is associated with a stand-alone DFS namespace.

#### DFS_VOLUME_FLAVOR_AD_BLOB (0x00000200)

The system sets this flag if the root is associated with a domain-based DFS namespace.

### `NumberOfStorages`

Specifies the number of DFS targets.

## Remarks

The DFS functions use the **DFS_INFO_2** structure to
retrieve information about a DFS root or link.

Following is an example that describes interpretation of the flags that can be returned in the
**State** member:

``` syntax
FlavorBits = (Flags & DFS_VOLUME_FLAVORS)
If (FlavorBits == DFS_VOLUME_FLAVOR_STANDALONE)   // namespace is stand-alone DFS
else if (FlavorBits == DFS_VOLUME_FLAVOR_AD_BLOB) // namespace is AD blob
else                                              // unknown flavor

StateBits = (Flags & DFS_VOLUME_STATES)
// StateBits can be one of the following:
//  (DFS_VOLUME_STATE_OK, DFS_VOLUME_STATE_INCONSISTENT,
//   DFS_VOLUME_STATE_OFFLINE or DFS_VOLUME_STATE_ONLINE)
```

## See also

[Distributed File System (DFS) Functions](https://learn.microsoft.com/previous-versions/windows/desktop/dfs/distributed-file-system-dfs-functions)

[NetDfsEnum](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsenum)

[NetDfsGetClientInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsgetclientinfo)

[NetDfsGetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsgetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)