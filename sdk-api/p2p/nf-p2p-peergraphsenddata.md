# PeerGraphSendData function

## Description

The **PeerGraphSendData** function sends data to a neighbor node or a directly connected node.

## Parameters

### `hGraph` [in]

Handle to the peer graph.

### `ullConnectionId` [in]

Specifies the unique ID of the connection to send data on.

### `pType` [in]

Specifies an application-defined data type to send. This parameter cannot be **NULL**.

### `cbData` [in]

Specifies the number of bytes pointed to by *pvData*.

### `pvData` [in]

Pointer to the data to send.

## Return value

Returns S_OK if the operation succeeds; otherwise, the function returns one of the following values:

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **PEER_E_CONNECTION_NOT_FOUND** | No connection with the given ID exists. |
| **PEER_E_INVALID_GRAPH** | The handle to the peer graph is invalid. |
| **PEER_E_NOT_INITIALIZED** | The graph must be initialized with a call to [PeerGraphStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphstartup) before using this function. |

## Remarks

The **PeerGraphSendData** function returns as soon as data has been sent to the network layer; the peer graphing layer does not wait for an acknowledgment from the other side of the connection.

**Note** In order to be able to receive data with a direct connection, an application must register for a peer event of type **PEER_GRAPH_EVENT_INCOMING_DATA**. See [PeerGraphRegisterEvent](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphregisterevent).

## See also

[PeerGraphEnumConnections](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphenumconnections)

[PeerGraphOpenDirectConnection](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphopendirectconnection)

[PeerGraphRegisterEvent](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphregisterevent)