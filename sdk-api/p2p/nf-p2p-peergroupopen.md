# PeerGroupOpen function

## Description

The **PeerGroupOpen** function opens a peer group that a peer has created or joined. After a peer group is opened, the peer can register for event notifications.

## Parameters

### `pwzIdentity` [in]

Pointer to a Unicode string that contains the identity a peer uses to open a group. This parameter is required.

### `pwzGroupPeerName` [in]

Pointer to a Unicode string that contains the peer name of the peer group. This parameter is required.

### `pwzCloud` [in]

Pointer to a Unicode string that contains the name of the PNRP cloud in which the peer group is located. If the value is **NULL**, the cloud specified in the peer group properties is used.

### `phGroup` [out]

Pointer to a handle for a peer group. If this value is **NULL**, the open operation is unsuccessful. This parameter is required.

## Return value

Returns **S_OK** if the operation succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory available to complete the operation. |
| **PEER_E_CLOUD_NAME_AMBIGUOUS** | The cloud specified in *pwzCloud* cannot be uniquely discovered, for example, more than one cloud matches the provided name. |
| **PEER_E_NO_CLOUD** | The cloud specified in *pwzCloud* cannot be located. |
| **PEER_E_NO_KEY_ACCESS** | Access to the peer identity or peer group keys is denied. Typically, this is caused by an incorrect access control list (ACL) for the folder that contains the user or computer keys. This can happen when the ACL has been reset manually. |

Cryptography-specific errors can be returned from the [Microsoft RSA Base Provider](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-base-cryptographic-provider). These errors are prefixed with CRYPT_* and defined in Winerror.h.

## Remarks

Multiple applications can open the same group simultaneously. Any application can choose to open a group without subsequently calling [PeerGroupConnect](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupconnect). These applications are considered to be offline. However, a second application can open and connect the peer to the group, which means that an application must be ready to connect at any time.

## See also

[PeerGroupClose](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupclose)

[PeerGroupConnect](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupconnect)

[PeerGroupCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreate)

[PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin)