# PeerCollabEnumApplications function

## Description

The **PeerCollabEnumApplications** function returns the handle to an enumeration that contains the applications registered to a specific peer's endpoint(s).

## Parameters

### `pcEndpoint` [in, optional]

Pointer to a [PEER_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_endpoint) structure that contains the endpoint information for a peer whose applications will be enumerated.

If this parameter is set to **NULL**, the published application information for the local peer's endpoint is enumerated.

### `pApplicationId` [in, optional]

Pointer to the GUID value that uniquely identifies a particular application of the supplied peer. If this parameter is supplied, the only peer application returned is the one that matches this GUID.

### `phPeerEnum` [out]

Pointer to the handle for the enumerated set of registered applications that correspond to the GUID returned in *pObjectId*. Pass this handle to [PeerGetNextItem](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergetnextitem) to obtain each item in the enumerated set.

## Return value

Returns S_OK if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory to support this operation. |
| **E_INVALIDARG** | One of the arguments is invalid. |
| **PEER_E_NOT_INITIALIZED** | The Windows Peer infrastructure is not initialized. Calling the relevant initialization function is required. |

## Remarks

In order to enumerate the applications for the specified endpoint successfully, application data must be available on the endpoint. For application data to be available, one of the following must occur:

* The endpoint must have been previously obtained by calling [PeerCollabEnumEndpoints](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabenumendpoints).
* The local peer must have subscribed to the endpoint by calling [PeerCollabSubscribeEndpointData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabsubscribeendpointdata).
* The endpoint data must be refreshed by calling [PeerCollabRefreshEndpointData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabrefreshendpointdata) successfully.

To obtain the individual peer applications, pass the returned handle to [PeerGetNextItem](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergetnextitem). To close the enumeration and release the resources associated with it, pass this handle to [PeerEndEnumeration](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerendenumeration). Individual items returned by the enumeration must be released with [PeerFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerfreedata).

Peer application data items are returned as individual [PEER_APPLICATION](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_application) structures.

The **PeerCollabEnumApplications** function returns an empty array for endpoints on the subnet that are not trusted contacts.

## See also

[PEER_APPLICATION](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_application)

[PEER_CONTACT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_contact)

[PEER_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_endpoint)

[Peer Collaboration API Functions](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-functions)