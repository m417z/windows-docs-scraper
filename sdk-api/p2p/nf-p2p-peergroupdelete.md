# PeerGroupDelete function

## Description

The **PeerGroupDelete** function deletes the local data and certificate associated with a peer group.

## Parameters

### `pwzIdentity` [in]

Pointer to a Unicode string that contains the identity opening the specified peer group. If this parameter is **NULL**, the implementation uses the identity obtained from [PeerIdentityGetDefault](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peeridentitygetdefault).

### `pwzGroupPeerName` [in]

Pointer to a Unicode string that contains the peer name of the peer group for which data is deleted. This parameter is required. The group
name can be obtained by calling [PeerGroupGetProperties](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupgetproperties) prior to [PeerGroupClose](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupclose), or by parsing the invitation with
[PeerGroupParseInvitation](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupparseinvitation).

## Return value

Returns S_OK if the operation succeeds. Otherwise, the function returns one of the following values.

**Note** If a delete operation fails due to a file system error, the appropriate file system error is returned.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | Access to the peer group database is denied. Ensure that the peer has permission to perform this operation. In this case, the peer must be the original creator of the peer group. |
| **E_INVALIDARG** | One of the parameters is invalid. |
| **PEER_E_NOT_FOUND** | The peer group cannot be found. |
| **PEER_E_NO_KEY_ACCESS** | Access to the identity or peer group keys is denied. Typically, this is caused by an incorrect access control list (ACL) for the folder that contains the user or computer keys. This can happen when the ACL is reset manually. |

Cryptography-specific errors can be returned from the [Microsoft RSA Base Provider](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-base-cryptographic-provider). These errors are prefixed with CRYPT_* and defined in Winerror.h.

## Remarks

If a peer group is deleted, all handles associated with that group immediately become invalid. As a best practice, ensure that all handles for this group are closed before calling this function. Otherwise, this data is deleted from all other running peer applications that use it, which can cause errors and instability.

## See also

[PeerGroupCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreate)