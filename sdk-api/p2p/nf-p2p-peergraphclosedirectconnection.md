# PeerGraphCloseDirectConnection function

## Description

The **PeerGraphCloseDirectConnection** function closes a specified direct connection.

## Parameters

### `hGraph` [in]

Handle to a peer graph.

### `ullConnectionId` [in]

Specifies the connection ID to disconnect from.

## Return value

If the function call succeeds, the return value is **S_OK**. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **PEER_E_CONNECTION_NOT_FOUND** | No connection with the specified ID exists. |
| **PEER_E_INVALID_GRAPH** | The handle to a peer graph is invalid. |
| **PEER_E_NOT_INITIALIZED** | The graph must be initialized with a call to [PeerGraphStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphstartup) before using this function. |

## See also

[PeerGraphOpenDirectConnection](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphopendirectconnection)