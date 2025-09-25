# PeerCollabSetPresenceInfo function

## Description

The **PeerCollabSetPresenceInfo** function updates the caller's presence information to any contacts watching it.

## Parameters

### `pcPresenceInfo` [in]

Pointer to a [PEER_PRESENCE_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_presence_info) structure that contains the new presence information to publish for the calling peer application.

## Return value

Returns S_OK if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory to support this operation. |
| **E_INVALIDARG** | One of the arguments is invalid. |
| **PEER_E_NOT_INITIALIZED** | The Windows Peer infrastructure is not initialized. Calling the relevant initialization function is required. |
| **PEER_E_NOT_SIGNED_IN** | The operation requires the user to be signed in. |

## Remarks

Contacts watching this peer's presence will have a PEER_EVENT_PRESENCE_CHANGED event raised locally that signals this peer's change in presence status. A peer's presence status cannot be set to offline while signed-in. By default, a peer's presence status is 'online' and the descriptive text is **NULL** when signing in.

Any descriptive text for presence status is limited to 255 Unicode characters.

## See also

[Peer Collaboration API Functions](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-functions)