# PEER_PRESENCE_STATUS enumeration

## Description

The **PEER_PRESENCE_STATUS** enumeration defines the set of possible presence status settings available to a peer that participates in a peer collaboration network. These settings can be set by a peer collaboration network endpoint to indicate the peer's current level of participation to its watchers.

## Constants

### `PEER_PRESENCE_OFFLINE:0`

The user is offline.

### `PEER_PRESENCE_OUT_TO_LUNCH:1`

The user is currently "out to lunch" and unable to respond.

### `PEER_PRESENCE_AWAY:2`

The user is away and unable to respond.

### `PEER_PRESENCE_BE_RIGHT_BACK:3`

The user has stepped away from the application and will participate soon.

### `PEER_PRESENCE_IDLE:4`

The user is idling.

### `PEER_PRESENCE_BUSY:5`

The user is busy and does not wish to be disturbed.

### `PEER_PRESENCE_ON_THE_PHONE:6`

The user is currently on the phone and does not wish to be disturbed.

### `PEER_PRESENCE_ONLINE:7`

The user is actively participating in the peer collaboration network.

## See also

[Collaboration API Enumerations](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-enumerations)