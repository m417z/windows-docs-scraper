# PeerCollabEnumPeopleNearMe function

## Description

The **PeerCollabEnumPeopleNearMe** function returns a handle to an enumerated set that contains all of the peer collaboration network "people near me" endpoints currently available on the subnet of the calling peer.

## Parameters

### `phPeerEnum` [out]

Pointer to a handle of an enumerated set that contains all of the peer collaboration network "people near me" endpoints currently available on the subnet of the calling peer.

## Return value

Returns S_OK if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory to support this operation. |
| **E_INVALIDARG** | One of the arguments is invalid. |
| **PEER_E_NOT_INITIALIZED** | The Windows Peer infrastructure is not initialized. Calling the relevant initialization function is required. |
| **PEER_E_NOT_SIGNED_IN** | The operation requires the user to be signed in. |

## Remarks

To obtain the individual peer "people near me" contacts, pass the returned handle to [PeerGetNextItem](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergetnextitem). An array of pointers to the [PEER_PEOPLE_NEAR_ME](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_people_near_me) structures are returned. To close the enumeration and release the resources associated with it, pass this handle to [PeerEndEnumeration](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerendenumeration). Individual items returned by the enumeration must be released with [PeerFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerfreedata).

## See also

[PEER_PEOPLE_NEAR_ME](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_people_near_me)

[Peer Collaboration API Functions](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-functions)

[PeerCollabSignin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabsignin)