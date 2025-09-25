# PeerCollabGetInvitationResponse function

## Description

The **PeerCollabGetInvitationResponse** function obtains the response from a peer previously invited to join a peer collaboration activity.

## Parameters

### `hInvitation` [in]

Handle to an invitation to join a peer collaboration activity.

### `ppInvitationResponse` [out]

Pointer to the address of a [PEER_INVITATION_RESPONSE](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_invitation_response) structure that contains an invited peer's response to a previously transmitted invitation request.

Free the memory associated with this structure by calling [PeerFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerfreedata).

## Return value

Returns S_OK if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The provided handle is invalid. |
| **E_OUTOFMEMORY** | There is not enough memory to support this operation. |
| **PEER_E_NOT_FOUND** | The invitation recipient could not be found. |
| **PEER_E_INVITE_CANCELED** | The invitation was previously canceled. |
| **PEER_E_INVITE_RESPONSE_NOT_AVAILABLE** | The response to the peer invitation is not available. |
| **PEER_E_CONNECTION_FAILED** | A connection to the graph or group has failed, or a direct connection in a graph or group has failed. |

## Remarks

This function must be called after [PeerCollabAsyncInviteContact](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabasyncinvitecontact) or [PeerCollabAsyncInviteEndpoint](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabasyncinviteendpoint) is called and the event handle provided to [PeerCollabRegisterEvent](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabregisterevent) is signaled on the peer that sent the invitation.

## See also

[PEER_INVITATION_RESPONSE](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_invitation_response)

[Peer Collaboration API Functions](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-functions)

[PeerCollabAsyncInviteContact](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabasyncinvitecontact)

[PeerCollabAsyncInviteEndpoint](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabasyncinviteendpoint)