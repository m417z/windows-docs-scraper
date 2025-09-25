# PeerGroupSetProperties function

## Description

The **PeerGroupSetProperties** function sets the current peer group properties. In version 1.0 of this API, only the creator of the peer group can perform this operation.

## Parameters

### `hGroup` [in]

Handle to the peer group whose properties are set by a peer. This handle is returned by the [PeerGroupCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreate), [PeerGroupOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopen), or [PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin) function. This parameter is required.

### `pProperties` [in]

Pointer to a peer-populated [PEER_GROUP_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_group_properties)
structure that contains the new properties. To obtain this structure, a peer must first call [PeerGroupGetProperties](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupgetproperties), change the appropriate fields, and then pass it as this parameter. This parameter is required.

The following members of [PEER_GROUP_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_group_properties) cannot be changed:

* **dwSize**
* **pwzCloud**
* **pwzClassifier**
* **pwzGroupPeerName**
* **pwzCreatorPeerName**

## Return value

Returns **S_OK** if the operation succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory available to complete the operation. |
| **PEER_E_GROUP_NOT_READY** | The group is not in a state where peer group properties can be set. For example, [PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin) has been called, but synchronization with the peer group database is not complete. |
| **PEER_E_INVALID_GROUP** | The handle to the peer group is invalid. |
| **PEER_E_INVALID_GROUP_PROPERTIES** | One or more of the specified properties is invalid. |
| **PEER_E_NOT_AUTHORIZED** | The current identity does not have the authorization to change these properties. In this case, the identity is not the creator of the peer group. |
| **PEER_E_PASSWORD_DOES_NOT_MEET_POLICY** | Password specified does not meet system password requirements. |

Cryptography-specific errors can be returned from the [Microsoft RSA Base Provider](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-base-cryptographic-provider). These errors are prefixed with CRYPT_* and defined in Winerror.h.

## Remarks

For applications that utilize passwords, it is recommended the passwords are handled securely by calling the [CryptoProtectMemory](https://learn.microsoft.com/windows/desktop/api/dpapi/nf-dpapi-cryptprotectmemory) and [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)) functions.

## See also

[PEER_GROUP_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_group_properties)

[PeerGroupCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreate)

[PeerGroupGetProperties](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupgetproperties)

[PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin)

[PeerGroupOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopen)