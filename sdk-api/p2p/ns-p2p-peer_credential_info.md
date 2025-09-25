# PEER_CREDENTIAL_INFO structure

## Description

The **PEER_CREDENTIAL_INFO** structure defines information used to obtain and issue a peer's security credentials.

## Members

### `dwSize`

Specifies the size of this structure, in bytes.

### `dwFlags`

Reserved. This field must be set to 0.

### `pwzFriendlyName`

Pointer to a Unicode string that specifies the friendly (display) name of the issuer.

### `pPublicKey`

Pointer to a **CERT_PUBLIC_KEY_INFO** structure that contains the peer group member's public key and the encryption type it uses.

### `pwzIssuerPeerName`

Pointer to a Unicode string that specifies the membership issuer's PNRP name.

### `pwzIssuerFriendlyName`

Pointer to a Unicode string that specifies the friendly (display) name of the issuer.

### `ftValidityStart`

Specifies the [FILETIME](https://learn.microsoft.com/windows/desktop/P2PSdk/graphing-reference-links) structure that contains the time when the recipient's membership in the peer group becomes valid. When issuing new credentials this value must be greater than the ValidityStart value for the member's current credentials.

### `ftValidityEnd`

Specifies the [FILETIME](https://learn.microsoft.com/windows/desktop/P2PSdk/graphing-reference-links) structure that contains the time when the recipient's membership in the peer group becomes invalid.

### `cRoles`

Specifies the number of role GUIDs present in **pRoles**.

### `pRoles`

Pointer to a list of GUIDs that specifies the combined set of available roles. The available roles are as follows.

| Value | Meaning |
| --- | --- |
| **PEER_GROUP_ROLE_ADMIN** | This role can issue invitations, issue credentials, and renew the GMC of other administrators, as well as behave as a member of the peer group. |
| **PEER_GROUP_ROLE_MEMBER** | The role can add records to the peer group database. |

## See also

[PEER_MEMBER](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_member)

[PeerGroupIssueCredentials](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupissuecredentials)