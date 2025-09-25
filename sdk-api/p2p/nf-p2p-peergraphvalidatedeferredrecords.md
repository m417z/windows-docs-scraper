# PeerGraphValidateDeferredRecords function

## Description

The **PeerGraphValidateDeferredRecords** function indicates to the Peer Graphing Infrastructure that it is time to resubmit any deferred records for the security module to validate.

## Parameters

### `hGraph` [in]

Handle to the peer graph.

### `cRecordIds` [in]

Specifies the number of records specified in *pRecordIds*. Specify zero (0) to instruct the Graphing infrastructure to validate all deferred records. If zero (0) is specified, *pRecordIds* is ignored.

### `pRecordIds` [in]

Pointer to an array of record IDs to validate.

## Return value

If the function call succeeds, the return value is **S_OK**. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform the specified operation. |
| **PEER_E_INVALID_GRAPH** | The handle to the peer graph is invalid. |
| **PEER_E_NOT_INITIALIZED** | The peer graph must be initialized with a call to [PeerGraphStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphstartup) before using this function. |

## Remarks

When a new record comes to the computer from its neighbor in the peer graph, the Peer Graphing Infrastructure attempts to validate the record by calling the [PFNPEER_VALIDATE_RECORD](https://learn.microsoft.com/windows/desktop/api/p2p/nc-p2p-pfnpeer_validate_record) callback, specified in the [PEER_SECURITY_INTERFACE](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_security_interface) structure during a call to either [PeerGraphCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphcreate) or [PeerGraphOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphopen). If the security module does not have all the information necessary to validate the record, it returns the PEER_E_DEFERRED_VALIDATION error. Once the security module obtains enough information, it must then validate the records using **PeerGraphValidateDeferredRecords**. When this function is called, the Peer Graphing Infrastructure calls *PFNPEER_VALIDATE_RECORD* to validate the records with IDs in *pRecordIds*.

## See also

[PEER_SECURITY_INTERFACE](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_security_interface)

[PFNPEER_VALIDATE_RECORD](https://learn.microsoft.com/windows/desktop/api/p2p/nc-p2p-pfnpeer_validate_record)

[PeerGraphCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphcreate)

[PeerGraphOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphopen)