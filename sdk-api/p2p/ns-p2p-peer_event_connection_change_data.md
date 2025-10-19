# PEER_EVENT_CONNECTION_CHANGE_DATA structure

## Description

 A [PEER_GRAPH_EVENT_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_graph_event_data) structure points to the **PEER_EVENT_CONNECTION_CHANGE_DATA** structure if one of the following peer events is triggered:

* **PEER_GRAPH_EVENT_NEIGHBOR_CONNECTION**
* **PEER_GRAPH_EVENT_DIRECT_CONNECTION**
* **PEER_GROUP_EVENT_NEIGHBOR_CONNECTION**
* **PEER_GROUP_EVENT_DIRECT_CONNECTION**

The **PEER_EVENT_CONNECTION_CHANGE_DATA** structure contains updated information that includes changes to a neighbor or direct connection.

## Members

### `dwSize`

Specifies the size of a structure.

### `status`

Specifies the type of change in a neighbor or direct connection. Valid values are the following.

| Value | Meaning |
| --- | --- |
| **PEER_CONNECTED** | A new incoming or outgoing connection to the local node has been established. |
| **PEER_CONNECTION_FAILED** | An attempt to connect to a local node has failed. <br><br>It is possible for a single attempt to connect to result in multiple connection failures. This will occur after the initial connection failure, when the peer infrastructure sets the **ullNextConnectionId** member to the Node ID and attempts a new connection. If the **ullNextConnectionId** member is 0, no further connections will be attempted. |
| **PEER_DISCONNECTED** | An existing connection has been disconnected. |

### `ullConnectionId`

 Specifies the unique ID for a connection that has changed.

### `ullNodeId`

Specifies the unique ID for the node that has changed.

### `ullNextConnectionId`

**Windows Vista or later.** Contains the next available node ID that the grouping or graphing APIs will attempt to connect to when a connection fails. If this member has a value of 0, no further connections will be attempted.

### `hrConnectionFailedReason`

**Windows Vista or later.** Specifies the type of error when a connection fails. **hrConnectionFailedReason** can return the following error codes.

| Value | Description |
| --- | --- |
| **PEER_E_CONNECTION_REFUSED** | A connection has been established and refused. The remote node is already at maximum number of connections or a connection already exists. |
| **PEER_E_CONNECTION_FAILED** | An attempt to connect to a remote node has failed. |
| **PEER_E_CONNECTION_NOT_AUTHENTICATED** | A connection is lost during the authentication phase. This is the result of a network failure or the remote node breaking the connection. |

## See also

[PEER_GRAPH_EVENT_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_graph_event_data)

[PEER_GROUP_EVENT_DATA](https://learn.microsoft.com/windows/win32/api/p2p/ns-p2p-peer_group_event_data-r1)