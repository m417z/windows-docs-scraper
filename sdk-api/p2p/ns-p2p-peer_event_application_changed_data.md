# PEER_EVENT_APPLICATION_CHANGED_DATA structure

## Description

The **PEER_EVENT_APPLICATION_CHANGED_DATA** structure contains information returned when a PEER_EVENT_ENDPOINT_APPLICATION_CHANGED or PEER_EVENT_MY_APPLICATION_CHANGED event is raised on a peer participating in a peer collaboration network.

## Members

### `pContact`

Pointer to a [PEER_CONTACT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_contact) structure that contains the peer contact information for a contact whose change in application raised the event.

### `pEndpoint`

Pointer to a [PEER_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_endpoint) structure that contains the peer endpoint information for a contact whose change in application information raised the event.

### `changeType`

[PEER_CHANGE_TYPE](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_change_type) enumeration value that specifies the type of application change that occurred.

### `pApplication`

Pointer to a [PEER_APPLICATION](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_application) structure that contains the changed application information.

## Remarks

"Application" is a set of software or software features available on the peer's endpoint. Commonly, this refers to software packages that support peer networking activities, like games or other collaborative applications.

A peer's application has a GUID representing a single specific application. When an application is registered for a peer, this GUID and the corresponding application can be made available to all trusted contacts of the peer, indicating the activities the peer can participate in. To deregister a peer's application, call [PeerCollabUnregisterApplication](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabunregisterapplication) with this GUID.

When a new application is registered locally using PeerCollabRegisterApplication or unregistered using PeerCollabUnregisterApplication all peers subscribed to the local peer's presence information receive the PEER_EVENT_ENDPOINT_APPLICATION_CHANGED event. Locally, applications receive the PEER_EVENT_MY_APPLICATION_CHANGED event.

The **current user** scope has priority over the **all user** scope. If the application is registered in both scopes, the event will be fired only if the **current user** scope is changed.

## See also

[PEER_APPLICATION](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_application)

[PEER_CHANGE_TYPE](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_change_type)

[PEER_CONTACT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_contact)

[PEER_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_endpoint)

[Peer Collaboration API Structures](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-structures)