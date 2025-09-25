# PEER_GROUP_PROPERTIES structure

## Description

The **PEER_GROUP_PROPERTIES** structure contains data about the membership policy of a peer group.

## Members

### `dwSize`

Size of the structure, in bytes.

### `dwFlags`

[PEER_GROUP_PROPERTY_FLAGS](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_group_property_flags) flags that describe the behavior of a peer group. The default value is zero (0), which indicates that flags are not set.

### `pwzCloud`

Specifies the name of the Peer Name Resolution Protocol (PNRP) cloud that a peer group participates in. The default value is "global", if this member is **NULL**.

### `pwzClassifier`

Specifies the classifier used to identify the authority of a peer group peer name for registration or resolution within a PNRP cloud. The maximum size of this field is 149 Unicode characters. This member can be **NULL**.

### `pwzGroupPeerName`

Specifies the name of a peer group that is registered with the PNRP service. The maximum size of this field is 137 Unicode characters.

### `pwzCreatorPeerName`

Specifies the peer name associated with the Peer group creator. The maximum size of this field is 137 Unicode characters. If this structure member is **NULL**, the implementation uses the identity obtained from [PeerIdentityGetDefault](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peeridentitygetdefault).

### `pwzFriendlyName`

Specifies the friendly (display) name of a peer group. The maximum size of this field is 255 characters.

### `pwzComment`

Contains a comment used to describe a peer group. The maximum size of this field is 255 characters.

### `ulMemberDataLifetime`

Specifies the lifetime, in seconds, of peer group member data ([PEER_MEMBER](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_member)). The minimum value for this field is 8 hours, and the maximum is 10 years. The default value is 2,419,200 seconds, or 28 days.

If this value is set to zero (0), member data has the maximum allowable lifetime, which is the time remaining in the lifetime of the administrator who issues the credentials for a member.

### `ulPresenceLifetime`

Specifies the lifetime, in seconds, of presence information published to a peer group. The default value is 300 seconds. Do not set the value of **ulPresenceLifetime** to less than 300 seconds. If this member is set to less than the 300–second default value, then undefined behavior can occur.

### `dwAuthenticationSchemes`

**Windows Vista or later.** Logical OR of [PEER_GROUP_AUTHENTICATION_SCHEME](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_group_authentication_scheme) enumeration values that indicate the types of authentication supported by the peer group.

### `pwzGroupPassword`

**Windows Vista or later.** Pointer to a Unicode string that contains the password used to authenticate peers attempting to join the peer group.

### `groupPasswordRole`

**Windows Vista or later.** GUID value that indicates the peer group role for which the password is required for authentication.

## See also

[PeerGroupCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreate)

[PeerGroupGetProperties](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupgetproperties)

[PeerGroupSetProperties](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupsetproperties)