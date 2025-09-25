# PeerGraphExportDatabase function

## Description

The **PeerGraphExportDatabase** function exports a peer graph database into a file that you can move to a different computer. By using [PeerGraphImportDatabase](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphimportdatabase), a peer graph database can be imported to a different computer.

## Parameters

### `hGraph` [in]

Handle to a peer graph.

### `pwzFilePath` [in]

Pointer to a string that contains the file path to store exported data. If a data storage file exists and contains data when new data is exported to it, then the new data overwrites the old data.

## Return value

If the function call succeeds, the return value is **S_OK**. Otherwise, it returns either an error located in WinErr.h, or one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One parameter is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform a specified operation. |
| **PEER_E_INVALID_GRAPH** | The handle to a graph is invalid. |
| **PEER_E_NOT_INITIALIZED** | A graph must be initialized with a call to [PeerGraphStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphstartup) before using this function. |

## Remarks

If the export of a database fails because of file creation errors, a standard WinErr.h file error is returned.

## See also

[PeerGraphImportDatabase](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphimportdatabase)