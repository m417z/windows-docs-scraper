# PEER_APP_LAUNCH_INFO structure

## Description

The **PEER_APP_LAUNCH_INFO** structure contains the peer application application launch information provided by a contact in a previous peer invite request.

## Members

### `pContact`

Pointer to a [PEER_CONTACT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_contact) structure that contains information about the contact that sent the request to the local peer to launch the application referenced by the application.

### `pEndpoint`

Pointer to a [PEER_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_endpoint) structure that contains information about the specific endpoint of the contact that sent the request to the local peer to launch the application referenced by the application

### `pInvitation`

Pointer to the [PEER_INVITATION](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_invitation) structure that contains the invitation to launch a specific peer application application on the local peer.

## See also

[PEER_CONTACT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_contact)

[PEER_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_endpoint)

[PEER_INVITATION](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_invitation)

[Peer Collaboration API Structures](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-structures)