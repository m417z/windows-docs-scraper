# DFS_GET_PKT_ENTRY_STATE_ARG structure

## Description

Input buffer used with the
[FSCTL_DFS_GET_PKT_ENTRY_STATE](https://learn.microsoft.com/windows/desktop/dfs/fsctl-dfs-get-pkt-entry-state) control
code.

## Members

### `DfsEntryPathLen`

Length of the DFS Entry Path Unicode string in bytes stored in the *Buffer*
parameter.

### `ServerNameLen`

Length of the Server Name Unicode string in bytes stored in the *Buffer* parameter
following the DFS Entry Path string.

### `ShareNameLen`

Length of the Share Name Unicode string in bytes stored in the *Buffer* parameter
following the Server Name string.

### `Level`

Length of the Level string in bytes.

#### 1

Return the DFS root or DFS link name. On return the output buffer for the
[FSCTL_DFS_GET_PKT_ENTRY_STATE](https://learn.microsoft.com/windows/desktop/dfs/fsctl-dfs-get-pkt-entry-state) control
code contains a [DFS_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_1) structure.

#### 2

Return the DFS root or DFS link name, status, and the number of DFS targets. On return the output buffer
for the [FSCTL_DFS_GET_PKT_ENTRY_STATE](https://learn.microsoft.com/windows/desktop/dfs/fsctl-dfs-get-pkt-entry-state)
control code contains a [DFS_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_2) structure.

#### 3

Return the DFS root or DFS link name, status, and target information. On return output buffer for the
[FSCTL_DFS_GET_PKT_ENTRY_STATE](https://learn.microsoft.com/windows/desktop/dfs/fsctl-dfs-get-pkt-entry-state) control
code contains a [DFS_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_3) structure.

#### 4

Return the DFS root or DFS link name, status, **GUID**, time-out, and target
information. On return the output buffer for the
[FSCTL_DFS_GET_PKT_ENTRY_STATE](https://learn.microsoft.com/windows/desktop/dfs/fsctl-dfs-get-pkt-entry-state) control
code contains a [DFS_INFO_4](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_4) structure.

#### 101

Set the storage state associated with the DFS root or link specified in the DFS Entry Path string. On the
return output buffer for the
[FSCTL_DFS_GET_PKT_ENTRY_STATE](https://learn.microsoft.com/windows/desktop/dfs/fsctl-dfs-get-pkt-entry-state) control
code contains a [DFS_INFO_101](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_101) structure.

### `Buffer`

On input this contains the three Unicode strings in order. The Unicode strings are not
**NULL** terminated and there is no delimiter between the strings.

## See also

[Distributed File System Structures](https://learn.microsoft.com/previous-versions/windows/desktop/dfs/distributed-file-system-structures)

[FSCTL_DFS_GET_PKT_ENTRY_STATE](https://learn.microsoft.com/windows/desktop/dfs/fsctl-dfs-get-pkt-entry-state)

[NetDfsGetClientInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsgetclientinfo)