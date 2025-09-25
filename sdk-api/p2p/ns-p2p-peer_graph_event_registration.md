# PEER_GRAPH_EVENT_REGISTRATION structure

## Description

The **PEER_GRAPH_EVENT_REGISTRATION** structure is used during registration for peer event notification. During registration it specifies which peer events an application requires notifications for.

## Members

### `eventType`

Specifies the type of peer event the application requires notifications for. The per events that can be registered for are specified by the [PEER_GRAPH_EVENT_TYPE](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_graph_event_type) enumeration.

### `pType`

If the peer event specified by **eventType** relates to records, use this member to specify which types of records the application requires notifications for. Specify **NULL** to receive notifications for all record types. This member is ignored if the event specified by **eventType** does not relate to records.

## See also

[PEER_GRAPH_EVENT_TYPE](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_graph_event_type)

[PeerGraphRegisterEvent](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphregisterevent)