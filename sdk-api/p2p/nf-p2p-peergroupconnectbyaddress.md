# PeerGroupConnectByAddress function

## Description

The **PeerGroupConnectByAddress** function attempts to connect to the peer group that other peers with known IPv6 addresses are participating in. After this function is called successfully, a peer can communicate with other members of the peer group.

## Parameters

### `hGroup` [in]

Handle to the peer group to which a peer intends to connect. This handle is returned by the [PeerGroupCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreate), [PeerGroupOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopen),[PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin), or [PeerGroupPasswordJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergrouppasswordjoin) function. This parameter is required.

### `cAddresses` [in]

The total number of [PEER_ADDRESS](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_address) structures pointed to by *pAddresses*.

### `pAddresses` [in]

Pointer to a list of [PEER_ADDRESS](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_address) structures that specify the endpoints of peers participating in the group.

## Return value

Returns S_OK if the operation succeeds. Otherwise, the function returns the following value.

| Return code | Description |
| --- | --- |
| **PEER_E_INVALID_GROUP** | The handle to the peer group is invalid. |

Cryptography-specific errors may be returned from the [Microsoft RSA Base Provider](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-base-cryptographic-provider). These errors are prefixed with CRYPT_* and defined in Winerror.h.

## Remarks

If a time-out value for PeerGroupConnectByAddress is not provided in the application, encountering a failure will cause the application to hang. A time-out value of 30 seconds is recommended.

## See also

[PEER_ADDRESS](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_address)

[PeerGroupConnect](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupconnect)

[PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin)

[PeerGroupPasswordJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergrouppasswordjoin)