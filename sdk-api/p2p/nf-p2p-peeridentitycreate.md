# PeerIdentityCreate function

## Description

The **PeerIdentityCreate** function creates a new peer identity and returns its name. The name of the peer identity must be passed in all subsequent calls to the Peer Identity Manager, Peer Grouping, or PNRP functions that operate on behalf of the peer identity. The peer identity name specifies which peer identity is being used.

## Parameters

### `pwzClassifier` [in]

Specifies the classifier to append to the published peer identity name. This string is a Unicode string, and can be **NULL**. This string can only be 150 characters long, including the **NULL** terminator.

### `pwzFriendlyName` [in]

Specifies the friendly name of the peer identity. This is a Unicode string, and can be **NULL**. This string can only be 256 characters long, including the **NULL** terminator. If *pwzFriendlyName* is **NULL**, the name of the identity is the friendly name. The friendly name is optional, and it does not have to be unique.

### `hCryptProv` [in]

Handle to the cryptographic service provider (CSP) that contains an AT_KEYEXCHANGE key pair of at least 1024 bits in length. This key pair is used as the basis for a new peer identity. If *hCryptProv* is zero (0), a new key pair is generated for the peer identity.

**Note** The Identity Manager API does not support a CSP that has user protected keys. If a CSP that has user protected keys is used, **PeerIdentityCreate** returns **E_INVALIDARG**.

### `ppwzIdentity` [out]

Receives a pointer to the name of a peer identity that is created. This name must be used in all subsequent calls to the Peer Identity Manager, Peer Grouping, or PNRP functions that operate on behalf of the peer identity. Returns **NULL** if the peer identity cannot be created.

## Return value

If the function call succeeds, the return value is **S_OK**. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The handle to the key specified by *hCryptProv* is not valid. |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform the specified operation. |
| **PEER_E_ALREADY_EXISTS** | The peer identity already exists. Only occurs if a peer identity based on the specified key and classifier already exists. |
| **PEER_E_NO_KEY_ACCESS** | Access to the peer identity or peer group keys is denied. Typically, this is caused by an incorrect access control list (ACL) for the folder that contains the user or computer keys. This can happen when the ACL has been reset manually. |
| **PEER_E_TOO_MANY_IDENTITIES** | The peer identity cannot be created because there are too many peer identities. |

## Remarks

The key pair and the classifier are used to generate the peer name of a new peer identity. After a peer identity is created, it is automatically stored on the disk.

The name of the identity should be freed by using [PeerFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerfreedata). This does not delete the peer identity. To delete the identity, use [PeerIdentityDelete](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peeridentitydelete) function.

If *hCryptProv* is not **NULL**, it can be released by using [CryptReleaseContext](https://learn.microsoft.com/windows/desktop/P2PSdk/identity-manager-reference-links) after the call returns.

## See also

[CryptReleaseContext](https://learn.microsoft.com/windows/desktop/P2PSdk/identity-manager-reference-links)

[PeerFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerfreedata)

[PeerIdentityDelete](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peeridentitydelete)