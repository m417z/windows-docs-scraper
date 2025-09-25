# PeerCollabAddContact function

## Description

The **PeerCollabAddContact** function adds a contact to the contact list of a peer.

## Parameters

### `pwzContactData` [in]

Pointer to a zero-terminated Unicode string buffer that contains the contact data for the peer that is added to the contact list. This string buffer can either be obtained by passing the peer name of the endpoint to add as a contact to [PeerCollabQueryContactData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabquerycontactdata), or through an out-of-band mechanism.

To send its own contact data out-of-band, the peer can call [PeerCollabExportContact](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabexportcontact) with a **NULL** peer name. This function returns the contact data in XML format.

### `ppContact` [out, optional]

Pointer to a pointer to a [PEER_CONTACT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_contact) structure. This parameter receives the address of a **PEER_CONTACT** structure containing peer contact information for the contact supplied in *pwzContactData*. This parameter may be **NULL**.

Call [PeerFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerfreedata) on the address of the [PEER_CONTACT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_contact) structure to free this data.

## Return value

Returns S_OK if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory to support this operation. |
| **E_INVALIDARG** | One of the arguments is invalid. |

## See also

[PEER_CONTACT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_contact)

[Peer Collaboration API Functions](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-functions)

[PeerCollabExportContact](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabexportcontact)

[PeerCollabQueryContactData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabquerycontactdata)