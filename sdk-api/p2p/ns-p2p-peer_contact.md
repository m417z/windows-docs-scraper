# PEER_CONTACT structure

## Description

The **PEER_CONTACT** structure contains information about a specific contact.

## Members

### `pwzPeerName`

Zero-terminated Unicode string that contains the peer name of the contact. This is the unique identifier for a contact. There can only be a single contact associated with any given peername.

### `pwzNickName`

Zero-terminated Unicode string that contains the nickname of the contact and can be modified at any time. This is used when the peer collaboration scope is set to People Near Me. It is advertised in People Near Me and seen by recipients of sent invitations.

This member is limited to 255 unicode characters.

### `pwzDisplayName`

Zero-terminated Unicode string that contains the display name of the contact. This corresponds to the display name seen for the contact in a peer's contacts folder.

This member is limited to 255 unicode characters.

### `pwzEmailAddress`

Zero-terminated Unicode string that contains the email address of the contact.

### `fWatch`

If true, the contact is watched by the peer; if false, it is not.

### `WatcherPermissions`

[PEER_WATCH_PERMISSION](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_watch_permission) enumeration value that specifies the watch permissions for this contact.

### `credentials`

[PEER_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_data) structure that contains the security credentials for the contact in an opaque byte buffer.

## Remarks

"Contacts" are peers participating in a peer collaboration network who publish presence information available to the local peer. This associated information enables the peer application to "watch" them for updates and peer application or object status changes. Lists of contacts are maintained by the peer collaboration infrastructure, and specific status change events are raised for each individual contact in the list.

## See also

[PEER_WATCH_PERMISSION](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_watch_permission)

[Peer Collaboration API Structures](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-structures)