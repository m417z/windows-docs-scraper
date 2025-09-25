# PeerGraphGetRecord function

## Description

The **PeerGraphGetRecord** function retrieves a specific record based on the specified record ID. The returned record should be freed by calling [PeerGraphFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphfreedata).

## Parameters

### `hGraph` [in]

Handle to the peer graph.

### `pRecordId` [in]

Pointer to record ID to retrieve.

### `ppRecord` [out]

Receives the requested record. When this structure is no longer required, free it by calling [PeerGraphFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphfreedata).

## Return value

If the function call succeeds, the return value is S_OK. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **PEER_E_GRAPH_NOT_READY** | The peer graph has never been synchronized. Records cannot be retrieved until the peer graph has been synchronized. |
| **PEER_E_INVALID_GRAPH** | The handle to the peer graph is invalid. |
| **PEER_E_NOT_INITIALIZED** | The peer graph must be initialized with a call to [PeerGraphStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphstartup) before using this function. |
| **PEER_E_RECORD_NOT_FOUND** | The specified record was not found. |

## See also

[PEER_RECORD](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_record)

[PeerGraphFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphfreedata)