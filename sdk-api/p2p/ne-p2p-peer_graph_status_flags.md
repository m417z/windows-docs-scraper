# PEER_GRAPH_STATUS_FLAGS enumeration

## Description

The **PEER_GRAPH_STATUS_FLAGS** enumeration is a set of flags that show the current status of a node within the peer graph.

## Constants

### `PEER_GRAPH_STATUS_LISTENING:0x0001`

Specifies whether or not the node is listening for connections.

### `PEER_GRAPH_STATUS_HAS_CONNECTIONS:0x0002`

Specifies whether or not the node has connections to other nodes.

### `PEER_GRAPH_STATUS_SYNCHRONIZED:0x0004`

Specifies whether or not the node's database is synchronized.

## See also

[PEER_GRAPH_EVENT_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_graph_event_data)

[PeerGraphGetStatus](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphgetstatus)