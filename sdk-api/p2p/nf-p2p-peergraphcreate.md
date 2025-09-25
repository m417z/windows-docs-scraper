# PeerGraphCreate function

## Description

The **PeerGraphCreate** function creates a new peer graph. An application can specify information about a peer graph, and the type of security that a peer graph uses. A handle to a peer graph is returned, but a network connection is not established.

## Parameters

### `pGraphProperties` [in]

All of the properties of a peer graph in the [PEER_GRAPH_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_graph_properties) structure.

### `pwzDatabaseName` [in]

The name of a record database to associate with a peer graph when it is created. The record database name must be a valid file name. Do not include a path with the file name. For a complete list of rules regarding file names, see the Naming a File item in the list of [Graphing Reference_Links](https://learn.microsoft.com/windows/desktop/P2PSdk/graphing-reference-links).

### `pSecurityInterface` [in]

The information about a security provider for a peer graph in the [PEER_SECURITY_INTERFACE](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_security_interface) structure.

### `phGraph` [out]

Receives a handle to the peer graph that is created. When this handle is not required anymore, free it by calling [PeerGraphClose](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphclose).

## Return value

Returns **S_OK** if the operation succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform a specified operation. |
| **PEER_E_DUPLICATE_GRAPH** | A database with a specified peer graph ID that already exists. |
| **PEER_E_NOT_INITIALIZED** | The peer graph must be initialized with a call to [PeerGraphStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphstartup) before using this function. |

## Remarks

If you develop your own Security Service Provider (SSP), your application must not call the Peer Graphing API to access data in the peer graphing database, because that can cause a deadlock situation. Instead, the application must use a cached copy of the information. The cached copy is not created by the Peer Graphing API. The application must provide a mechanism for caching this data.

After **PeerGraphCreate** is called, the application can subscribe to events before it calls [PeerGraphListen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphlisten).

## See also

[PEER_GRAPH_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_graph_properties)

[PEER_SECURITY_INTERFACE](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_security_interface)

[PeerGraphClose](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphclose)

[PeerGraphConnect](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphconnect)

[PeerGraphListen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphlisten)

[PeerGraphOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphopen)