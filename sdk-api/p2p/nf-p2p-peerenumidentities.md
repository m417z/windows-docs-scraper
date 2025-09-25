# PeerEnumIdentities function

## Description

The **PeerEnumIdentities** function creates and returns a peer enumeration handle used to enumerate all the peer identities that belong to a specific user.

## Parameters

### `phPeerEnum` [out]

 Receives a handle to the peer enumeration that contains the list of peer identities, with each item represented as a pointer to a [PEER_NAME_PAIR](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_name_pair) structure. Pass this handle to [PeerGetNextItem](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergetnextitem) to retrieve the items; when finished, call [PeerEndEnumeration](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerendenumeration) to release the memory.

## Return value

If the function call succeeds, the return value is S_OK. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform the specified operation. |

## Remarks

Once the application has obtained the peer enumeration handle, use [PeerGetNextItem](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergetnextitem) and [PeerGetItemCount](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergetitemcount) to enumerate the peer identities.

When enumerating peer identities, [PeerGetNextItem](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergetnextitem) returns an array of pointers to [PEER_NAME_PAIR](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_name_pair) structures.

Call [PeerEndEnumeration](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerendenumeration) to free the enumeration handle when it is no longer required.

## See also

[PEER_NAME_PAIR](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_name_pair)

[PeerEndEnumeration](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerendenumeration)

[PeerGetItemCount](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergetitemcount)

[PeerGetNextItem](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergetnextitem)