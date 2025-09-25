# PeerGraphOpenDirectConnection function

## Description

The **PeerGraphOpenDirectConnection** function allows an application to establish a direct connection with a node in a peer graph. The connection can only be made if the node to which the application is connecting has subscribed to the **PEER_GRAPH_EVENT_DIRECT_CONNECTION** event. The application can then send data directly to another node. A call to this function is asynchronous.

## Parameters

### `hGraph` [in]

Handle to a peer graph.

### `pwzPeerId` [in]

Pointer to the unique ID of a user or node to connect to. This parameter is used to identify a specific user because multiple identities can be attached to the specified address.

### `pAddress` [in]

Pointer to a [PEER_ADDRESS](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_address) structure that contains the address of the node to connect to.

### `pullConnectionId` [out]

Receives the connection ID for the requested connection.

## Return value

If the function call succeeds, the return value is **S_OK**. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **PEER_E_INVALID_GRAPH** | The handle to the graph is invalid. |
| **PEER_E_NOT_INITIALIZED** | The graph must be initialized with a call to [PeerGraphStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphstartup)—before using this function. |

## Remarks

A call to **PeerGraphOpenDirectConnection** is an asynchronous call. A **PEER_GRAPH_EVENT_DIRECT_CONNECTION** event is triggered to inform the application of the direct connection's success or failure. The actual status of the function's success or failure is given in the [PEER_GRAPH_EVENT_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_graph_event_data) structure.

## See also

[PEER_ADDRESS](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_address)

[PeerGraphCloseDirectConnection](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphclosedirectconnection)

[PeerGraphEnumConnections](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphenumconnections)