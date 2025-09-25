# PeerCollabExportContact function

## Description

The **PeerCollabExportContact** function exports the contact data associated with a peer name to a string buffer. The buffer contains contact data in XML format.

The [PeerCollabAddContact](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabaddcontact) function allows this XML string to be utilized by other peers.

## Parameters

### `pwzPeerName` [in, optional]

Pointer to zero-terminated Unicode string that contains the name of the peer contact for which to export.

If this parameter is **NULL**, the "Me" contact information for the calling peer is exported.

### `ppwzContactData` [out, optional]

Pointer to a zero-terminated string buffer that contains peer contact XML data where the peer names match the string supplied in *pwzPeerName*.

The memory returned here can be freed by calling [PeerFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerfreedata).

## Return value

Returns S_OK if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory to support this operation. |
| **E_INVALIDARG** | One of the arguments is invalid. |
| **PEER_E_NOT_INITIALIZED** | The Windows Peer infrastructure is not initialized. Calling the relevant initialization function is required. |
| **PEER_E_NOT_SIGNED_IN** | One of the arguments is invalid. |

## See also

[Peer Collaboration API Functions](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-functions)