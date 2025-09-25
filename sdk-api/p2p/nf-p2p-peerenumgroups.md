# PeerEnumGroups function

## Description

The **PeerEnumGroups** function creates and returns a peer enumeration handle used to enumerate all the peer groups associated with a specific peer identity.

## Parameters

### `pwzIdentity` [in]

Specifies the peer identity to enumerate groups for.

### `phPeerEnum` [out]

 Receives a handle to the peer enumeration that contains the list of peer groups that the specified identity is a member of, with each item represented as a pointer to a [PEER_NAME_PAIR](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_name_pair) structure. Pass this handle to [PeerGetNextItem](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergetnextitem) to retrieve the items; when finished, call [PeerEndEnumeration](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerendenumeration) release the memory.

## Return value

If the function call succeeds, the return value is S_OK. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform the specified operation. |
| **PEER_E_NOT_FOUND** | The specified peer identity cannot be found. |

## Remarks

Once the application has obtained the enumeration handle, use [PeerGetNextItem](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergetnextitem) and [PeerGetItemCount](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergetitemcount) to enumerate the peer groups.

When enumerating peer groups, [PeerGetNextItem](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergetnextitem) returns an array of pointers to [PEER_NAME_PAIR](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_name_pair) structures.

Call [PeerEndEnumeration](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerendenumeration) to free the peer enumeration handle when it is no longer required.

## See also

[PEER_NAME_PAIR](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_name_pair)

[PeerEndEnumeration](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerendenumeration)

[PeerGetItemCount](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergetitemcount)

[PeerGetNextItem](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergetnextitem)