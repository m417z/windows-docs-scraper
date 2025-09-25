# PEER_PRESENCE_INFO structure

## Description

The **PEER_PRESENCE_INFO** structure contains specific peer presence information.

## Members

### `status`

[PEER_PRESENCE_STATUS](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_presence_status) enumeration value that indicates the current availability or level of participation by the peer in a peer collaboration network.

### `pwzDescriptiveText`

Zero-terminated Unicode string that contains a user- or application-defined message that expands upon the current status value. This string is limited to 255 characters.

## Remarks

Peer "presence" is information about a specific peer's level of participation in a peer collaboration network, such as whether or not the peer has logged into or out of the peer collaboration network, or has set a specific status (for example, "Busy, "Away").

## See also

[PEER_PRESENCE_STATUS](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_presence_status)

[Peer Collaboration API Structures](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-structures)