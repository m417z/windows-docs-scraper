# PeerGroupJoin function

## Description

The **PeerGroupJoin** function prepares a peer with an invitation to join an existing peer group prior to calling [PeerGroupConnect](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupconnect) or [PeerGroupConnectByAddress](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupconnectbyaddress).

## Parameters

### `pwzIdentity` [in]

Pointer to a Unicode string that contains the identity opening the specified peer group. If this parameter is **NULL**, the implementation uses the identity obtained from [PeerIdentityGetDefault](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peeridentitygetdefault).

### `pwzInvitation` [in]

Pointer to a Unicode string that contains the XML invitation granted by another peer. An invitation is created when the inviting peer calls [PeerGroupCreateInvitation](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreateinvitation) or [PeerGroupIssueCredentials](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupissuecredentials). Specific details regarding this invitation can be obtained as a [PEER_INVITATION_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_invitation_info) structure by calling [PeerGroupParseInvitation](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupparseinvitation). This parameter is required.

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
| **PEER_E_INVALID_TIME_PERIOD** | The validity period specified in the invitation is invalid. Either the specified period has expired or the invitation is not yet valid (i.e. the specified ValidityStart date\time has not yet been reached). One possible reason for the return of this error is that the system clock is incorrectly set on the machine joining the group, or on the machine that issued the invitation. |
| **PEER_E_INVITATION_NOT_TRUSTED** | The invitation is not trusted. This may be due to invitation alteration, errors, or expiration. |
| **PEER_E_NO_CLOUD** | The cloud cannot be located. |
| **PEER_E_UNSUPPORTED_VERSION** | The invitation is not supported by the current version of the Peer Infrastructure. |
| **PEER_E_NO_KEY_ACCESS** | Access to the peer identity or peer group keys is denied. Typically, this is caused by an incorrect access control list (ACL) for the folder that contains the user or computer keys. This can happen when the ACL has been reset manually. |

Cryptography-specific errors can be returned from the [Microsoft RSA Base Provider](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-base-cryptographic-provider). These errors are prefixed with CRYPT_* and defined in Winerror.h.

## See also

[PEER_INVITATION_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_invitation_info)

[PeerGroupConnect](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupconnect)

[PeerGroupConnectByAddress](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupconnectbyaddress)

[PeerGroupCreateInvitation](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreateinvitation)

[PeerGroupOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopen)

[PeerGroupParseInvitation](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupparseinvitation)