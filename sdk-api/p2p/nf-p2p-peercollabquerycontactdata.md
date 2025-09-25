# PeerCollabQueryContactData function

## Description

The **PeerCollabQueryContactData** function retrieves the contact information for the supplied peer endpoint.

## Parameters

### `pcEndpoint` [in, optional]

Pointer to a [PEER_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_endpoint) structure that contains the peer endpoint about which to obtain contact information.

If this parameter is set to **NULL**, the contact information for the current peer endpoint is obtained.

### `ppwzContactData` [out]

Pointer to a zero-terminated Unicode string buffer that contains the contact data for the endpoint supplied in *pcEndpoint*. Call [PeerFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerfreedata) to free the data.

## Return value

Returns S_OK if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory to support this operation. |
| **E_INVALIDARG** | One of the arguments is invalid. |
| **PEER_E_NOT_FOUND** | The requested contact data does not exist. Try calling [PeerCollabRefreshEndpointData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabrefreshendpointdata) before making another attempt. |

## Remarks

To retrieve contact data for an endpoint successfully, one of the following must occur:

* The endpoint must have been previously obtained by calling [PeerCollabEnumEndpoints](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabenumendpoints).
* The local peer must have subscribed to the endpoint by calling [PeerCollabSubscribeEndpointData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabsubscribeendpointdata).
* The endpoint data must be refreshed by calling [PeerCollabRefreshEndpointData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabrefreshendpointdata) successfully.

## See also

[PEER_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_endpoint)

[Peer Collaboration API Functions](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-functions)