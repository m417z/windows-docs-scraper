# PeerCollabGetEndpointName function

## Description

The **PeerCollabGetEndpointName** function retrieves the name of the current endpoint of the calling peer, as previously set by a call to [PeerCollabSetEndpointName](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabsetendpointname).

## Parameters

### `ppwzEndpointName` [out]

Pointer to a zero-terminated Unicode string name of the peer endpoint currently used by the calling application.

## Return value

Returns S_OK if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory to support this operation. |
| **E_INVALIDARG** | One of the arguments is invalid. |
| **PEER_E_NOT_INITIALIZED** | The Windows Peer infrastructure is not initialized. Calling the relevant initialization function is required. |
| **PEER_E_NOT_SIGNED_IN** | The operation requires the user to be signed in. |

## Remarks

The endpoint name is limited to 25 Unicode characters. To free this data call [PeerFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerfreedata).

## See also

[Peer Collaboration API Functions](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-functions)

[PeerCollabSetEndpointName](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabsetendpointname)