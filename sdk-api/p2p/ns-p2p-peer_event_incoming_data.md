# PEER_EVENT_INCOMING_DATA structure

## Description

 The [PEER_GROUP_EVENT_DATA](https://learn.microsoft.com/windows/win32/api/p2p/ns-p2p-peer_group_event_data-r1) structure points to the **PEER_EVENT_INCOMING_DATA** structure if one of the following peer events is triggered:

* **PEER_GRAPH_INCOMING_DATA**
* **PEER_GROUP_INCOMING_DATA**

The **PEER_EVENT_INCOMING_DATA** structure contains updated information that includes data changes a node receives from a neighbor or direct connection.

## Members

### `dwSize`

Specifies the size of a structure.

### `ullConnectionId`

Specifies the unique ID of a data connection.

### `type`

Specifies the application-defined data type of incoming data.

### `data`

Specifies the actual data received.

## See also

[PEER_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_data)

[PEER_GRAPH_EVENT_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_graph_event_data)

[PEER_GROUP_EVENT_DATA](https://learn.microsoft.com/windows/win32/api/p2p/ns-p2p-peer_group_event_data-r1)