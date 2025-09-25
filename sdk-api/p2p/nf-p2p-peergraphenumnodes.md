# PeerGraphEnumNodes function

## Description

The **PeerGraphEnumNodes** function creates and returns an enumeration handle used to enumerate the nodes in a peer graph. The enumeration provides a snapshot of a peer graph at the time an enumeration is performed. Depending on the policy of a peer graph, and if nodes do not publish presence information, an enumeration does not return some nodes that are connected to a peer graph.

## Parameters

### `hGraph` [in]

Handle to a peer graph.

### `pwzPeerId` [in]

The peer ID to obtain a node enumeration. Specify **NULL** to return all nodes in a peer graph.

### `phPeerEnum` [out]

Receives a handle to an enumeration. Use [PeerGraphGetNextItem](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphgetnextitem) to retrieve the actual node information. When this handle is not needed, free it by calling [PeerGraphEndEnumeration](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphendenumeration).

## Return value

If a function call succeeds, the return value is **S_OK**. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One parameter is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform a specified operation. |
| **PEER_E_INVALID_GRAPH** | The handle to a peer graph is invalid. |
| **PEER_E_NOT_INITIALIZED** | A peer graph must be initialized with a call to [PeerGraphStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphstartup) before using this function. |
| **PEER_E_NOT_READY** | A peer graph is not synchronized completely, and the nodes cannot be enumerated. |
| **PEER_E_PRESENCE_DISABLED** | A peer graph does not require presence information. Therefore, the nodes cannot be enumerated. |

## Remarks

If [PeerGraphGetNextItem](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphgetnextitem) is called with the handle that **PeerGraphEnumNodes** returns, then **PeerGraphGetNextItem** returns the data in the [PEER_NODE_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_node_info) structure.

## See also

[PEER_NODE_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_node_info)

[PeerGraphEndEnumeration](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphendenumeration)

[PeerGraphGetItemCount](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphgetitemcount)

[PeerGraphGetNextItem](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphgetnextitem)