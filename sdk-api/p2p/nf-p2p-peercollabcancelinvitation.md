# PeerCollabCancelInvitation function

## Description

The **PeerCollabCancelInvitation** function cancels an invitation previously sent by the caller to a contact.

## Parameters

### `hInvitation` [in]

Handle to a previously sent invitation.

## Return value

Returns S_OK if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory to support this operation. |
| **E_INVALIDARG** | The provided handle is invalid. |
| **PEER_E_NOT_INITIALIZED** | The application did not make a previous call to [PeerCollabStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabstartup). |
| **E_HANDLE** | The handle specified is invalid. |

## Remarks

 When **PeerCollabCancelInvitation** is called, depending on the state of the invitation, it will perform one or more of the following actions:

* If the connection to the receiver is not yet established, it will cancel the connection creation process and the receiver will not see the invitation.
* If the invitation has been received, but not responded to, it will notify the recipient contact that the invitation has been canceled. As a result, the receiver will not be able to respond to the invitation.
* If the receiver has already responded to the invitation, the call performs a no-op.
  After canceling the invitation, you must call [PeerCollabCloseHandle](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabclosehandle).

## See also

[Peer Collaboration API Functions](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-functions)

[PeerCollabCloseHandle](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabclosehandle)