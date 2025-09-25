# PeerGraphDeleteRecord function

## Description

The **PeerGraphDeleteRecord** function marks a record as deleted within a peer graph. The record is not available on a local node to function calls, for example, calls to [PeerGraphGetRecord](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphgetrecord) and [PeerGraphEnumRecords](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphenumrecords).

## Parameters

### `hGraph` [in]

Handle to a peer graph.

### `pRecordId` [in]

Pointer to a record ID to delete.

### `fLocal` [in]

Specify **TRUE** to remove a record from only a local database without notifying the rest of a peer graph about the change. Specify FALSE to delete the record from an entire peer graph.

**Note** Specifying **TRUE** does not prevent a record from being added again during the next graph synchronization with a neighbor. Specifying **TRUE** is only effective if PEER_SECURITY_INTERFACE is specified in a call to [PeerGraphOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphopen) or [PeerGraphCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphcreate), and only if PEER_SECURITY_INTERFACE contains a [PFNPEER_VALIDATE_RECORD](https://learn.microsoft.com/windows/desktop/api/p2p/nc-p2p-pfnpeer_validate_record) function that returns PEER_E_INVALID_RECORD when validating the record.

## Return value

If the function call succeeds, the return value is **S_OK**. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | Cannot access a peer graph. |
| **PEER_E_GRAPH_NOT_READY** | The peer graph is not synchronized. Records cannot be deleted until the graph is synchronized. |
| **PEER_E_INVALID_GRAPH** | The handle to a peer graph is invalid. |
| **PEER_E_NOT_INITIALIZED** | The peer graph must be initialized with a call to [PeerGraphStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphstartup) before using this function. |
| **PEER_E_RECORD_NOT_FOUND** | The specified record cannot be found. |

## See also

[PeerGraphAddRecord](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphgetrecord)

[PeerGraphEnumRecords](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphenumrecords)

**PeerGraphGetRecord**

[PeerGraphUpdateRecord](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphupdaterecord)