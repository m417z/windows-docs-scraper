# PeerCollabInviteContact function

## Description

The **PeerCollabInviteContact** function sends an invitation to join a peer collaboration activity to a trusted contact. This call is synchronous and, if successful, obtains a response from the contact.

## Parameters

### `pcContact` [in]

Pointer to a [PEER_CONTACT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_contact) structure that contains the contact information associated with the invitee.

### `pcEndpoint` [in]

Pointer to a [PEER_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_endpoint) structure that contains information about the invited peer. This peer is sent an invitation when this API is called.

### `pcInvitation` [in]

Pointer to a [PEER_INVITATION](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_invitation) structure that contains the invitation request to send to the endpoint(s) specified in *pcEndpoint*. This parameter must not be set to **NULL**.

### `ppResponse` [out]

Pointer to a [PEER_INVITATION_RESPONSE](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_invitation_response) structure that receives an invited peer endpoint's responses to the invitation request.

If this call fails with an error, this parameter will be **NULL**.

Free the memory returned by calling [PeerFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerfreedata).

## Return value

Returns S_OK if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory to support this operation. |
| **E_INVALIDARG** | One of the arguments is invalid. |
| **PEER_E_TIMEOUT** | The recipient of the invitation has not responded within 5 minutes. |

## Remarks

This API ensures the peer that receives the invitation is the contact specified as input. The connection will fail if the specific contact is not present on the endpoint specified. The use of **PeerCollabInviteContact** is recommended in place of the less secure [PeerCollabInviteEndpoint](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabinviteendpoint).

A toast will appear for the recipient of the invitation. This toast will be converted to a dialog box in which the user can accept or decline the invitation. When the invitation is successfully accepted, the collaborative application is launched on the recipient's machine.

To successfully receive the invitation, the application must be registered on the recipient's machine using [PeerCollabRegisterApplication](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabregisterapplication). It is also possible for the sender of the invite to have failure codes returned because the recipient has turned off application invites.

If the recipient is accepting invitations only from trusted contacts, then the sender of the invite must be added to the contact store of the recipient machine. The sender must be added to the contact store before the invitation attempt. To add a contact to the contact store, call [PeerCollabAddContact](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabaddcontact).

The recipient of the invitation must respond within 5 minutes to avoid timeout.

## See also

[PEER_CONTACT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_contact)

[PEER_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_endpoint)

[PEER_INVITATION](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_invitation)

[PEER_INVITATION_RESPONSE](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_invitation_response)

[PeerCollabGetAppLaunchInfo](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabgetapplaunchinfo)