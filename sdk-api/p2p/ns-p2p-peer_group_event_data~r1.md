# PEER_GROUP_EVENT_DATA structure

## Description

The **PEER_GROUP_EVENT_DATA** structure contains information about a specific peer group event that has occurred.

## Members

### `eventType`

[PEER_GROUP_EVENT_TYPE](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_group_event_type) enumeration value that specifies the type of peer group event that occurred. The type of event dictates the subsequent structure chosen from the union; for example, if this value is set to PEER_GROUP_EVENT_INCOMING_DATA, the populated union member is **incomingData**.

### `__unnamed_union_03e8_3`

### `dwStatus`

Specifies the [PEER_GROUP_STATUS](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_group_status) flag values that indicate the new status of the peer group. This field is populated if a PEER_GROUP_EVENT_STATUS_CHANGED event is raised.

### `incomingData`

Specifies the [PEER_EVENT_INCOMING_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_event_incoming_data) structure that contains information on incoming data from a peer. This structure is populated if a PEER_GROUP_EVENT_INCOMING_DATA event is raised.

### `recordChangeData`

Specifies the [PEER_EVENT_RECORD_CHANGE_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_event_record_change_data) structure that contains data that describes a record change. This structure is populated if a PEER_GROUP_EVENT_RECORD_CHANGED event is raised.

### `connectionChangeData`

[PEER_EVENT_CONNECTION_CHANGE_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_event_connection_change_data) structure that contains information when a direct or neighbor connection has changed. This structure is populated if a PEER_GROUP_EVENT_DIRECT_CONNECTION or PEER_GROUP_EVENT_NEIGHBOR_CONNECTION event is raised.

### `memberChangeData`

[PEER_EVENT_MEMBER_CHANGE_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_event_member_change_data) structure that contains data when the status of a peer group member changes. This structure is populated if a PEER_GROUP_EVENT_MEMBER_CHANGED event is raised.

### `hrConnectionFailedReason`

**HRESULT** that indicates the type of connection failure that occurred. This value is populated if a PEER_GROUP_EVENT_CONNECTION_FAILED event is raised. This value is one of the following:

| Value | Meaning |
| --- | --- |
| **PEER_E_NO_MEMBERS_FOUND** | No available peers within the peer group were found to connect to. |
| **PEER_E_NO_MEMBER_CONNECTIONS** | No member connections were available. |
| **PEER_E_UNABLE_TO_LISTEN** | The peer was unable to receive connection data for an unspecified reason. |
| **PEER_E_NOT_AUTHORIZED** | An attempt has been made to perform an unauthorized operation. For example, attempting to join a group with an invalid password. |

## Remarks

## See also

[PEER_EVENT_CONNECTION_CHANGE_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_event_connection_change_data)

[PEER_EVENT_INCOMING_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_event_incoming_data)

[PEER_EVENT_MEMBER_CHANGE_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_event_member_change_data)

[PEER_EVENT_RECORD_CHANGE_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_event_record_change_data)

[PEER_GROUP_EVENT_TYPE](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_group_event_type)

[PEER_GROUP_STATUS](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_group_status)

[PeerGroupGetEventData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupgeteventdata)