# PEER_EVENT_REQUEST_STATUS_CHANGED_DATA structure

## Description

The **PEER_EVENT_REQUEST_STATUS_CHANGED_DATA** structure contains information returned when a PEER_EVENT_REQUEST_STATUS_CHANGED event is raised on a peer participating in a peer collaboration network.

## Members

### `pEndpoint`

Pointer to a [PEER_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_endpoint) structure that contains the peer endpoint information for the contact whose change in request status raised the event.

### `hrChange`

HRESULT value that indicates the change in request status that occurred.

## Remarks

This event is raised when the infrastructure finishes processing the request for [PeerCollabRefreshEndpointData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabrefreshendpointdata) or [PeerCollabSubscribeEndpointData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabsubscribeendpointdata). If the process fails **hrChange** value will most typically be PEER_E_CONNECTION_FAILED.

## See also

[PEER_CHANGE_TYPE](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_change_type)

[PEER_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_endpoint)

[Peer Collaboration API Structures](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-structures)