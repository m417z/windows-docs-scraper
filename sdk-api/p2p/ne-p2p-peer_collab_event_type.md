# PEER_COLLAB_EVENT_TYPE enumeration

## Description

The **PEER_COLLAB_EVENT_TYPE** enumeration defines the set of events that can be raised on a peer by the peer collaboration network event infrastructure.

## Constants

### `PEER_EVENT_WATCHLIST_CHANGED:1`

The peer's list of watched contacts has changed.

### `PEER_EVENT_ENDPOINT_CHANGED:2`

The endpoint has changed.

### `PEER_EVENT_ENDPOINT_PRESENCE_CHANGED:3`

The presence status of an endpoint has changed.

### `PEER_EVENT_ENDPOINT_APPLICATION_CHANGED:4`

The registered application of the endpoint has changed.

### `PEER_EVENT_ENDPOINT_OBJECT_CHANGED:5`

A peer object registered to the endpoint has changed.

### `PEER_EVENT_MY_ENDPOINT_CHANGED:6`

The local peer's endpoint has changed.

### `PEER_EVENT_MY_PRESENCE_CHANGED:7`

The local peer's presence status has changed.

### `PEER_EVENT_MY_APPLICATION_CHANGED:8`

The local peer's registered application has changed.

### `PEER_EVENT_MY_OBJECT_CHANGED:9`

A peer object registered with the local peer has changed.

### `PEER_EVENT_PEOPLE_NEAR_ME_CHANGED:10`

An endpoint in the same subnet as the local peer's endpoint has changed.

### `PEER_EVENT_REQUEST_STATUS_CHANGED:11`

The status of a request to refresh endpoint data or subscribe to endpoint data has changed.

## See also

[Collaboration API Enumerations](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-enumerations)