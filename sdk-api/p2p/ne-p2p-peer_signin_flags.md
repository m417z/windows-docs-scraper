# PEER_SIGNIN_FLAGS enumeration

## Description

The **PEER_SIGNIN_FLAGS** enumeration defines the set of peer presence publication behaviors available when the peer signs in to a peer collaboration network.

## Constants

### `PEER_SIGNIN_NONE:0x0`

A peer's presence is not being published in any scope.

### `PEER_SIGNIN_NEAR_ME:0x1`

The peer can publish availability information to endpoints in the same subnet or local area network, or query for other endpoints available on the subnet.

### `PEER_SIGNIN_INTERNET:0x2`

The peer can publish presence, applications, and objects to all contacts in a peer's contact list.

### `PEER_SIGNIN_ALL`

The peer can publish presence, applications, and objects to all contacts in a peer's contact list, or query for other endpoints available on the subnet.

## See also

[Collaboration API Enumerations](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-enumerations)