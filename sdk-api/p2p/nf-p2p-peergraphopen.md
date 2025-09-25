# PeerGraphOpen function

## Description

The **PeerGraphOpen** function opens a peer graph that is created previously by either the local node or a remote node. A handle to the peer graph is returned, but a network connection is not established.

## Parameters

### `pwzGraphId` [in]

Specifies the ID of the peer graph to open. This identifier must be the same as the ID used in the call to [PeerGraphCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphcreate).

**Note** A peer who specifies an invalid (long) graph ID can open and connect successfully to a graph, but the peer cannot publish records to the graph, because the records cannot be validated.

### `pwzPeerId` [in]

Specifies the unique ID of the peer opening the graph.

**Note** A peer who specifies an invalid (long) graph ID can open and connect successfully to a graph, but the peer cannot publish records to the graph, because the records cannot be validated.

### `pwzDatabaseName` [in]

Specifies the name of the database that is associated with this peer graph at the time the graph was created or opened for the first time.

### `pSecurityInterface` [in]

Specifies the security provider for a peer graph. This parameter must specify the same value as the *pSecurityInterface* specified in the original call to [PeerGraphCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphcreate).

### `cRecordTypeSyncPrecedence` [in]

Specifies the number of record types in the *pRecordTypeSyncPrecedence* parameter.

### `pRecordTypeSyncPrecedence` [in]

Points to an array of record types. This array specifies the order in which records of the specified record types are synchronized. The order can be zero (0) to N, where 0 is the first record type to be synchronized. If a record type is not specified in the array, it is synchronized in the default order after the types specified in the array are synchronized.

Specify **NULL** to use the default order. This parameter must be **NULL** if *cRecordTypeSyncPrecedence* is zero (0).

### `phGraph` [out]

Receives a handle to the peer graph that is opened. When this handle is not required or needed, free it by calling [PeerGraphClose](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphclose).

## Return value

Returns S_OK if an existing database was successfully opened. Otherwise, the function returns one of the following values:

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform the specified operation. |
| **PEER_S_GRAPH_DATA_CREATED** | An existing database is not found, and a new one is created successfully. If an existing database is found and opened successfully, **S_OK** is returned. |
| **PEER_E_INVALID_GRAPH** | The handle to the peer graph is invalid. |
| **PEER_E_NOT_INITIALIZED** | The peer graph must be initialized by using a call to [PeerGraphStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphstartup) before using this function. |

## Remarks

If you have developed your own SSP, your application must not call the PeerGraphing API to access data in the graphing database, because that can lead to a deadlock situation. Instead, the application should look at a cached copy of the information.

After **PeerGraphOpen** is called, an application can subscribe to events or import a database, or both.

Until a peer graph is synchronized at least one time, many functions are not available (for example, [PeerGraphListen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphlisten) or any of the record management functions), and any calls made to these functions fail. A peer graph is synchronized at least one time when one of the following occurs:

* A call to **PeerGraphOpen** returns **S_OK**, which means that an already synchronized database has been found.
* The [PeerGraphCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphcreate) function has been called.
* The **PEER_GRAPH_EVENT_STATUS_CHANGED** event has been triggered, and the PEER_GRAPH_STATUS_SYNCHRONIZED flag of the **dwStatus** member has been set.

## See also

[PEER_SECURITY_INTERFACE](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_security_interface)

[PeerGraphClose](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphclose)

[PeerGraphCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphcreate)

[PeerGraphListen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphlisten)