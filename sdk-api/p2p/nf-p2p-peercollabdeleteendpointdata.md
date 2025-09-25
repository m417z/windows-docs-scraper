# PeerCollabDeleteEndpointData function

## Description

The **PeerCollabDeleteEndpointData** function deletes the peer endpoint data on the calling peer node that matches the supplied endpoint data.

## Parameters

### `pcEndpoint` [in]

Pointer to a [PEER_ENDPOINT](https://learn.microsoft.com/windows/win32/api/p2p/ns-p2p-peer_endpoint) structure that contains the peer endpoint information to delete from the current peer node.

## Return value

Returns S_OK if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory to support this operation. |
| **E_INVALIDARG** | One of the arguments is invalid. |

## Remarks

The function **PeerCollabDeleteEndpointData** is used to remove cached endpoint data previously retrieved by [PeerCollabRefreshEndpointData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabrefreshendpointdata) when it is no longer required. Any data obtained through **PeerCollabRefreshEndpointData** remains in memory until **PeerCollabDeleteEndpointData** is called.

## See also

[PEER_ENDPOINT](https://learn.microsoft.com/windows/win32/api/p2p/ns-p2p-peer_endpoint)

[Peer Collaboration API Functions](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-functions)

[PeerCollabRefreshEndpointData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabrefreshendpointdata)