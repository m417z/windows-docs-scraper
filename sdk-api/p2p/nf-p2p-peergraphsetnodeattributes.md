# PeerGraphSetNodeAttributes function

## Description

The **PeerGraphSetNodeAttributes** function sets the attributes of the [PEER_NODE_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_node_info) structure for the local node.

## Parameters

### `hGraph` [in]

Handle to the peer graph.

### `pwzAttributes` [in]

Pointer to a string that represents the attributes the application associates with the local node. This string is a free-form text string that is specific to the application. Specify **NULL** to delete all attributes for the specified node.

## Return value

If the function call succeeds, the return value is S_OK. Otherwise, it returns one of the following value.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform the specified operation. |
| **PEER_E_INVALID_GRAPH** | The handle to the peer graph is invalid. |
| **PEER_E_NOT_INITIALIZED** | The peer graph must be initialized with a call to [PeerGraphStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphstartup) before using this function. |

## Remarks

To retrieve attributes for a node, call [PeerGraphGetNodeInfo](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphgetnodeinfo).

## See also

[PEER_NODE_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_node_info)

[PeerGraphGetNodeInfo](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphgetnodeinfo)