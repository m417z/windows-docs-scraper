# PeerGroupCreate function

## Description

The **PeerGroupCreate** function creates a new peer group.

## Parameters

### `pProperties` [in]

Pointer to a [PEER_GROUP_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_group_properties) structure that specifies the specific details of the group, such as the peer group names, invitation lifetimes, and presence lifetimes. This parameter is required.

The following members must be set:

* **pwzCreatorPeerName**

The following members cannot be set:

* **pwzGroupPeerName**

The remaining members are optional.

### `phGroup` [out]

Returns the handle pointer to the peer group. Any function called with this handle as a parameter has the corresponding action performed on that peer group. This parameter is required.

## Return value

Returns S_OK if the operation succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform the specified operation. |
| **PEER_E_CLOUD_NAME_AMBIGUOUS** | The cloud specified in *pProperties* cannot be uniquely discovered (more than one cloud matches the provided name). |
| **PEER_E_INVALID_CLASSIFIER** | The peer group classifier specified in *pProperties* is invalid. |
| **PEER_E_INVALID_PEER_NAME** | The peer name specified for the group in *pProperties* is invalid. |
| **PEER_E_INVALID_PROPERTIES** | One or more of the peer group properties supplied in *pProperties* is invalid. |
| **PEER_E_NO_CLOUD** | The cloud specified in *pProperties* cannot be located. |
| **PEER_E_NO_KEY_ACCESS** | Access to the identity or group keys is denied. Typically, this is caused by an incorrect access control list (ACL) for the folder that contains the user or computer keys. This can happen when the ACL is reset manually. |
| **PEER_E_PASSWORD_DOES_NOT_MEET_POLICY** | Password specified does not meet system password requirements. |
| **ERROR_DELETE_PENDING** | The peer identity specified as the Group Creator has been deleted or is in the process of being deleted. |

Cryptography-specific errors can be returned from the [Microsoft RSA Base Provider](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-base-cryptographic-provider). These errors are prefixed with CRYPT_* and defined in Winerror.h.

## Remarks

[PeerGroupConnect](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupconnect) must be called by the group creator immediately after creation. If this does not take place, users given an invitation will call PeerGroupConnect successfully but they will not be able to listen and will eventually receive the connection failed event.

An application obtains an identity by calling [PeerIdentityCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peeridentitycreate), or any other method that returns an identity name string. This identity serves as the owner of the group, and is the initial member of the peer group when created.

For applications that utilize passwords, it is recommended the passwords are handled securely by calling the [CryptoProtectMemory](https://learn.microsoft.com/windows/desktop/api/dpapi/nf-dpapi-cryptprotectmemory) and [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)) functions.

## See also

 [PEER_GROUP_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_group_properties)

[PeerGroupClose](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupclose)

[PeerGroupConnect](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupconnect)

[PeerGroupOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopen)