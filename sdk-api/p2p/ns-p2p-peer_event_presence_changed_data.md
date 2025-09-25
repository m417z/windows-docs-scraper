# PEER_EVENT_PRESENCE_CHANGED_DATA structure

## Description

The **PEER_EVENT_PRESENCE_CHANGED_DATA** structure contains information returned when a PEER_EVENT_ENDPOINT_PRESENCE_CHANGED or PEER_EVENT_MY_PRESENCE_CHANGED event is raised on a peer participating in a peer collaboration network.

## Members

### `pContact`

Pointer to a [PEER_CONTACT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_contact) structure that contains the peer contact information for the contact whose change in presence raised the event.

### `pEndpoint`

Pointer to a [PEER_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_endpoint) structure that contains the peer endpoint information for the contact whose change in presence raised the event.

### `changeType`

[PEER_CHANGE_TYPE](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_change_type) enumeration value that specifies the type of presence change that occurred.

### `pPresenceInfo`

Pointer to a [PEER_PRESENCE_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_presence_info) structure that contains the updated presence information for the endpoint of the contact whose change in presence raised the event.

## See also

[PEER_CHANGE_TYPE](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_change_type)

[PEER_CONTACT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_contact)

[PEER_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_endpoint)

[Peer Collaboration API Structures](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-structures)