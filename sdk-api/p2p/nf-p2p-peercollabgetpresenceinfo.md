# PeerCollabGetPresenceInfo function

## Description

The **PeerCollabGetPresenceInfo** function retrieves the presence information for the endpoint associated with a specific contact.

## Parameters

### `pcEndpoint` [in]

Pointer to a [PEER_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_endpoint) structure that contains the specific endpoint associated with the contact specified in *pcContact* for which presence information must be returned.

### `ppPresenceInfo` [out]

Pointer to the address of the [PEER_PRESENCE_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_presence_info) structure that contains the requested presence data for the supplied endpoint.

## Return value

Returns S_OK if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory to support this operation. |
| **E_INVALIDARG** | One of the arguments is invalid. |
| **PEER_E_NOT_INITIALIZED** | The application did not make a previous call to [PeerCollabStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabstartup). |
| **PEER_E_NOT_FOUND** | The presence information for the specified endpoint was not found in the peer collaboration network. |

## Remarks

To obtain a peer object successfully:

* The endpoint must have been previously obtained by calling [PeerCollabEnumEndpoints](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabenumendpoints).
* The local peer must have subscribed to the endpoint by calling [PeerCollabSubscribeEndpointData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabsubscribeendpointdata).
* The endpoint data must be refreshed by calling [PeerCollabRefreshEndpointData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabrefreshendpointdata) successfully.

## See also

[PEER_CONTACT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_contact)

[PEER_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_endpoint)

[PEER_PRESENCE_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_presence_info)

[Peer Collaboration API Functions](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-functions)