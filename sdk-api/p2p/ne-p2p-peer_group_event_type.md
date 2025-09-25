# PEER_GROUP_EVENT_TYPE enumeration

## Description

The **PEER_GROUP_EVENT_TYPE** enumeration contains the specific peer event types that can occur within a peer group.

## Constants

### `PEER_GROUP_EVENT_STATUS_CHANGED:1`

The status of the group has changed. This peer event is fired when one of the flags listed in the [PEER_GROUP_STATUS](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_group_status) enumeration are set or changed for the group.

### `PEER_GROUP_EVENT_PROPERTY_CHANGED:2`

A member in the [PEER_GROUP_EVENT_DATA](https://learn.microsoft.com/windows/win32/api/p2p/ns-p2p-peer_group_event_data-r1) to retrieve.

### `PEER_GROUP_EVENT_RECORD_CHANGED:3`

A group record has changed. Information on this change is provided in the [PEER_GROUP_EVENT_DATA](https://learn.microsoft.com/windows/win32/api/p2p/ns-p2p-peer_group_event_data-r1).

### `PEER_GROUP_EVENT_DIRECT_CONNECTION:4`

The status of a direct connection has changed. Information on this change is provided in the [PEER_GROUP_EVENT_DATA](https://learn.microsoft.com/windows/win32/api/p2p/ns-p2p-peer_group_event_data-r1).

### `PEER_GROUP_EVENT_NEIGHBOR_CONNECTION:5`

The status of a neighbor connection has changed. Information on this change is provided in the [PEER_GROUP_EVENT_DATA](https://learn.microsoft.com/windows/win32/api/p2p/ns-p2p-peer_group_event_data-r1).

### `PEER_GROUP_EVENT_INCOMING_DATA:6`

Incoming direct connection data from a member is detected. Information on this peer event is provided in the [PEER_GROUP_EVENT_DATA](https://learn.microsoft.com/windows/win32/api/p2p/ns-p2p-peer_group_event_data-r1).

### `PEER_GROUP_EVENT_MEMBER_CHANGED:8`

The status of a member has changed. Information on this change is provided in the [PEER_GROUP_EVENT_DATA](https://learn.microsoft.com/windows/win32/api/p2p/ns-p2p-peer_group_event_data-r1).

### `PEER_GROUP_EVENT_CONNECTION_FAILED:10`

The connection to the peer group has failed. No data is provided when this peer event is raised. This event is also raised if no members are online in a group you are attempting to connect to for the first time.

### `PEER_GROUP_EVENT_AUTHENTICATION_FAILED:11`

## See also

[PEER_GROUP_EVENT_DATA](https://learn.microsoft.com/windows/win32/api/p2p/ns-p2p-peer_group_event_data-r1)

[PEER_GROUP_EVENT_REGISTRATION](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_group_event_registration)