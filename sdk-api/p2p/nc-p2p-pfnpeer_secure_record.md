# PFNPEER_SECURE_RECORD callback function

## Description

The **PFNPEER_SECURE_RECORD** callback specifies the function that the Peer Graphing Infrastructure calls to secure records.

## Parameters

### `hGraph` [in]

Specifies the peer graph associated with the specified record.

### `pvContext` [in]

Pointer to the security context. This parameter points to the **pvContext** member of the [PEER_SECURITY_INTERFACE](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_security_interface) structure.

### `pRecord` [in]

Pointer to the record to secure.

### `changeType` [in]

Specifies the reason the validation must occur. [PEER_RECORD_CHANGE_TYPE](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_record_change_type) enumerates the valid values.

### `ppSecurityData` [out]

Specifies the security data for this record. This data is released by calling the method specified in the **pfnFreeSecurityData** member of the [PEER_SECURITY_INTERFACE](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_security_interface) after the data is copied and added to the record.

## Return value

If this callback succeeds, the return value is S_OK.

## Remarks

This callback is invoked whenever an application calls any of the methods that modify records, such as [PeerGraphAddRecord](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphaddrecord) or [PeerGraphUpdateRecord](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphupdaterecord). This callback
should create data that is specific to this record, such as a small digital signature, and return it through the *ppSecurityData* parameter.
This data is then added to the record in the **securityData** member, and is verified by the method specified by the **pfnValidateRecord** member of the [PEER_SECURITY_INTERFACE](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_security_interface).

**Note** This process happens on the local computer as well as any peer connected to the graph when the peer receives the record.

If the operation specified by the *changeType* parameter is not allowed, the callback should return a failure code, such as PEER_E_NOT_AUTHORIZED, instead of S_OK.

This callback can be invoked from any of the Peer Graphing API functions involving records, such as [PeerGraphUpdateRecord](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphupdaterecord).

## See also

[PEER_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_data)

[PEER_RECORD](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_record)

[PEER_RECORD_CHANGE_TYPE](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_record_change_type)

[PEER_SECURITY_INTERFACE](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_security_interface)