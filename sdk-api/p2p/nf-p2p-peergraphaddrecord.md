# PeerGraphAddRecord function

## Description

The **PeerGraphAddRecord** function adds a new record to a peer graph. A record added with this function is sent to each node in a peer graph.

## Parameters

### `hGraph` [in]

Handle to a peer graph.

### `pRecord` [in]

Pointer to a record to add.

### `pRecordId` [out]

Specifies the record ID that uniquely identifies a record in a peer graph.

## Return value

If the function call succeeds, the return value is **S_OK**. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | Cannot access a peer graph. |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform a specified operation. |
| **PEER_E_GRAPH_NOT_READY** | A graph is not synchronized. Records cannot be added until the peer graph is synchronized. |
| **PEER_E_GRAPH_SHUTTING_DOWN** | [PeerGraphClose](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphclose) has been called. |
| **PEER_E_INVALID_ATTRIBUTES** | The specified attributes do not match the schema. |
| **PEER_E_INVALID_GRAPH** | The handle to a peer graph is invalid. |
| **PEER_E_MAX_RECORD_SIZE_EXCEEDED** | The record exceeds the maximum size allowed by a peer graph. |
| **PEER_E_NOT_INITIALIZED** | The graph must be initialized with a call to [PeerGraphStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphstartup)—before using this function. |

## Remarks

The following members of the [PEER_RECORD](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_record) structure must contain valid values:

* **dwSize**.
* **type**.
* **ftExpiration** - Must be later than the current graph time, and must be specified in peer time by using [PeerGraphUniversalTimeToPeerTime](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphuniversaltimetopeertime).

The following members of the **PEER_RECORD** structure are optional. Set them to **NULL** if they are not used by your application:

* **data**
* **pwzAttributes**
* **securityData**
* **dwVersion**

If any of the following members are **NULL**, the Peer Graphing API performs the specified default behavior:

* **pwzCreatorId** - Uses the peer ID passed to either [PeerGraphCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphcreate) or [PeerGraphOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphopen).
* **pwzModifiedById** - Uses the **pwzCreatorId**.

The following members cannot be specified; any value used is overwritten by the Peer Graphing infrastructure:

* **id**.
* **ftCreation** - Uses peer time.
* **ftLastModified** - Uses peer time.

## See also

[PEER_RECORD](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_record)

[PeerGraphDelete](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphdelete)

[PeerGraphGetEventData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphgeteventdata)

[PeerGraphUpdate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphopen)