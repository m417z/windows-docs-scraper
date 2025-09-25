# PeerGroupEnumConnections function

## Description

The **PeerGroupEnumConnections** function creates an enumeration of connections currently active on the peer.

## Parameters

### `hGroup` [in]

Handle to the group that contains the connections to be enumerated. This handle is returned by the [PeerGroupCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreate), [PeerGroupOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopen), or [PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin) function. This parameter is required.

### `dwFlags` [in]

Specifies the flags that indicate the type of connection to enumerate. Valid values are specified by [PEER_CONNECTION_FLAGS](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_connection_flags).

### `phPeerEnum` [out]

Pointer to the enumeration that contains the returned list of active connections. This handle is passed to
[PeerGetNextItem](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergetnextitem) to retrieve the items, with each item represented as a pointer to a [PEER_CONNECTION_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_connection_info) structure. When finished, [PeerEndEnumeration](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerendenumeration) is called to return the memory used by the enumeration. This parameter is required.

## Return value

Returns S_OK if the operation succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform the specified operation. |
| **PEER_E_INVALID_GROUP** | The handle to the peer group is invalid. |

Cryptography-specific errors can be returned from the [Microsoft RSA Base Provider](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-base-cryptographic-provider). These errors are prefixed with CRYPT_* and defined in Winerror.h.

## See also

[PeerEndEnumeration](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerendenumeration)

[PeerGetItemCount](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergetitemcount)

[PeerGetNextItem](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergetnextitem)