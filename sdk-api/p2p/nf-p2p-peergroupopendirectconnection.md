# PeerGroupOpenDirectConnection function

## Description

The **PeerGroupOpenDirectConnection** function establishes a direct connection with another peer in a peer group.

## Parameters

### `hGroup` [in]

Handle to the peer group that hosts the direct connection. This handle is returned by the [PeerGroupCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreate), [PeerGroupOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopen), or [PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin) function. This parameter is required.

### `pwzIdentity` [in]

Pointer to a Unicode string that contains the identity a peer connects to. This parameter is required.

### `pAddress` [in]

Pointer to a [PEER_ADDRESS](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_address) structure that contains the IPv6 address the peer connects to. This parameter is required.

### `pullConnectionId` [out]

Unsigned 64-bit integer that identifies the direct connection. This ID value cannot be assumed as valid until the [PEER_GROUP_EVENT_DIRECT_CONNECTION](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_group_event_type) event is raised and indicates that the connection has been accepted by the other peer. This parameter is required.

## Return value

Returns **S_OK** if the operation succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory available to complete the operation. |
| **PEER_E_CONNECT_SELF** | The connection failed because it was a loopback, that is, the connection is between a peer and itself. |
| **PEER_E_NO_KEY_ACCESS** | Access to the peer identity or peer group keys is denied. This is typically caused by an incorrect access control list (ACL) for the folder that contains the user or computer keys. This can happen when the ACL has been reset manually. |

Cryptography-specific errors can be returned from the [Microsoft RSA Base Provider](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-base-cryptographic-provider). These errors are prefixed with CRYPT_* and defined in Winerror.h.

## Remarks

Every direct connection opened with this function must be closed with [PEER_GROUP_EVENT DATA](https://learn.microsoft.com/windows/win32/api/p2p/ns-p2p-peer_group_event_data-r1) structure has the **status** member of its component [PEER_EVENT_CONNECTION_CHANGE_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_event_connection_change_data) structure set to PEER_CONNECTION_FAILED.

## See also

 [PEER_ADDRESS](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_address)

[PEER_EVENT_CONNECTION_CHANGE_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_event_connection_change_data)

[PEER_GROUP_EVENT DATA](https://learn.microsoft.com/windows/win32/api/p2p/ns-p2p-peer_group_event_data-r1)

[PEER_GROUP_EVENT_DIRECT_CONNECTION](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_group_event_type)

[PeerGroupCloseDirectConnection](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupclosedirectconnection)

[PeerGroupCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreate)

[PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin)

[PeerGroupOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopen)

[PeerGroupSendData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupsenddata)