# PEER_GROUP_STATUS enumeration

## Description

The **PEER_GROUP_STATUS** flags indicate whether or not the peer group has connections present.

## Constants

### `PEER_GROUP_STATUS_LISTENING:0x0001`

The peer group is awaiting new connections.

### `PEER_GROUP_STATUS_HAS_CONNECTIONS:0x0002`

The peer group has at least one connection.

## See also

[PEER_GROUP_EVENT_DATA](https://learn.microsoft.com/windows/win32/api/p2p/ns-p2p-peer_group_event_data-r1)

[PeerGroupGetStatus](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupgetstatus)