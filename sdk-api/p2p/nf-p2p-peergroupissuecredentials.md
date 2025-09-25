# PeerGroupIssueCredentials function

## Description

The **PeerGroupIssueCredentials** function issues credentials, including a GMC, to a specific identity, and optionally returns an invitation XML string the invited peer can use to join a peer group.

## Parameters

### `hGroup` [in]

Handle to a peer group for which a peer will issue credentials to potential invited peers. This handle is returned by the [PeerGroupCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreate), [PeerGroupOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopen), or [PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin) function. This parameter is required.

### `pwzSubjectIdentity` [in]

Specifies the identity of a peer to whom credentials will be issued. This parameter is required.

### `pCredentialInfo` [in]

[PEER_CREDENTIAL_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_credential_info) structure that contains information about the credentials of a peer whose identity is specified in *pwzSubjectIdentity*. If this parameter is **NULL**, the information stored in the peer database is used, instead. This parameter is optional.

If this parameter is provided, the following fields in [PEER_CREDENTIAL_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_credential_info) are ignored:

* **pwzIssuerPeerName**
* **pwzIssuerFriendlyName**

### `dwFlags` [in]

Specifies a set of flags used to describe actions taken when credentials are issued. If this parameter is set to 0 (zero), the credentials are returned in *ppwzInvitation*. This parameter is optional.

| Value | Meaning |
| --- | --- |
| **PEER_GROUP_STORE_CREDENTIALS** | Publish the subject identity's newly-created GMC in the group database. The GMC is picked up automatically by the subject. If this flag is not set, the credentials must be obtained by a different application such as email. |

### `ppwzInvitation` [out]

Pointer to an invitation XML string returned by the function call. This invitation is passed out-of-band to the invited peer who uses it in a call to [PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin). This parameter is optional.

## Return value

Returns **S_OK** if the operation succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory available to complete the operation. |
| **PEER_E_IDENTITY_DELETED** | The identity creating the credentials has been deleted. |
| **PEER_E_IDENTITY_NOT_FOUND** | The identity cannot be found in the group database, and *pCredentialInfo* is **NULL**. |
| **PEER_E_NO_KEY_ACCESS** | Access to the identity or group keys is denied. Typically, this is caused by an incorrect access control list (ACL) for the folder that contains the user or computer keys. This can happen when the ACL has been reset manually. |

Cryptography-specific errors can be returned from the [Microsoft RSA Base Provider](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-base-cryptographic-provider). These errors are prefixed with CRYPT_* and defined in Winerror.h.

## Remarks

This function can only be called successfully by an administrator.

The credentials for a member ([PEER_CREDENTIAL_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_credential_info)) are obtained by calling [PeerGroupEnumMembers](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupenummembers). The credentials are located in the **pCredentialInfo** field of the [PEER_MEMBER](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_member) structure for a specific member.