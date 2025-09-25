# PeerGraphSearchRecords function

## Description

The **PeerGraphSearchRecords** function searches the peer graph for specific records.

## Parameters

### `hGraph` [in]

Handle to the peer graph.

### `pwzCriteria` [in]

Pointer to an XML string that specifies the records to search for. For information on formulating an XML query string to search the peer graphing records, see [Record Search Query Format](https://learn.microsoft.com/windows/desktop/P2PSdk/record-search-query-format).

### `phPeerEnum` [out]

Handle to the enumeration.

## Return value

If the function call succeeds, the return value is S_OK. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform the specified operation. |
| **PEER_E_INVALID_GRAPH** | The handle to the peer graph is invalid. |
| **PEER_E_INVALID_SEARCH** | The specified query does not adhere to the search schema. See [Record Search Query Format](https://learn.microsoft.com/windows/desktop/P2PSdk/record-search-query-format) for further information. |
| **PEER_E_NOT_INITIALIZED** | The peer graph must be initialized with a call to [PeerGraphStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphstartup) before using this function. |

## Remarks

The [PeerGraphEnumRecords](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphenumrecords) function is more efficient than the **PeerGraphSearchRecords** function.

When [PeerGraphGetNextItem](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphgetnextitem) is called with the handle returned by **PeerGraphSearchRecords**, **PeerGraphGetNextItem** returns the data in the [PEER_RECORD](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_record) structure.

## See also

[PEER_RECORD](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_record)

[PeerGraphEndEnumeration](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphendenumeration)

[PeerGraphEnumRecords](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphenumrecords)

[PeerGraphGetItemCount](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphgetitemcount)

[PeerGraphGetNextItem](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphgetnextitem)