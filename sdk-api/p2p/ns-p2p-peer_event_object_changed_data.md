# PEER_EVENT_OBJECT_CHANGED_DATA structure

## Description

The **PEER_EVENT_OBJECT_CHANGED_DATA** structure contains information returned when a PEER_EVENT_ENDPOINT_OBJECT_CHANGED or PEER_EVENT_MY_OBJECT_CHANGED event is raised on a peer participating in a peer collaboration network.

## Members

### `pContact`

Pointer to a [PEER_CONTACT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_contact) structure that contains the peer contact information for the contact whose peer object data changed.

### `pEndpoint`

Pointer to a [PEER_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_endpoint) structure that contains the peer endpoint information for the contact whose peer object data changed.

### `changeType`

[PEER_CHANGE_TYPE](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_change_type) enumeration value that specifies the type of change that occurred.

### `pObject`

Pointer to a [PEER_OBJECT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_object) structure that contains the peer object data whose change raised the event. This most commonly occurs when a new peer object is received by the peer.

## Remarks

Peer objects are run-time data items associated with a particular application, such as a picture or avatar, a certificate, or a specific description. Each peer object must be smaller than 16K in size.

Trusted contacts watching this peer object will have a PEER_EVENT_OBJECT_CHANGED event raised on them signaling the peer object's change in status.

The PEER_EVENT_OBJECT_CHANGED event is raised when an object is changed by calling [PeerCollabSetObject](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabsetobject). If it is the first time the object is set then **changeType** is set to PEER_CHANGE_ADDED. On subsequent calls of PeerCollabSetObject for the same object ID the **changeType** is set to PEER_CHANGE_UDPATED.

If [PeerCollabDeleteObject](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabdeleteobject) is called the PEER_CHANGE_DELETED event is raised.

## See also

[PEER_CHANGE_TYPE](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_change_type)

[PEER_CONTACT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_contact)

[PEER_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_endpoint)

[PEER_OBJECT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_object)

[Peer Collaboration API Structures](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-structures)