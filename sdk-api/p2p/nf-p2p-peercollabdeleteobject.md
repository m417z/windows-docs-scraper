# PeerCollabDeleteObject function

## Description

The **PeerCollabDeleteObject** function deletes a peer object from the calling endpoint.

## Parameters

### `pObjectId` [in]

Pointer to a GUID value that uniquely identifies the peer object to delete from the calling endpoint.

## Return value

Returns S_OK if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory to support this operation. |
| **E_INVALIDARG** | One of the arguments is invalid. |
| **PEER_E_NOT_INITIALIZED** | The Windows Peer infrastructure is not initialized. Calling the relevant initialization function is required. |
| **PEER_E_NOT_SIGNED_IN** | The operation requires the user to be signed in. |

## Remarks

Peer objects are run-time data items associated with a particular application, such as a picture, an avatar, a certificate, or a specific description. Each peer object must be smaller than 3216K in size.

Trusted contacts watching this peer object and the subscriber of the "Me" contact will have a PEER_EVENT_OBJECT_CHANGED event raised, signaling this peer object's change in status. PEER_EVENT_MY_OBJECT_CHANGED will be raised locally.

Pre-defined objects, like Picture objects, cannot be deleted by calling this API.

## See also

[Peer Collaboration API Functions](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-functions)