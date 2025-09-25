# PEER_GROUP_PROPERTY_FLAGS enumeration

## Description

The **PEER_GROUP_PROPERTY_FLAGS** flags are used to specify various peer group membership settings.

## Constants

### `PEER_MEMBER_DATA_OPTIONAL:0x0001`

A peer's member data ([PEER_MEMBER](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_member)) is only published when an action if performed, such as publishing a record or issuing a GMC. If the peer has not performed one of these actions, the membership data will not be available.

### `PEER_DISABLE_PRESENCE:0x0002`

The peer presence system is prevented from automatically publishing presence information.

### `PEER_DEFER_EXPIRATION:0x0004`

Group records are not expired until the peer connects with a group.

## Remarks

These flags can only be set by the peer group creator.

## See also

[PEER_MEMBER](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_member)