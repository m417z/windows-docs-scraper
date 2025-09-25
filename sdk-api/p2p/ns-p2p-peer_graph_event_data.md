# PEER_GRAPH_EVENT_DATA structure

## Description

The **PEER_GRAPH_EVENT_DATA** structure contains data associated with a peer event.

## Members

### `eventType`

The type of peer event this data corresponds to. Must be one of the [PEER_GRAPH_EVENT_TYPE](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_graph_event_type) values. The members that remain are given values based on the peer event type that has occurred. Not all members contain data.

### `dwStatus`

This member is given a value if the [PEER_GRAPH_EVENT_STATUS_CHANGE](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_graph_event_type) peer event is triggered. A change has been made in relation to a node's connection to the graph.

### `incomingData`

This member is given a value if the [PEER_GRAPH_INCOMING_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_event_incoming_data) peer event is triggered. A node has received data from a neighbor or a direct connection.

### `recordChangeData`

This member given a value if the [PEER_GRAPH_EVENT_RECORD_CHANGE](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_event_record_change_data) peer event is triggered. A record type the application asked for notifications of has changed.

### `connectionChangeData`

This member is given a value if the [PEER_GRAPH_EVENT_NEIGHBOR_CONNECTION](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_event_connection_change_data) or **PEER_GRAPH_EVENT_DIRECT_CONNECTION** peer event is triggered. An aspect of a neighbor or direct connection state has changed.

### `nodeChangeData`

This member is given a value if the [PEER_GRAPH_EVENT_NODE_CHANGED](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_event_node_change_data) peer event is triggered. A node's presence state has changed.

### `synchronizedData`

This member is given a value if the [PEER_GRAPH_EVENT_SYNCHRONIZED](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_event_synchronized_data) peer event is triggered. A record type has completed its synchronization.

## See also

[PEER_EVENT_CONNECTION_CHANGE_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_event_connection_change_data)

[PEER_EVENT_INCOMING_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_event_incoming_data)

[PEER_EVENT_NODE_CHANGE_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_event_node_change_data)

[PEER_EVENT_RECORD_CHANGE_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_event_record_change_data)

[PEER_EVENT_SYNCHRONIZED_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_event_synchronized_data)

[PEER_GRAPH_EVENT_TYPE](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_graph_event_type)

[PEER_GRAPH_STATUS_FLAGS](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_graph_status_flags)

[PeerGraphGetEventData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphgeteventdata)