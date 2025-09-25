# PeerGroupDeleteRecord function

## Description

The **PeerGroupDeleteRecord** function deletes a record from a peer group. The creator, as well as any other member in an administrative role may delete a specific record.

## Parameters

### `hGroup` [in]

Handle to the peer group that contains the record. This handle is returned by the [PeerGroupCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreate), [PeerGroupOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopen), or [PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin) function. This parameter is required.

### `pRecordId` [in]

Specifies the GUID value that uniquely identifies the record to be deleted. This parameter is required.

## Return value

Returns S_OK if the operation succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **PEER_E_GROUP_NOT_READY** | The peer group is not in a state where records can be deleted. For example, [PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin) is called, but synchronization with the peer group database has not completed. |
| **PEER_E_INVALID_GROUP** | The handle to the peer group is invalid. |
| **PEER_E_NOT_AUTHORIZED** | The current identity does not have the authorization to delete the record. In this case, the identity is not the creator or a member in an administrative role may delete a specific record. |
| **PEER_E_RECORD_NOT_FOUND** | The record cannot be located in the data store. |

Cryptography-specific errors can be returned from the [Microsoft RSA Base Provider](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-base-cryptographic-provider). These errors are prefixed with CRYPT_* and defined in Winerror.h.

## See also

[PeerGroupAddRecord](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupaddrecord)

[PeerGroupCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreate)

[PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin)

[PeerGroupOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopen)

[PeerGroupUpdateRecord](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupupdaterecord)