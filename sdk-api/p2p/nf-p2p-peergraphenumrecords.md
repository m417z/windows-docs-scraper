# PeerGraphEnumRecords function

## Description

The **PeerGraphEnumRecords** function creates and returns an enumeration handle used to enumerate records of a specific type of record, user, or both. An enumeration provides a snapshot of records at the time an enumeration is performed.

## Parameters

### `hGraph` [in]

Handle to a peer graph.

### `pRecordType` [in]

Pointer to the type of record to enumerate. Specify **NULL** to enumerate all record types.

### `pwzPeerId` [in]

Pointer to a string that identifies the creator that an application is requesting an enumeration for. Specify **NULL** to enumerate all records.

### `phPeerEnum` [out]

Receives a handle to an enumeration. Supply the handle to all calls to [PeerGraphGetNextItem](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphgetnextitem). When a handle is not needed, free it by calling [PeerGraphEndEnumeration](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphendenumeration).

## Return value

If the function call succeeds, the return value is **S_OK**. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One parameter is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform a specified operation. |
| **PEER_E_INVALID_GRAPH** | The handle to a peer graph is invalid. |
| **PEER_E_NOT_INITIALIZED** | A graph must be initialized with a call to [PeerGraphStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphstartup) before using this function. |

## Remarks

* If both the *pRecordType* and *pwzPeerId* parameters are **NULL**, all records are returned.

* For simple enumeration tasks, use the **PeerGraphEnumRecords** function, because it is more efficient than the [PeerGraphSearchRecords](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphsearchrecords) function. For complex enumeration and filtering tasks such as heuristic searches of the database, use the **PeerGraphSearchRecords** function.

* When [PeerGraphGetNextItem](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphgetnextitem) is called with the handle that **PeerGraphEnumRecords** returns, **PeerGraphGetNextItem** returns the data in the [PEER_RECORD](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_record) structure.

## See also

[PEER_RECORD](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_record)

[PeerGraphEndEnumeration](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphendenumeration)

[PeerGraphGetItemCount](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphgetitemcount)

[PeerGraphGetNextItem](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphgetnextitem)

[PeerGraphSearchRecords](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphsearchrecords)