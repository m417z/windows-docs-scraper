# PeerGraphStartup function

## Description

The **PeerGraphStartup** function indicates to the Peer Graphing Infrastructure what version of the Peer protocols the calling application requires. **PeerGraphStartup** must be called before any other peer graphing functions. It must be matched by a call to [PeerGraphShutdown](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphshutdown).

## Parameters

### `wVersionRequested` [in]

Specify PEER_GRAPH_VERSION.

### `pVersionData` [out]

Pointer to a [PEER_VERSION_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_version_data) structure that receives the
version of the Peer Infrastructure installed on the local computer.

## Return value

Returns S_OK if the operation succeeds; otherwise, the function returns one of the following values:

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory to perform the specified operation. |
| **PEER_E_UNSUPPORTED_VERSION** | The version requested is not supported by the Peer Infrastructure .dll installed on the local computer. |

## See also

[PEER_VERSION_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_version_data)

[PeerGraphShutdown](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphshutdown)