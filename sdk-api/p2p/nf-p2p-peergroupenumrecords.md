# PeerGroupEnumRecords function

## Description

The **PeerGroupEnumRecords** function creates an enumeration of peer group records.

## Parameters

### `hGroup` [in]

Handle to the peer group whose records are enumerated. This handle is returned by the [PeerGroupCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreate), [PeerGroupOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopen), or [PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin) function. This parameter is required.

### `pRecordType` [in]

Pointer to a **GUID** value that uniquely identifies a specific record type. If this parameter is **NULL**, all records are returned.

### `phPeerEnum` [out]

Pointer to the enumeration that contains the returned list of records. This handle is passed to
[PeerGetNextItem](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergetnextitem) to retrieve the items, with each item represented as a pointer to a [PEER_RECORD](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_record) structure. When finished, [PeerEndEnumeration](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerendenumeration) is called to return the memory used by the enumeration. This parameter is required.

## Return value

Returns **S_OK** if the operation succeeds. Otherwise, the function returns one of the following values.

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

[PeerGroupGetRecord](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupgetrecord)