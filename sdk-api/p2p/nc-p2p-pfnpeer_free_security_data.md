# PFNPEER_FREE_SECURITY_DATA callback function

## Description

The **PFNPEER_FREE_SECURITY_DATA** callback specifies the function that the Peer Graphing Infrastructure calls to free data returned by [PFNPEER_SECURE_RECORD](https://learn.microsoft.com/windows/desktop/api/p2p/nc-p2p-pfnpeer_secure_record) and [PFNPEER_VALIDATE_RECORD](https://learn.microsoft.com/windows/desktop/api/p2p/nc-p2p-pfnpeer_validate_record) callbacks.

## Parameters

### `hGraph` [in]

Specifies the peer graph associated with the specified record.

### `pvContext` [in]

Pointer to the security context to free. This parameter is set to the value of the **pvContext** member of the [PEER_SECURITY_INTERFACE](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_security_interface) structure passed in [PeerGraphCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphcreate) or [PeerGraphOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphopen).

### `pSecurityData` [in]

Pointer to the security data to free.

## Return value

If the callback is successful, the return value is S_OK. Otherwise, the callback returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform the specified operation. |

## Remarks

This callback can be invoked from any of the Peer Graphing API functions involving records, such as [PeerGraphUpdateRecord](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphupdaterecord).

## See also

[PEER_DATA](https://learn.microsoft.com/windows/win32/api/p2p/ns-p2p-peer_data)

[PEER_SECURITY_INTERFACE](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_security_interface)

[PeerGraphCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphcreate)

[PeerGraphOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphopen)