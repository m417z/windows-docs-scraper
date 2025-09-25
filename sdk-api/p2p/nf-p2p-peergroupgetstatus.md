# PeerGroupGetStatus function

## Description

The **PeerGroupGetStatus** function retrieves the current status of a group.

## Parameters

### `hGroup` [in]

Handle to a peer group whose status is returned. This handle is returned by the [PeerGroupCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreate), [PeerGroupOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopen), or [PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin) function. This parameter is required.

### `pdwStatus` [out]

Pointer to a set of [PEER_GROUP_STATUS](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_group_status) flags that describe the status of a peer group.

## Return value

Returns **S_OK** if the operation succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more of the parameters is invalid. |
| **E_OUTOFMEMORY** | There is not enough memory available to complete an operation. |
| **PEER_E_INVALID_GROUP** | The handle to a group is invalid. |

Cryptography-specific errors can be returned from the [Microsoft RSA Base Provider](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-base-cryptographic-provider). These errors are prefixed with CRYPT_* and defined in Winerror.h.

## See also

[PEER_GROUP_STATUS](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_group_status)

[PeerGroupCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreate)

[PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin)

[PeerGroupOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopen)