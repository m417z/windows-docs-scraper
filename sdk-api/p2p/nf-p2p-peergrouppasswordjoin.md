# PeerGroupPasswordJoin function

## Description

The **PeerGroupPasswordJoin** function prepares a peer with an invitation and the correct password to join a password-protected peer group prior to calling [PeerGroupConnect](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupconnect) or [PeerGroupConnectByAddress](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupconnectbyaddress).

## Parameters

### `pwzIdentity` [in]

Pointer to a Unicode string that contains the identity opening the specified peer group. If this parameter is **NULL**, the implementation uses the identity obtained from [PeerIdentityGetDefault](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peeridentitygetdefault).

### `pwzInvitation` [in]

Pointer to a Unicode string that contains the XML invitation granted by another peer. An invitation with a password is created when the inviting peer calls [PeerGroupCreatePasswordInvitation](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreatepasswordinvitation). Specific details regarding this invitation, including the password set by the group creator, can be obtained as a [PEER_INVITATION_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_invitation_info) structure by calling [PeerGroupParseInvitation](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupparseinvitation). This parameter is required.

### `pwzPassword` [in]

Pointer to a zero-terminated Unicode string that contains the password required to validate and join the peer group. This password must match the password specified in the invitation. This parameter is required.

### `pwzCloud` [in]

Pointer to a Unicode string that contains the name of the PNRP cloud where a group is located. The default value is **NULL**, which indicates that the cloud specified in the invitation must be used.

### `phGroup` [out]

Pointer to the handle of the peer group. To start communication with a group, call [PeerGroupConnect](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupconnect). This parameter is required.

## Return value

Returns **S_OK** if the operation succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory available to complete the operation. |
| **PEER_E_CLOUD_NAME_AMBIGUOUS** | The cloud cannot be uniquely discovered, for example, more than one cloud matches the provided name. |
| **PEER_E_INVALID_PEER_NAME** | The peer identity specified in *pwzIdentity* is invalid. |
| **PEER_E_INVITATION_NOT_TRUSTED** | The invitation is not trusted by the peer. It has been altered or contains errors. |
| **PEER_E_NO_CLOUD** | The cloud cannot be located. |
| **PEER_E_UNSUPPORTED_VERSION** | The invitation is not supported by the current version of the Peer Infrastructure. |
| **PEER_E_NO_KEY_ACCESS** | Access to the peer identity or peer group keys is denied. Typically, this is caused by an incorrect access control list (ACL) for the folder that contains the user or computer keys. This can happen when the ACL has been reset manually. |
| **PEER_S_ALREADY_A_MEMBER** | The local peer attempted to join a group based on a password more than once. |

Cryptography-specific errors may be returned from the [Microsoft RSA Base Provider](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-base-cryptographic-provider). These errors are prefixed with CRYPT_* and defined in Winerror.h.

## Remarks

In the event of a clock skew between participating machines, the initial **PeerGroupPasswordJoin** function may still succeed while the following call of [PeerGroupConnect](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupconnect) can result in a failure to join depending on the severity of the skew.

## See also

[PeerGroupConnect](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupconnect)

[PeerGroupConnectByAddress](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupconnectbyaddress)