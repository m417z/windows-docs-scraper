# PEER_EVENT_NODE_CHANGE_DATA structure

## Description

The **PEER_EVENT_NODE_CHANGE_DATA** structure contains a pointer to the data if a **PEER_GRAPH_EVENT_NODE_CHANGE** event is triggered.

## Members

### `dwSize`

Specifies the size of the structure. Should set to the size of PEER_EVENT_NODE_CHANGE_DATA.

### `changeType`

Specifies the new state of the node. Valid values are the following.

| Value | Meaning |
| --- | --- |
| **PEER_NODE_CHANGE_CONNECTED** | The node is present in the graph. |
| **PEER_NODE_CHANGE_DISCONNECTED** | The node is no longer present in the graph. |
| **PEER_NODE_CHANGE_UPDATED** | The node has new information, for example, the attributes have changed. |

### `ullNodeId`

Specifies the unique ID of the node that has changed.

### `pwzPeerId`

Specifies the peer ID of the node that has changed.

## See also

[PEER_GRAPH_EVENT_DATA](https://learn.microsoft.com/windows/win32/api/p2p/ns-p2p-peer_graph_event_data)