# DFS_INFO_1 structure

## Description

Contains the name of a Distributed File System (DFS) root or link. This structure is only for use with the
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

## Remarks

The DFS functions use the
**DFS_INFO_1** structure to retrieve information about a DFS root or link.

## See also

[Distributed File System (DFS) Functions](https://learn.microsoft.com/previous-versions/windows/desktop/dfs/distributed-file-system-dfs-functions)

[NetDfsEnum](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsenum)

[NetDfsGetClientInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsgetclientinfo)

[NetDfsGetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsgetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)