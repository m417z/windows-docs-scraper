# PeerGraphConnect function

## Description

The **PeerGraphConnect** function attempts to make a connection to a specified node in a peer graph. This function starts an asynchronous operation. The calling application must wait for a **PEER_GRAPH_EVENT_NEIGHBOR_CONNECTION** event to determine if the connection attempt is successful.

## Parameters

### `hGraph` [in]

Handle to a peer graph.

### `pwzPeerId` [in]

The unique ID of a peer to connect to at *pAddress*. Specify **NULL** to connect to any peer listening at a specified address in the same peer graph.

### `pAddress` [in]

Pointer to a [PEER_ADDRESS](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_address) structure that identifies a node to connect to.

### `pullConnectionId` [out]

Receives the pointer to an **ULONGLONG** that contains the connection ID. This ID can be used with the direct communication functions.

## Return value

If the function call succeeds, the return value is **S_OK**. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform a specified operation. |
| **PEER_E_ALREADY_EXISTS** | A neighbor connection to a specified node already exists. |
| **PEER_E_INVALID_GRAPH** | The handle to a peer graph is invalid. |
| **PEER_E_NOT_INITIALIZED** | A graph must be initialized with a call to [PeerGraphStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphstartup) before using this function. |

## See also

[PEER_ADDRESS](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_address)

[PeerGraphGetEventData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphgeteventdata)

[PeerGraphListen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphlisten)

[PeerGraphOpenDirectConnection](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphopendirectconnection)

[PeerGraphSendData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphsenddata)