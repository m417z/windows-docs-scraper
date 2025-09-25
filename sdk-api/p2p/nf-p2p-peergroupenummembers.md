# PeerGroupEnumMembers function

## Description

The **PeerGroupEnumMembers** function creates an enumeration of available peer group members and the associated membership information.

## Parameters

### `hGroup` [in]

Handle to the peer group whose members are enumerated. This handle is returned by the [PeerGroupCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreate), [PeerGroupOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopen), or [PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin) function. This parameter is required.

### `dwFlags` [in]

Specifies the [PEER_MEMBER_FLAGS](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_member_flags) flags that indicate which types of members to include in the enumeration. If this value is set to zero, all members of the peer group are included.

| Value | Meaning |
| --- | --- |
| **PEER_MEMBER_PRESENT** | Enumerate all members of the current peer group that are online. |

### `pwzIdentity` [in]

Unicode string that contains the identity of a specific peer whose information is retrieved and returned in a one-item enumeration. If this parameter is **NULL**, all members of the current peer group are retrieved. This parameter is required.

### `phPeerEnum` [out]

Pointer to the enumeration that contains the returned list of peer group members. This handle is passed to
[PeerGetNextItem](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergetnextitem) to retrieve the items, with each item represented as a pointer to a [PEER_MEMBER](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_member) structure. When finished, [PeerEndEnumeration](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerendenumeration) is called to return the memory used by the enumeration. This parameter is required.

## Return value

Returns S_OK if the operation succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform the specified operation. |
| **PEER_E_INVALID_GROUP** | The handle to the peer group is invalid. |

Cryptography-specific errors can be returned from the [Microsoft RSA Base Provider](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-base-cryptographic-provider). These errors are prefixed with CRYPT_* and defined in Winerror.h.

## Remarks

The local node is always the very first item in the enumeration if *pwzIdentity* is **NULL**, and *dwFlags* is set to indicate that the local node is a member of the explicit subset.

By default, every member publishes membership information to the peer group. If [PEER_MEMBER_DATA_OPTIONAL](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_group_property_flags) is set on the [PEER_MEMBER](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_member) data for that peer, this information is only available when a peer performs an action within the group, for example, publishing a record, updating presence, or issuing a GMC.

## See also

[PeerEndEnumeration](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerendenumeration)

[PeerGetItemCount](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergetitemcount)

[PeerGetNextItem](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergetnextitem)