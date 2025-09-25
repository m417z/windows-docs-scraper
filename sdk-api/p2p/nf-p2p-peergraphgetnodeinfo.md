# PeerGraphGetNodeInfo function

## Description

The **PeerGraphGetNodeInfo** function retrieves information about a specific node.

## Parameters

### `hGraph` [in]

Handle to a peer graph.

### `ullNodeId` [in]

Specifies the ID of a node that an application receives information about. Specify zero (0) to retrieve information about the local node.

### `ppNodeInfo` [out]

Receives a pointer to a [PEER_NODE_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_node_info) structure that contains the requested information. When the handle is not needed, free it by calling [PeerGraphFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphfreedata).

## Return value

If the function succeeds, the return value is **S_OK**. Otherwise, the function returns one of the following error codes.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One parameter is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform a specified operation. |
| **PEER_E_INVALID_GRAPH** | The handle to a peer graph is invalid. |
| **PEER_E_NOT_INITIALIZED** | A peer graph must be initialized by using a call to [PeerGraphStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphstartup) before using this function. |
| **PEER_E_NODE_NOT_FOUND** | A specified node is not found. |

## Remarks

There can be several nodes of a graph on a computer. For example, multiple users may have joined the graph on a specific computer, so the information that **PeerGraphGetNodeInfo** returns is about each node—not each computer.

## See also

[PEER_NODE_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_node_info)

[PeerGraphFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphfreedata)