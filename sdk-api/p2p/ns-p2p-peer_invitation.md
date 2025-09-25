# PEER_INVITATION structure

## Description

The **PEER_INVITATION** structure contains a request to initiate or join a peer collaboration activity.

## Members

### `applicationId`

GUID value that uniquely identifies the registered software or software component for the peer collaboration activity.

### `applicationData`

[PEER_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_data) structure that contains opaque data describing possible additional application-specific settings (for example, an address and port on which the activity will occur, or a specific video codec to use). This data is limited to 16K.

### `pwzMessage`

Zero-terminated Unicode string that contains a specific request message to the invitation recipient. The message is limited to 255 unicode characters.

## Remarks

An invitation request is typically sent by a peer after a contact appears online within the peer collaboration network and a call to [PeerCollabEnumApplications](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabenumapplications) returns a common software application (represented as a application GUID) available on the contact's endpoint.

## See also

[PEER_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_data)

[Peer Collaboration API Structures](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-structures)