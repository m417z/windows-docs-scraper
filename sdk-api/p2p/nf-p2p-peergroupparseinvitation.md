# PeerGroupParseInvitation function

## Description

The **PeerGroupParseInvitation** function returns a [PEER_INVITATION_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_invitation_info) structure with the details of a specific invitation.

## Parameters

### `pwzInvitation` [in]

Pointer to a Unicode string that contains the specific peer group invitation. This parameter is required.

### `ppInvitationInfo` [out]

Pointer to a [PEER_INVITATION_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_invitation_info) structure with the details of a specific invitation. To release the resources used by this structure, pass this pointer to [PeerFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerfreedata). This parameter is required.

## Return value

Returns **S_OK** if the operation succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory available to complete an operation. |
| **PEER_E_INVITATION_NOT_TRUSTED** | The invitation is not trusted by the peer. It has been altered or contains errors. |
| **PEER_E_UNSUPPORTED_VERSION** | The invitation is not supported by the current version of the Peer Infrastructure. |

Cryptography-specific errors can be returned from the [Microsoft RSA Base Provider](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-base-cryptographic-provider). These errors are prefixed with CRYPT_* and defined in Winerror.h.

## See also

[PEER_INVITATION_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_invitation_info)

[PeerGroupCreateInvitation](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreateinvitation)