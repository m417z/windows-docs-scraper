# PeerGroupCloseDirectConnection function

## Description

The **PeerGroupCloseDirectConnection** function closes a specific direct connection between two peers.

## Parameters

### `hGroup` [in]

Handle to the peer group that contains the peers involved in the direct connection. This handle is returned by the [PeerGroupCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreate), [PeerGroupOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopen), or [PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin) function. This parameter is required.

### `ullConnectionId` [in]

Specifies the connection ID to disconnect from. This parameter is required and has no default value.

## Return value

Returns S_OK if the operation succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **PEER_E_CONNECTION_NOT_FOUND** | A direct connection that matches the supplied connection ID cannot be found. |
| **PEER_E_INVALID_GROUP** | The handle to the peer group is invalid. |

Cryptography-specific errors can be returned from the [Microsoft RSA Base Provider](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-base-cryptographic-provider). These errors are prefixed with CRYPT_* and defined in Winerror.h.

## See also

[PeerGroupCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreate)

[PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin)

[PeerGroupOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopen)

[PeerGroupOpenDirectConnection](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopendirectconnection)