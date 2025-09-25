# PeerCollabGetEventData function

## Description

The **PeerCollabGetEventData** function obtains the data associated with a peer collaboration event raised on the peer.

## Parameters

### `hPeerEvent` [in]

The peer collaboration network event handle obtained by a call to [PeerCollabRegisterEvent](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabregisterevent).

### `ppEventData` [out]

Pointer to a list of [PEER_COLLAB_EVENT_DATA](https://learn.microsoft.com/windows/win32/api/p2p/ns-p2p-peer_collab_event_data-r1) structures that contain data about the peer collaboration network event. These data structures must be freed after use by calling [PeerFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerfreedata).

## Return value

Returns S_OK if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory to support this operation. |
| **E_INVALIDARG** | One of the arguments is invalid. |
| **PEER_S_NO_EVENT_DATA** | The event data is not present. |

## See also

[Peer Collaboration API Functions](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-functions)