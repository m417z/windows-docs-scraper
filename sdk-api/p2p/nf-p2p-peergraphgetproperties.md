# PeerGraphGetProperties function

## Description

The **PeerGraphGetProperties** function retrieves the current peer graph properties.

## Parameters

### `hGraph` [in]

Handle to a peer graph.

### `ppGraphProperties` [out]

Receives a pointer to a [PEER_GRAPH_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_graph_properties) structure. When the structure is not needed, free it by calling [PeerGraphFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphfreedata).

## Return value

If the function call succeeds, the return value is **S_OK**. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform a specified operation. |
| **PEER_E_GRAPH_NOT_READY** | The graph is not synchronized. Data cannot be retrieved until a peer graph is synchronized. |
| **PEER_E_INVALID_GRAPH** | The handle to a peer graph is invalid. |
| **PEER_E_NOT_INITIALIZED** | A peer graph must be initialized with a call to [PeerGraphStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphstartup) before using this function. |

## See also

[PEER_GRAPH_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_graph_properties)

[PeerGraphCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphcreate)

[PeerGraphFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphfreedata)