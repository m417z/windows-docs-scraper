# PeerCollabUnregisterEvent function

## Description

The **PeerCollabUnregisterEvent** function deregisters an application from notification about specific peer collaboration events.

## Parameters

### `hPeerEvent` [in]

Handle to the peer collaboration event the peer application will deregister. This handle is obtained with a previous call to [PeerCollabRegisterEvent](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabregisterevent).

## Return value

Returns S_OK if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory to support this operation. |
| **E_INVALIDARG** | One of the arguments is invalid. |

## See also

[Peer Collaboration API Functions](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-functions)