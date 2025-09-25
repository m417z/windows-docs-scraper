# PeerCollabParseContact function

## Description

The **PeerCollabParseContact** function parses a Unicode string buffer containing contact XML data into a [PEER_CONTACT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_contact) data structure.

## Parameters

### `pwzContactData` [in]

Pointer to zero-terminated Unicode string buffer that contains XML contact data as returned by functions like [PeerCollabQueryContactData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabquerycontactdata) or [PeerCollabExportContact](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabexportcontact).

### `ppContact` [out]

Pointer to the address of a [PEER_CONTACT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_contact) structure that contain the peer contact information parsed from *pwzContactData*. Free the memory allocated by calling [PeerFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerfreedata).

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