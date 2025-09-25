# PEER_GROUP_EVENT_REGISTRATION structure

## Description

The **PEER_GROUP_EVENT_REGISTRATION** structure defines the particular peer group event a member can register for.

## Members

### `eventType`

[PEER_GROUP_EVENT_TYPE](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_group_event_type) that specifies the peer group event type to register for.

### `pType`

GUID value that identifies the type of record or data message that raises an event of the type specified by **eventType**. For example, if the peer wishes to be notified about all changes to a specific record type, the GUID that corresponds to this record type must be supplied in this field and PEER_GROUP_RECORD_CHANGED must be in **eventType**.

This member is only populated (not NULL) when **eventType** is either PEER_GROUP_EVENT_RECORD_CHANGED or PEER_GROUP_EVENT_INCOMING_DATA.

## See also

[PEER_GROUP_EVENT_TYPE](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_group_event_type)

[PeerGroupRegisterEvent](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupregisterevent)