# PeerGroupCreatePasswordInvitation function

## Description

The **PeerGroupCreatePasswordInvitation** function returns an XML string that can be used by the specified peer to join a group with a matching password.

## Parameters

### `hGroup` [in]

Handle to the peer group for which this invitation is issued. This handle is returned by the [PeerGroupCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreate), [PeerGroupOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopen), or [PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin) function. This parameter is required.

### `ppwzInvitation` [out]

Pointer to a Unicode string that contains the invitation from the issuer. This invitation can be passed to [PeerGroupPasswordJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergrouppasswordjoin) by the recipient in order to join the specified peer group. To return the details of the invitation as a [PEER_INVITATION_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_invitation_info) structure, pass this string to [PeerGroupParseInvitation](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupparseinvitation). To release this data, pass this pointer to [PeerFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerfreedata).

This function requires that the following fields are set on the [PEER_GROUP_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_group_properties) structure passed to [PeerGroupCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreate).

* **pwzGroupPassword**. This field must contain the password used to validate peers joining the peer group.
* **groupPasswordRole**. This field must containing the GUID of the role (administrator or peer) for which the password is required.
* **dwAuthenticationSchemes**. This field must have the **PEER_GROUP_PASSWORD_AUTHENTICATION** flag (0x00000001) set on it.

## Return value

Returns S_OK if the operation succeeds; otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform the specified operation. |
| **PEER_E_GROUP_NOT_READY** | The peer group is not in a state where records can be added. For example, [PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin) is called, but synchronization with the group database has not completed. |
| **PEER_E_CHAIN_TOO_LONG** | The GMC chain is longer than 24 administrators or members. For more information about GMC chains, please refer to the [How Group Security Works](https://learn.microsoft.com/windows/desktop/P2PSdk/how-group-security-works) documentation. |
| **PEER_E_IDENTITY_DELETED** | The data passed as *pwzIdentityInfo* is for a deleted identity and no longer valid. |
| **PEER_E_NOT_AUTHORIZED** | The peer that called this method is not an administrator. |
| **PEER_E_NO_KEY_ACCESS** | Access to the identity or peer group keys is denied. Typically, this is caused by an incorrect access control list (ACL) for the folder that contains the user or computer keys. This can happen when the ACL is reset manually. |

Cryptography-specific errors may be returned from the [Microsoft RSA Base Provider](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-base-cryptographic-provider). These errors are prefixed with CRYPT_* and defined in Winerror.h.