# PeerGraphGetStatus function

## Description

The **PeerGraphGetStatus** function returns the current status of the peer graph.

## Parameters

### `hGraph` [in]

Handle to the peer graph.

### `pdwStatus` [out]

Receives the current status of the peer graph. Returns one or more of the [PEER_GRAPH_STATUS_FLAGS](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_graph_status_flags) values.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform the specified operation. |
| **PEER_E_INVALID_GRAPH** | The handle to the peer graph is invalid. |
| **PEER_E_NOT_INITIALIZED** | The peer graph must be initialized with a call to [PeerGraphStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphstartup) before using this function. |

## See also

[PEER_GRAPH_STATUS_FLAGS](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_graph_status_flags)