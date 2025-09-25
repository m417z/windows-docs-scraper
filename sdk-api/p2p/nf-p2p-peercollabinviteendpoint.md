# PeerCollabInviteEndpoint function

## Description

The **PeerCollabInviteEndpoint** function sends an invitation to a specified peer endpoint to join the sender's peer collaboration activity. This call is synchronous and, if successful, obtains a response from the peer endpoint.

## Parameters

### `pcEndpoint` [in]

Pointer to a [PEER_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_endpoint) structure that contains information about the invited peer. This peer is sent an invitation when this API is called.

This parameter must not be set to **NULL**.

### `pcInvitation` [in]

Pointer to a [PEER_INVITATION](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_invitation) structure that contains the invitation request to send to the endpoint specified in *pcEndpoint*. This parameter must not be set to **NULL**.

### `ppResponse` [out]

Pointer to a [PEER_INVITATION_RESPONSE](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_invitation_response) structure that receives an invited peer endpoint's responses to the invitation request.

If this call fails with an error, on output this parameter will be **NULL**.

Free the memory associated with this structure by pass it to [PeerFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerfreedata).

## Return value

Returns S_OK if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory to support this operation. |
| **E_INVALIDARG** | One of the arguments is invalid. |
| **PEER_E_TIMEOUT** | The recipient of the invitation has not responded within 5 minutes. |

## Remarks

This API sends an invitation to the endpoint specified as input. It does not guarantee that the recipient of the invite is the specific contact that the user intended to send the invite to. To ensure that the invitation is sent to the correct contact, call [PeerCollabInviteContact](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabinvitecontact).

A toast will appear for the recipient of the invitation. This toast will be converted to a dialog box in which the user can accept or decline the invitation. When the invitation is successfully accepted, the collaborative application is launched on the recipient's machine.

To successfully receive the invitation, the application must be registered on the recipient's machine using [PeerCollabRegisterApplication](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabregisterapplication). It is also possible for the sender of the invite to have failure codes returned because the recipient has turned off application invites.

The recipient of the invitation must respond within 5 minutes to avoid timeout.

## See also

[PEER_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_endpoint)

[PEER_INVITATION](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_invitation)

[PEER_INVITATION_RESPONSE](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_invitation_response)

[Peer Collaboration API Functions](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-functions)

[PeerCollabGetAppLaunchInfo](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabgetapplaunchinfo)