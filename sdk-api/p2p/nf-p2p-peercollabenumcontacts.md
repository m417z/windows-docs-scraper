# PeerCollabEnumContacts function

## Description

The **PeerCollabEnumContacts** function returns a handle to an enumerated set that contains all of the peer collaboration network contacts currently available on the calling peer.

## Parameters

### `phPeerEnum` [out]

Handle to an enumerated set that contains all of the peer collaboration network contacts currently available on the calling peer, excluding the "Me" contact.

## Return value

Returns S_OK if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory to support this operation. |
| **E_INVALIDARG** | One of the arguments is invalid. |
| **PEER_E_NOT_INITIALIZED** | The Windows Peer infrastructure is not initialized. Calling the relevant initialization function is required. |

## Remarks

To obtain the individual peer contacts, pass the returned handle to [PEER_CONTACT](https://learn.microsoft.com/windows/win32/api/p2p/ns-p2p-peer_contact) structures will be returned. To close the enumeration and release the resources associated with it, pass this handle to [PeerEndEnumeration](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerendenumeration). Individual items returned by the enumeration must be released with [PeerFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerfreedata).

## See also

[Peer Collaboration API Functions](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-functions)