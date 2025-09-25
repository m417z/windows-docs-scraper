# PeerCollabAsyncInviteContact function

## Description

The **PeerCollabAsyncInviteContact** function sends an invitation to a trusted peer contact to join the sender's peer collaboration activity over a secured connection. The availability of the invitation response is updated through an asynchronous event.

## Parameters

### `pcContact` [in, optional]

Pointer to a [PEER_CONTACT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_contact) structure that contains the contact information associated with the recipient of the invite. This parameter is optional.

To invite the endpoint of the calling peer specified in *pcEndpoint*, set the pointer value to **NULL**.

### `pcEndpoint` [in]

Pointer to a [PEER_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_endpoint) structure that contains information about the invited peer's endpoint. The endpoint must be associated with the peer contact specified in *pcContact*.

### `pcInvitation` [in]

Pointer to a [PEER_INVITATION](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_invitation) structure that contains the invitation request to send to the endpoint specified in *pcEndpoint*. E_INVALIDARG is returned if this parameter is set to **NULL**.

### `hEvent` [in, optional]

Handle to the event for this invitation, created by a previous call to CreateEvent. The event is signaled when the status of the asynchronous invitation is updated. To obtain the response data, call [PeerCollabGetInvitationResponse](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabgetinvitationresponse).

If the event is not provided the caller must poll for the result by calling [PeerCollabGetInvitationResponse](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabgetinvitationresponse).

### `phInvitation` [optional]

A pointer to a handle to the sent invitation. The framework will cleanup the response information after the invitation response is received if **NULL** is specified. When **NULL** is not the specified handle to the invitation provided, it must be closed by calling [PeerCollabCloseHandle](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabclosehandle).

## Return value

Returns S_OK if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory to support this operation. |
| **E_INVALIDARG** | One of the arguments is invalid. |
| **E_NOTIMPL** | *pcEndpoint* is **NULL**. |
| **PEER_E_NOT_INITIALIZED** | The Windows Peer infrastructure is not initialized. Calling the relevant initialization function is required. |

## Remarks

This API ensures the peer that receives the invitation is the contact specified as input. The connection will fail if the specific contact is not present on the endpoint specified. The use of **PeerCollabAsyncInviteContact** is recommended in place of the less secure [PeerCollabAsyncInviteEndpoint](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabasyncinviteendpoint).

A toast will appear for the recipient of the invitation. This toast will be converted to a dialog box in which the user can accept or decline the invitation. When the invitation is successfully accepted, the collaborative application is launched on the recipient's machine.

To successfully receive the invitation the application must be registered on the recipient's machine using [PeerCollabRegisterApplication](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabregisterapplication). It is also possible for the sender of the invite to have failure codes returned because the recipient has turned off application invites.

The [PeerCollabGetInvitiationResponse](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabgetinvitationresponse) function will return PEER_E_CONNECTION_FAILED if the contact to which the invitation is being sent is not accepting invitations.

If the recipient is accepting invitations only from trusted contacts, then the sender of the invite must be added to the contact store of the recipient machine. The sender must be added to the contact store before the invitation attempt. To add a contact to the contact store, call [PeerCollabAddContact](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabaddcontact).

To cancel an outstanding invitation, call [PeerCollabCancelInvitation](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabcancelinvitation).

## See also

[PEER_CONTACT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_contact)

[PEER_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_endpoint)

[PEER_INVITATION](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_invitation)

[Peer Collaboration API Functions](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-functions)

[PeerCollabAddContact](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabaddcontact)

[PeerCollabCancelInvitation](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabcancelinvitation)

[PeerCollabCloseHandle](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabclosehandle)

[PeerCollabGetAppLaunchInfo](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabgetapplaunchinfo)

[PeerCollabGetInvitationResponse](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabgetinvitationresponse)