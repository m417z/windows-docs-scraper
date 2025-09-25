# PEER_MEMBER_CHANGE_TYPE enumeration

## Description

The **PEER_MEMBER_CHANGE_TYPE** enumeration defines the set of possible peer group membership and presence states for a peer.

## Constants

### `PEER_MEMBER_CONNECTED:1`

A member is connected to a peer group.

### `PEER_MEMBER_DISCONNECTED:2`

A member is disconnected from a peer group.

### `PEER_MEMBER_UPDATED:3`

A member has updated information (for example, a new address) within a peer group.

### `PEER_MEMBER_JOINED:4`

New membership information is published for a group member. The peer name of a peer group member is obtained from the **pwzIdentity** field of the [PEER_EVENT_MEMBER_CHANGE_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_event_member_change_data) structure. New membership information is published in one of the following three scenarios:

* An administrator calls [PeerGroupIssueCredentials](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupissuecredentials) with the PEER_GROUP_STORE_CREDENTIALS flag set.
* A user connects to a peer group for the first time, and the PEER_MEMBER_DATA_OPTIONAL flag is not set.
* A peer group member performs an operation (for example, issuing an invitation or credentials, or publishing a record), but membership information for the peer group member does not exist in the group.

### `PEER_MEMBER_LEFT:5`

This peer event does not exist in the Peer Grouping Infrastructure v1.0, and must not be used.

## See also

[PEER_EVENT_MEMBER_CHANGE_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_event_member_change_data)