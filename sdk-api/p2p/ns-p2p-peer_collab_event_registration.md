# PEER_COLLAB_EVENT_REGISTRATION structure

## Description

The **PEER_COLLAB_EVENT_REGISTRATION** structure contains the data used by a peer to register for specific peer collaboration network events.

## Members

### `eventType`

[PEER_COLLAB_EVENT_TYPE](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_collab_event_type) enumeration value that specifies the type of peer collaboration network event for which to register.

### `pInstance`

GUID value that uniquely identifies the application or object that registers for the specific event.

This parameter is valid only for PEER_EVENT_ENDPOINT_APPLICATION_CHANGED, PEER_EVENT_ENDPOINT_OBJECT_CHANGED, PEER_EVENT_MY_APPLICATION_CHANGED, and PEER_EVENT_MY_OBJECT_CHANGED. This GUID represents the application ID for application-specific events, and the object ID for object-specific events.

When this member is set, notification will be sent only for the specific application or object.

### `pInstance.unique`

## See also

[PEER_COLLAB_EVENT_TYPE](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_collab_event_type)

[Peer Collaboration API Structures](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-structures)