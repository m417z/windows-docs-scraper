# PEER_PEOPLE_NEAR_ME structure

## Description

The **PEER_PEOPLE_NEAR_ME** structure contains information about a peer in the same logical or virtual subnet.

## Members

### `pwzNickName`

Zero-terminated Unicode string that contains the nickname of the contact.

### `endpoint`

[PEER_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_endpoint) structure that contains the IPv6 network address of the peer whose endpoint shares the same subnet.

### `id`

GUID value that contains the unique ID value for this peer. Since this value uniquely identifies a peer endpoint, the display name and even the associated IPv6 address can be changed with deleting the rest of the peer information.

## See also

[PEER_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_data)

[Peer Collaboration API Structures](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-structures)