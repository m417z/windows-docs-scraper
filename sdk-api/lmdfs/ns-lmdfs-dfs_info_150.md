# DFS_INFO_150 structure

## Description

Contains the security descriptor for a DFS link's reparse point. This structure is only for
use with the [NetDfsGetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsgetinfo) and
[NetDfsSetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfssetinfo) functions.

## Members

### `SecurityDescriptorLength`

### `pSecurityDescriptor.size_is`

### `pSecurityDescriptor.size_is.SecurityDescriptorLength`

### `SdLengthReserved`

This member is reserved for system use.

### `pSecurityDescriptor`

Pointer to a [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)
structure that specifies a self-relative security descriptor to be associated with the DFS link's reparse
point. This field is valid for DFS links only.

## See also

[Distributed File System Functions](https://learn.microsoft.com/previous-versions/windows/desktop/dfs/distributed-file-system-dfs-functions)

[NetDfsGetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsgetinfo)

[NetDfsSetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfssetinfo)