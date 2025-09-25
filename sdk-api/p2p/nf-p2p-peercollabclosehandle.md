# PeerCollabCloseHandle function

## Description

The **PeerCollabCloseHandle** function closes the handle to a Peer Collaboration activity invitation.

## Parameters

### `hInvitation` [in]

Handle obtained by a previous call to [PeerCollabAsyncInviteContact](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabasyncinvitecontact) or [PeerCollabAsyncInviteEndpoint](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabasyncinviteendpoint).

## Return value

Returns S_OK if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory to support this operation. |
| **E_HANDLE** | The handle specified is invalid. |

## Remarks

You must call this API after the handle has been signaled for an event and any data associated with the event has been obtained.

## See also

[Peer Collaboration API Functions](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-functions)

[PeerCollabAsyncInviteContact](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabasyncinvitecontact)

[PeerCollabAsyncInviteEndpoint](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabasyncinviteendpoint)