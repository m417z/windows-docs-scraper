# PeerCollabAsyncInviteEndpoint function

## Description

The **PeerCollabAsyncInviteEndpoint** function sends an invitation to a specified peer endpoint to join the sender's peer collaboration activity. The availability of the response to the invitation is updated through an asynchronous event.

## Parameters

### `pcEndpoint` [in]

Pointer to a [PEER_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_endpoint) structure that contains information about the invited peer. This peer is sent an invitation when this API is called.

This parameter must not be set to **NULL**.

### `pcInvitation` [in]

Pointer to a [PEER_INVITATION](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_invitation) structure that contains the invitation request to send to the endpoint specified in *pcEndpoint*. E_INVALIDARG is returned if this parameter is set to **NULL**.

### `hEvent` [in, optional]

Handle to the event for this invitation, created by a previous call to CreateEvent. The event is signaled when the status of the asynchronous invitation is updated. To obtain the response data, call [PeerCollabGetInvitationResponse](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabgetinvitationresponse).

If the event is not provided, the caller must poll for the result by calling [PeerCollabGetInvitationResponse](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabgetinvitationresponse).

### `phInvitation` [out, optional]

A pointer to a handle to the sent invitation. If this parameter is **NULL**, the framework will cleanup the response information after the invitation response is received. If this parameter is not **NULL**, the handle must be closed by calling [PeerCollabCloseHandle](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabclosehandle).

## Return value

Returns S_OK if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory to support this operation. |
| **E_INVALIDARG** | One of the arguments is invalid. |

## Remarks

This API sends an invitation to the endpoint specified as input. It does not guarantee that the recipient of the invite is the specific contact that the user intended to send the invite to. To ensure that the invitation is sent to the correct contact use [PeerCollabAsyncInviteContact](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabasyncinvitecontact).

A toast will appear for the recipient of the invitation. This toast will be converted to a dialog box in which the user can accept or decline the invitation. When the invitation is successfully accepted, the collaborative application is launched on the recipient's machine.

To successfully receive the invitation, the application must be registered on the recipient's machine using [PeerCollabRegisterApplication](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabregisterapplication). It is also possible for the sender of the invite to have failure codes returned because the recipient has turned off application invites.

The [PeerCollabGetInvitiationResponse](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabgetinvitationresponse) function will return PEER_E_CONNECTION_FAILED if the endpoint to which the invitation is being sent is not accepting invitations.

If the recipient is accepting invitations only from trusted contacts, then the sender of the invite must be added to the contact store of the recipient machine. The sender must be added to the contact store before the invitation attempt. To add a contact to the contact store, call [PeerCollabAddContact](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabaddcontact).

## See also

[PEER_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_endpoint)

[PEER_INVITATION](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_invitation)

[Peer Collaboration API Functions](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-functions)

[PeerCollabCloseHandle](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabclosehandle)

[PeerCollabGetAppLaunchInfo](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabgetapplaunchinfo)

[PeerCollabGetInvitationResponse](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabgetinvitationresponse)