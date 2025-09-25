# PEER_GRAPH_EVENT_TYPE enumeration

## Description

The **PEER_GRAPH_EVENT_TYPE** enumeration specifies peer event types the application is to be notified for.

## Constants

### `PEER_GRAPH_EVENT_STATUS_CHANGED:1`

The peer graph status has changed in some manner. For example, the node has synchronized with the peer graph.

### `PEER_GRAPH_EVENT_PROPERTY_CHANGED:2`

A field in the peer graph property structure has changed. This peer event does not generate a specific piece of data for an application to retrieve. The application must use [PeerGraphGetProperties](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphgetproperties) to obtain the updated structure.

### `PEER_GRAPH_EVENT_RECORD_CHANGED:3`

A record type or specific record has changed in some manner.

### `PEER_GRAPH_EVENT_DIRECT_CONNECTION:4`

A peer's direct connection has changed.

### `PEER_GRAPH_EVENT_NEIGHBOR_CONNECTION:5`

A connection to a peer neighbor has changed.

### `PEER_GRAPH_EVENT_INCOMING_DATA:6`

Data has been received from a direct or neighbor connection.

### `PEER_GRAPH_EVENT_CONNECTION_REQUIRED:7`

The peer graph has become unstable. The client should call [PeerGraphConnect](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphconnect) on a new node. This peer event does not generate a specific piece of data for an application to retrieve.

### `PEER_GRAPH_EVENT_NODE_CHANGED:8`

A node's presence status has changed in the peer graph.

### `PEER_GRAPH_EVENT_SYNCHRONIZED:9`

A specific record type has been synchronized.

## See also

[PEER_GRAPH_EVENT_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_graph_event_data)

[PEER_GRAPH_EVENT_REGISTRATION](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_graph_event_registration)

[PeerGraphConnect](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphconnect)

[PeerGraphGetProperties](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphgetproperties)