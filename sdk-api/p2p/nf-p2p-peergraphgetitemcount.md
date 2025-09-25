# PeerGraphGetItemCount function

## Description

The **PeerGraphGetItemCount** function retrieves the number of items in an enumeration.

## Parameters

### `hPeerEnum` [in]

Handle to a peer graph.

### `pCount` [out]

Receives a pointer to the number of records in an enumeration.

## Return value

If the function call succeeds, the return value is **S_OK**. Otherwise, it returns the following value.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One parameter is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform a specified operation. |
| **PEER_E_NOT_INITIALIZED** | A peer graph must be initialized with a call to [PeerGraphStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphstartup) before using this function. |

## Remarks

Because some items can become invalid while an application is enumerating a set of items, the number of items returned from [PeerGraphGetNextItem](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphgetnextitem) can be less than the number of items returned in *pCount*. The value of *pCount* indicates the number of items in an enumeration when the handle is created. Due to the dynamic nature of the Peer Infrastructure, it is not guaranteed that the number of items retrieved by using **PeerGraphGetNextItem** is equal to *pCount*.

## See also

[PeerGraphEndEnumeration](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphendenumeration)

[PeerGraphGetNextItem](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphgetnextitem)