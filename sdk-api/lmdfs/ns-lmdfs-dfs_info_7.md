# DFS_INFO_7 structure

## Description

Contains information about a DFS namespace. This structure contains the version
**GUID** for the metadata for the namespace.

This information level is available to DFS roots only.

## Members

### `GenerationGuid`

The value of this **GUID** changes each time the DFS metadata is changed.

## Remarks

This structure is used to detect when the metadata of a DFS namespace has changed. It is currently supported
only for domain-based DFS namespace servers.

If a DFS namespace server does not support generation **GUID**s, the
**GUID** value returned by
[NetDfsGetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsgetinfo) contains a null
**GUID** (all zeros). This structure cannot be used with
[NetDfsGetClientInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsgetclientinfo).