# PeerGraphDelete function

## Description

The **PeerGraphDelete** function deletes the data associated with a specified peer graph.

## Parameters

### `pwzGraphId` [in]

The name of a peer graph to delete data for. Specify the same ID used in calls to [PeerGraphCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphcreate) or [PeerGraphOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphopen).

### `pwzPeerId` [in]

The peer ID to delete data for. Specify the same ID used in calls to [PeerGraphCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphcreate) or [PeerGraphOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphopen).

### `pwzDatabaseName` [in]

The name of a database associated with a peer graph. Specify the same ID used in calls to [PeerGraphCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphcreate) or [PeerGraphOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphopen).

## Return value

If the function call succeeds, the return value is **S_OK**. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | Access to a graph is denied. |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **PEER_E_NOT_INITIALIZED** | A graph must be initialized with a call to [PeerGraphStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphstartup) before using this function. |

## Remarks

A peer graph must be closed by using [PeerGraphClose](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphclose) before it can be deleted.

If a delete operation fails, a Windows file error code is returned.

## See also

[PeerGraphClose](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphclose)

[PeerGraphCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphcreate)

[PeerGraphOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphopen)

[PeerGraphStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphstartup)