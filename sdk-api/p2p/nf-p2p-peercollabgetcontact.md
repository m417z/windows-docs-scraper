# PeerCollabGetContact function

## Description

The **PeerCollabGetContact** function obtains the information for a peer contact given the peer name of the contact.

## Parameters

### `pwzPeerName` [in, optional]

Pointer to zero-terminated Unicode string that contains the name of the peer contact for which to obtain information.

If this parameter is **NULL**, the 'Me' contact information for the calling peer is returned.

### `ppContact` [out, optional]

Pointer to a pointer to a [PEER_CONTACT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_contact) structure. It receives the address of a PEER_CONTACT structure containing peer contact information for the peer name supplied in *pwzPeerName*. When this parameter is **NULL**, this function returns E_INVALIDARG.

Call [PeerFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerfreedata) on the address of the [PEER_CONTACT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_contact) structure to free this data.

## Return value

Returns S_OK if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory to support this operation. |
| **E_INVALIDARG** | One of the arguments is invalid. |
| **PEER_E_NOT_INITIALIZED** | The Windows Peer infrastructure is not initialized. Calling the relevant initialization function is required. |

## See also

[PEER_CONTACT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_contact)

[Peer Collaboration API Functions](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-functions)