# PeerGraphClose function

## Description

The **PeerGraphClose** function invalidates the peer graph handle returned by a call to either [PeerGraphCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphcreate) or [PeerGraphOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphopen), and closes all network connections for the specified peer graph.

## Parameters

### `hGraph` [in]

Handle to the peer graph to close.

## Return value

If the function call succeeds, the return value is **S_OK**. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The parameter is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform the specified operation. |
| **PEER_E_INVALID_GRAPH** | The handle to the peer graph is invalid. |
| **PEER_E_NOT_INITIALIZED** | The peer graph must be initialized with a call to [PeerGraphStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphstartup) before using this function. |

## See also

[PeerGraphCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphcreate)

[PeerGraphOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphopen)