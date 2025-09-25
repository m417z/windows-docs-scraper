# PeerGroupGetProperties function

## Description

The **PeerGroupGetProperties** function retrieves information on the properties of a specified group.

## Parameters

### `hGroup` [in]

Handle to a peer group whose properties are retrieved. This handle is returned by the [PeerGroupCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreate), [PeerGroupOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopen), or [PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin) function. This parameter is required.

### `ppProperties` [out]

Pointer to a [PEER_GROUP_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_group_properties) structure that contains information about peer group properties. This data must be freed with [PeerFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerfreedata). This parameter is required.

## Return value

Returns **S_OK** if the operation succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform a specified operation. |
| **PEER_E_GROUP_NOT_READY** | The group is not in a state where peer group properties can be retrieved. For example, [PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin) is called, but synchronization with the group database has not completed. |
| **PEER_E_INVALID_GROUP** | The handle to the peer group is invalid. |

Cryptography-specific errors can be returned from the [Microsoft RSA Base Provider](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-base-cryptographic-provider). These errors are prefixed with CRYPT_* and defined in Winerror.h.

## Remarks

Group properties cannot be retrieved if a peer has not synchronized with a peer group database. To synchronize with a peer group database before calling this function, first call [PeerGroupConnect](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupconnect).

## See also

[PEER_GROUP_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_group_properties)

[PeerGroupCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreate)

[PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin)

[PeerGroupOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopen)

[PeerGroupSetProperties](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupsetproperties)