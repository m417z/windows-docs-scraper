# PeerGroupGetRecord function

## Description

The **PeerGroupGetRecord** function retrieves a specific group record.

## Parameters

### `hGroup` [in]

Handle to a group that contains a specific record. This handle is returned by the [PeerGroupCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreate), [PeerGroupOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopen), or [PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin) function. This parameter is required.

### `pRecordId` [in]

Specifies the GUID value that uniquely identifies a required record within a peer group. This parameter is required.

### `ppRecord` [out]

Pointer to the address of a [PEER_RECORD](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_record) structure that contains a returned record. This structure is freed by passing its pointer to [PeerFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerfreedata). This parameter is required.

## Return value

Returns **S_OK** if the operation succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform the specified operation. |
| **PEER_E_GROUP_NOT_READY** | The peer group is not in a state where group records can be retrieved. For example, [PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin) is called, but synchronization with the peer group database has not completed. |
| **PEER_E_INVALID_GROUP** | The handle to a peer group is invalid. |
| **PEER_E_RECORD_NOT_FOUND** | A record that matches the supplied ID cannot be found in a peer group database. |

Cryptography-specific errors can be returned from the [Microsoft RSA Base Provider](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-base-cryptographic-provider). These errors are prefixed with CRYPT_* and defined in Winerror.h.

## See also

 [PEER_RECORD](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_record)

[PeerFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerfreedata)

[PeerGroupCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreate)

[PeerGroupDeleteRecord](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupdeleterecord)

[PeerGroupEnumRecords](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupenumrecords)

[PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin)

[PeerGroupOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopen)