# PeerCollabEnumEndpoints function

## Description

The **PeerCollabEnumEndpoints** function returns the handle to an enumeration that contains the endpoints associated with a specific peer contact.

## Parameters

### `pcContact` [in]

Pointer to a [PEER_CONTACT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_contact) structure that contains the contact information for a specific peer. This parameter must not be **NULL**.

### `phPeerEnum` [out]

Pointer to a handle for the enumerated set of endpoints that are associated with the supplied peer contact. Pass this handle to [PeerGetNextItem](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergetnextitem) to obtain each item in the enumerated set.

## Return value

Returns S_OK if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory to support this operation. |
| **E_INVALIDARG** | One of the arguments is invalid. |
| **PEER_E_NOT_INITIALIZED** | The Windows Peer infrastructure is not initialized. Calling the relevant initialization function is required. |
| **PEER_E_NOT_SIGNED_IN** | The operation requires the user to be signed in. |

## Remarks

It is recommended that a contact record is updated using [PeerCollabUpdateContact](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabupdatecontact) prior to calling **PeerCollabEnumEndpoints**. Failure to do so can result in a return of E_INVALIDARG.

Endpoints will be available only for contacts with *fWatch* set to **true**. Only endpoints that have the "Me" contact of the calling peer saved as a trusted contact and have *WatcherPermissions* set to **allow** will be available. A contact must also be signed-in to the internet. In the event the contact is not signed-in, the error **E_INVALIDARG** will be returned.

To obtain the individual peer endpoints, pass the returned handle to [PeerGetNextItem](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergetnextitem). An array of pointers to [PEER_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_endpoint) structures will be returned. If no endpoints are available, an empty array will be returned. To close the enumeration and release the resources associated with it, pass this handle to [PeerEndEnumeration](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerendenumeration). Individual items returned by the enumeration must be released with [PeerFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerfreedata).

The limit for connections to a single contact is 50.

## See also

[PEER_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_endpoint)

[Peer Collaboration API Functions](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-functions)