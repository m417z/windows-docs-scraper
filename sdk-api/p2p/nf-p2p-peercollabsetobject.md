# PeerCollabSetObject function

## Description

The **PeerCollabSetObject** function creates or updates a peer data object used in a peer collaboration network.

## Parameters

### `pcObject` [in]

Pointer to a [PEER_OBJECT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_object) structure that contains the peer object on the peer collaboration network.

## Return value

Returns S_OK if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory to support this operation. |
| **E_INVALIDARG** | One of the arguments is invalid. |
| **PEER_E_NOT_INITIALIZED** | The Windows Peer infrastructure is not initialized. Calling the relevant initialization function is required. |
| **PEER_E_NOT_SIGNED_IN** | The operation requires the user to be signed in. |

## Remarks

Peer objects are run-time data items associated with a particular application, such as a picture, an avatar, a certificate, or a specific description. Each peer object must be smaller than 16K in size and cannot be 0.

If an object is already published, **PeerCollabSetObject** will update the existing object data.
The last application that updates the object will take ownership of the object. As a result, if the application is terminated the object is deleted.

If an object's 'published' status is removed due to sign-out rather than the closure of the associated application, the application is responsible for publishing the object the next time the user signs on.

Trusted contacts watching this peer object will have a **PEER_EVENT_OBJECT_CHANGED** event raised locally, signaling this peer object's change in status.

**PeerCollabSetObject** can be used to publish at most 128 objects.

There is one object with a given *GUID* published at any given time.

## See also

[PEER_OBJECT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_object)

[Peer Collaboration API Functions](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-functions)