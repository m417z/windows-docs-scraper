# PeerCollabEnumObjects function

## Description

The **PeerCollabEnumObjects** function returns the handle to an enumeration that contains the peer objects associated with a specific peer's endpoint.

## Parameters

### `pcEndpoint` [in]

Pointer to a [PEER_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_endpoint) structure that contains the endpoint information for a peer whose objects will be enumerated.

If this parameter is **NULL** the published objects of the local peer's contacts are returned.

### `pObjectId` [in, optional]

Pointer to a GUID value that uniquely identifies a peer object with the supplied peer. If this parameter is supplied, the only peer object returned is the one that matches this GUID.

### `phPeerEnum` [out]

Pointer to the handle for the enumerated set of peer objects that correspond to the GUID returned in *pObjectId*. Pass this handle to [PeerGetNextItem](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergetnextitem) to obtain each item in the enumerated set.

## Return value

Returns S_OK if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory to support this operation. |
| **E_INVALIDARG** | One of the arguments is invalid. |
| **PEER_E_NOT_INITIALIZED** | The Windows Peer infrastructure is not initialized. Calling the relevant initialization function is required. |
| **PEER_E_NOT_SIGNED_IN** | The operation requires the user to be signed in. |

## Remarks

Peer objects are run-time data items associated with a particular application, such as a picture, an avatar, a certificate, or a specific description. Each peer object must be smaller than 16K in size.

**PeerCollabEnumObjects** will return all of the objects published for the local peer. The objects can be published by more than one application.

To obtain the individual peer objects, pass the returned handle to [PeerGetNextItem](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergetnextitem). The peer objects are returned as an array of pointers to the [PEER_OBJECT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_object) structures. If the endpoint is not publishing any objects, an empty array will be returned. To close the enumeration and release the resources associated with it, pass this handle to [PeerEndEnumeration](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerendenumeration). Individual items returned by the enumeration must be released with [PeerFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerfreedata).

To obtain a peer object successfully:

* The endpoint must have been previously obtained by calling [PeerCollabEnumEndpoints](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabenumendpoints).
* The local peer must have subscribed to the endpoint by calling [PeerCollabSubscribeEndpointData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabsubscribeendpointdata).
* The endpoint data must be refreshed by calling [PeerCollabRefreshEndpointData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabrefreshendpointdata) successfully.

If the user is publishing a picture, the picture can be obtained by retrieving the corresponding object. The GUID for the picture object is PEER_COLLAB_OBJECTID_USER_PICTURE.

## See also

[PEER_CONTACT](https://learn.microsoft.com/windows/win32/api/p2p/ns-p2p-peer_contact)

[PEER_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_endpoint)

[PEER_OBJECT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_object)

[Peer Collaboration API Functions](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-functions)