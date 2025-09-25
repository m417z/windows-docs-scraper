# PEER_NAME_PAIR structure

## Description

The **PEER_NAME_PAIR** structure contains the results of a call to [PeerGetNextItem](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergetnextitem).

## Members

### `dwSize`

Specifies the size, in bytes, of this structure.

### `pwzPeerName`

Specifies the peer name of the peer identity or peer group.

### `pwzFriendlyName`

Specifies the friendly name of the peer identity or peer group.

## Remarks

This structure is used when enumerating peer identities and peer groups associated with a specific identity.

When enumerating peer identities, each **PEER_NAME_PAIR** structure contains a peer name and the friendly name of the identity.

When enumerating peer groups, each **PEER_NAME_PAIR** structure contains the peer name and friendly name of the corresponding peer group.

## See also

[PeerEnumGroups](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerenumgroups)

[PeerEnumIdentities](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerenumidentities)

[PeerGetNextItem](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergetnextitem)