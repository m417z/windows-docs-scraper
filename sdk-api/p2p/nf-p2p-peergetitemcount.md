# PeerGetItemCount function

## Description

The **PeerGetItemCount** function returns a count of the items in a peer enumeration.

## Parameters

### `hPeerEnum` [in]

Handle to the peer enumeration on which a count is performed. A peer enumeration function generates this handle.

### `pCount` [out]

Returns the total number of items in a peer enumeration.

## Return value

Returns **S_OK** if the operation succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform the specified operation. |

## See also

[PeerEndEnumeration](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerendenumeration)

[PeerEnumGroups](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerenumgroups)

[PeerEnumIdentities](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerenumidentities)

[PeerGetNextItem](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergetnextitem)

[PeerGroupEnumConnections](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupenumconnections)

[PeerGroupEnumMembers](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupenummembers)

[PeerGroupEnumRecords](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupenumrecords)