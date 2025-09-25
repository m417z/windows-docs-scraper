# PEER_INVITATION_INFO structure

## Description

The **PEER_INVITATION_INFO** structure defines information about an invitation to join a peer group. Invitations are represented as Unicode strings. To obtain this structure, pass the XML invitation string created by [PeerGroupCreateInvitation](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreateinvitation) to [PeerGroupParseInvitation](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupparseinvitation).

## Members

### `dwSize`

Specifies the size of this structure, in bytes.

### `dwFlags`

Must be set to 0x00000000.

### `pwzCloudName`

Pointer to a Unicode string that specifies the PNRP cloud name.

### `dwScope`

Specifies the scope under which the peer group was registered.

| Value | Meaning |
| --- | --- |
| **PNRP_GLOBAL_SCOPE** | Global scope, including the Internet. |
| **PNRP_LOCAL_SCOPE** | Local scope. |
| **PNRP_LINK_LOCAL_SCOPE** | Link-local scope. |

### `dwCloudFlags`

Specifies a set of flags that describe PNRP cloud features.

| Value | Meaning |
| --- | --- |
| **PNRP_CLOUD_NO_FLAGS**<br><br>0 | No flags are set. |
| **PNRP_CLOUD_NAME_LOCAL**<br><br>1 | The cloud name is not available on other computers; it is locally defined. |

### `pwzGroupPeerName`

Pointer to a Unicode string that specifies the peer name of the peer group.

### `pwzIssuerPeerName`

Pointer to a Unicode string that specifies the PNRP name of the peer issuing the invitation.

### `pwzSubjectPeerName`

Pointer to a Unicode string that specifies the PNRP name of the peer that receives the invitation.

### `pwzGroupFriendlyName`

Pointer to a Unicode string that specifies the friendly (display) name of the peer group.

### `pwzIssuerFriendlyName`

Pointer to a Unicode string that specifies the friendly (display) name of the peer issuing the invitation.

### `pwzSubjectFriendlyName`

Pointer to a Unicode string that specifies the friendly (display) name of the peer that receives the invitation.

### `ftValidityStart`

Specifies a UTC **FILETIME** value that indicates when the invitation becomes valid.

### `ftValidityEnd`

Specifies a UTC **FILETIME** value that indicates when the invitation becomes invalid.

### `cRoles`

Specifies the number of role GUIDs present in **pRoles**.

### `pRoles`

Pointer to a list of GUIDs that specifies the combined set of available roles. The available roles are as follows.

| Value | Meaning |
| --- | --- |
| **PEER_GROUP_ROLE_ADMIN** | This role can issue invitations, renew memberships, modify peer group properties, publish and update records, and renew the GMC of other administrators. |
| **PEER_GROUP_ROLE_MEMBER** | The role can publish records to the peer group database. |

### `cClassifiers`

Unsigned integer value that contains the number of string values listed in **ppwzClassifiers**. This field is reserved for future use.

### `ppwzClassifiers`

List of pointers to Unicode strings. This field is reserved for future use.

### `pSubjectPublicKey`

Pointer to a **CERT_PUBLIC_KEY_INFO** structure that contains the recipient's returned public key and the encryption algorithm type it uses.

### `authScheme`

**Windows Vista or later.** The [PEER_GROUP_AUTHENTICATION_SCHEME](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_group_authentication_scheme) enumeration value that indicates the type of authentication used to validate the peer group invitee.

## See also

[PeerGroupParseInvitation](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupparseinvitation)