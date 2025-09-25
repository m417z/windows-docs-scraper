# PeerGraphImportDatabase function

## Description

The **PeerGraphImportDatabase** function imports a file that contains the information from a peer graph database. This function can only be called if the application has not yet called the [PeerGraphListen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphlisten) or [PeerGraphConnect](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphconnect) function.

## Parameters

### `hGraph` [in]

Handle to the peer graph.

### `pwzFilePath` [in]

Pointer to a string that contains the path to the file in which the imported data is stored.

## Return value

If the function call succeeds, the return value is S_OK. Otherwise, it returns either one of the WinErr.h values or one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **PEER_E_GRAPH_IN_USE** | The graph is currently being used, and cannot be imported. Either [PeerGraphListen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphlisten) or [PeerGraphConnect](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphconnect) has been called. |
| **PEER_E_INVALID_DATABASE** | The specified database is not valid. |
| **PEER_E_INVALID_GRAPH** | The handle to the peer graph is invalid. |
| **PEER_E_NOT_INITIALIZED** | The graph must be initialized with a call to [PeerGraphStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphstartup) before using this function. |

## Remarks

The **PeerGraphImportDatabase** function cannot be used to import a database from a different peer graph. **PeerGraphImportDatabase** must be called after [PeerGraphOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphopen), not after [PeerGraphCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphcreate).

The database being imported must have the same peer graph ID and peer ID.

## See also

[PeerGraphExportDatabase](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphexportdatabase)