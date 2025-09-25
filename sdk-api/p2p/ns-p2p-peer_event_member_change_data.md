# PEER_EVENT_MEMBER_CHANGE_DATA structure

## Description

The **PEER_EVENT_MEMBER_CHANGE_DATA** structure contains data that describes a change in the status of a peer group member.

## Members

### `dwSize`

Contains the size of this structure, in bytes.

### `changeType`

**PEER_MEMBER_CHANGE_TYPE** enumeration value that specifies the change event that occurred, such as a member joining or leaving.

### `pwzIdentity`

Pointer to a Unicode string that contains the peer name of the peer group member.

## See also

[PEER_GROUP_EVENT_DATA](https://learn.microsoft.com/windows/win32/api/p2p/ns-p2p-peer_group_event_data-r1)

[PEER_GROUP_EVENT_REGISTRATION](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_group_event_registration)

[PEER_MEMBER_CHANGE_TYPE](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_member_change_type)