# PEER_COLLAB_EVENT_DATA structure

## Description

The **PEER_COLLAB_EVENT_DATA** union contains variant data for each possible peer collaboration network event raised on a peer.

## Members

### `eventType`

[PEER_COLLAB_EVENT_TYPE](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_collab_event_type) enumeration value that contains the type of the event whose corresponding data structure appears in the subsequent union arm.

### `__unnamed_union_03e8_5`

### `watchListChangedData`

A [PEER_EVENT_WATCHLIST_CHANGED_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_event_watchlist_changed_data) structure. This data structure is present when **eventType** is set to PEER_EVENT_WATCHLIST_CHANGED.

### `presenceChangedData`

A [PEER_EVENT_PRESENCE_CHANGED_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_event_presence_changed_data) structure. This data structure is present when **eventType** is set to PEER_EVENT_ENDPOINT_PRESENCE_CHANGED or PEER_EVENT_MY_PRESENCE_CHANGED.

### `applicationChangedData`

A [PEER_EVENT_APPLICATION_CHANGED_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_event_application_changed_data) structure. This data structure is present when **eventType** is set to PEER_EVENT_ENDPOINT_APPLICATION_CHANGED or PEER_EVENT_MY_APPLICATION_CHANGED.

### `objectChangedData`

A [PEER_EVENT_OBJECT_CHANGED_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_event_object_changed_data) structure. This data structure is present when **eventType** is set to PEER_EVENT_ENDPOINT_OBJECT_CHANGED or PEER_EVENT_MY_OBJECT_CHANGED.

### `endpointChangedData`

A [PEER_EVENT_ENDPOINT_CHANGED_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_event_endpoint_changed_data) structure. This data structure is present when **eventType** is set to PEER_EVENT_ENDPOINT_CHANGED or PEER_EVENT_MY_ENDPOINT_CHANGED.

### `peopleNearMeChangedData`

A [PEER_EVENT_PEOPLE_NEAR_ME_CHANGED_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_event_people_near_me_changed_data) structure. This data structure is present when **eventType** is set to PEER_EVENT_PEOPLE_NEAR_ME_CHANGED.

### `requestStatusChangedData`

A [PEER_EVENT_REQUEST_STATUS_CHANGED_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_event_request_status_changed_data) structure. This data structure is present when **eventType** is set to PEER_EVENT_REQUEST_STATUS_CHANGED.

## Remarks

## See also

[Peer Collaboration API Structures](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-structures)