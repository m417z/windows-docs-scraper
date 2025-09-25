# PEER_OBJECT structure

## Description

The **PEER_OBJECT** structure contains application-specific run-time information that can be shared with trusted contacts within a peer collaboration network.

## Members

### `id`

GUID value under which the peer object is uniquely registered.

### `data`

[PEER_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_data) structure that contains information which describes the peer object.

### `dwPublicationScope`

[PEER_PUBLICATION_SCOPE](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_publication_scope) enumeration value that specifies the publication scope for this peer object.

## Remarks

Peer objects are run-time data items associated with a particular application, such as a picture or avatar, a certificate, or a specific description. Each peer object must be smaller than 16K in size.

Trusted contacts watching this peer object will have a PEER_EVENT_OBJECT_CHANGED event raised on them signaling this peer object's change in status.

Peer object information is contained in the **data** member of this structure and represented as a byte buffer with a maximum size of 16K.

The lifetime of a peer object is tied to the lifetime of the application that registered it.

## See also

[PEER_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_data)

[Peer Collaboration API Structures](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-structures)