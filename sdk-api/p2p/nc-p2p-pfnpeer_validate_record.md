# PFNPEER_VALIDATE_RECORD callback function

## Description

The **PFNPEER_VALIDATE_RECORD** callback specifies the function that the Peer Graphing Infrastructure calls to validate records.

## Parameters

### `hGraph` [in]

Specifies the peer graph associated with the specified record.

### `pvContext` [in]

Pointer to the security context. This parameter should point to the **pvContext** member of the [PEER_SECURITY_INTERFACE](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_security_interface) structure.

### `pRecord` [in]

Specifies the record to validate.

### `changeType` [in]

Specifies the reason the validation must occur. Must be one of the [PEER_RECORD_CHANGE_TYPE](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_record_change_type) values.

## Return value

If this callback succeeds, the return value is S_OK; otherwise, the function returns one of the following errors:

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **PEER_E_DEFERRED_VALIDATION** | The specified record cannot be validated at this time because there is insufficient information to complete the operation. Validation is deferred. Call [PeerGraphValidateDeferredRecords](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphvalidatedeferredrecords) when sufficient information is obtained. |
| **PEER_E_INVALID_RECORD** | The specified record is invalid. |

## Remarks

When this callback is called by the Peer Graphing Infrastructure, a [PEER_RECORD_CHANGE_TYPE](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_record_change_type) value is passed. This specifies the operation just performed on the record. The application must verify the record based on the change type. If the application requires more information to verify the record, it can return PEER_E_DEFERRED_VALIDATION and the Peer Graphing Infrastructure places the record in a deferred-record list. Once the security mechanism has enough information to validate the record, it calls [PeerGraphValidateDeferredRecords](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphvalidatedeferredrecords), and any record in the deferred-record list is re-submitted for validation.

This callback can be invoked from any of the Peer Graphing API functions involving records, such as [PeerGraphUpdateRecord](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphupdaterecord).

## See also

[PEER_RECORD](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_record)

[PEER_RECORD_CHANGE_TYPE](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_record_change_type)

[PEER_SECURITY_INTERFACE](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_security_interface)

[PeerGraphValidateDeferredRecords](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphvalidatedeferredrecords)