# PEER_MEMBER structure

## Description

The **PEER_MEMBER** structure contains information that describes a member of a peer group.

## Members

### `dwSize`

Specifies the size of this structure, in bytes.

### `dwFlags`

PEER_MEMBER_FLAGS enumeration value that specifies the state of the member.

| Value | Meaning |
| --- | --- |
| **PEER_MEMBER_PRESENT** | The member is present in the peer group. |

### `pwzIdentity`

Pointer to a Unicode string that specifies the peer name of the member.

### `pwzAttributes`

Pointer to a unicode string that specifies the attributes of the member. The format of this string is defined by the application.

### `ullNodeId`

Unsigned 64-bit integer that contains the node ID. The same peer can have several node IDs, each identifying a different node that participates in a different peer group.

### `cAddresses`

Specifies the number of IP addresses listed in **pAddress**.

### `pAddresses`

Pointer to a list of [PEER_ADDRESS](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_address) structures used by the member.

### `pCredentialInfo`

Pointer to a [PEER_CREDENTIAL_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_credential_info) structure that contains information about the security credentials of a member.

## See also

[PEER_ADDRESS](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_address)

[PEER_CREDENTIAL_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_credential_info)