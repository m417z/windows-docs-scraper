# PeerCollabUnsubscribeEndpointData function

## Description

The **PeerCollabUnsubscribeEndpointData** function removes a subscription to an endpoint created with [PeerCollabSubscribeEndpointData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabsubscribeendpointdata).

## Parameters

### `pcEndpoint` [in]

Pointer to a [PEER_ENDPOINT](https://learn.microsoft.com/windows/win32/api/p2p/ns-p2p-peer_endpoint) structure that contains the peer endpoint that is used to remove the subscription.

## Return value

Returns S_OK if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory to support this operation. |
| **E_INVALIDARG** | One of the arguments is invalid. |
| **PEER_E_NOT_INITIALIZED** | The Windows Peer infrastructure is not initialized. Calling the relevant initialization function is required. |

## Remarks

Each call is reference counted. As a result, the peer is unsubscribed only when the last reference is released.

The **PeerCollabUnsubscribeEndpointData** function will timeout at 30 seconds.

## See also

[PeerCollabSubscribeEndpointData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabsubscribeendpointdata)