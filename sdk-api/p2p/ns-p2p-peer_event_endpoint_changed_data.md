# PEER_EVENT_ENDPOINT_CHANGED_DATA structure

## Description

The **PEER_EVENT_ENDPOINT_CHANGED_DATA** structure contains information returned when a PEER_EVENT_ENDPOINT_CHANGED or PEER_EVENT_MY_ENDPOINT_CHANGED event is raised on a peer participating in a peer collaboration network.

## Members

### `pContact`

Pointer to a [PEER_CONTACT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_contact) structure that contains the contact information for the contact who changed endpoints.

### `pEndpoint`

Pointer to a [PEER_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_endpoint) structure that contains the new active endpoint for the peer specified in *pContact*.

## Remarks

This event is raised when information about the endpoint changes. An example of this being the endpoint name in [PEER_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_endpoint) structure is changed using [PeerCollabSetEndpointName](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabsetendpointname).

## See also

[PEER_CONTACT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_contact)

[PEER_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_endpoint)

[Peer Collaboration API Structures](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-structures)