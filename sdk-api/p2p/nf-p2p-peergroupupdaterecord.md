# PeerGroupUpdateRecord function

## Description

The **PeerGroupUpdateRecord** function updates a record within a specific peer group.

## Parameters

### `hGroup` [in]

Handle to the peer group whose record is updated. This handle is returned by the [PeerGroupCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreate), [PeerGroupOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopen), or [PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin) function. This parameter is required.

### `pRecord` [in]

Pointer to a [PEER_RECORD](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_record) structure that contains the updated record for *hGroup*. This parameter is required.

The following members in [PEER_RECORD](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_record) can be updated.

* **pwzAttributes**
* **ftExpiration**
* **data**

The following members in [PEER_RECORD](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_record) must be present, but cannot be changed.

* **dwSize**
* **id**
* **type**
* **dwFlags**

The following members are ignored if populated.

* **dwVersion**
* **pwzCreatorId**
* **pwzModifiedById**
* **ftCreation**
* **ftLastModified**
* **securityData**

The members that remain are optional.

## Return value

Returns **S_OK** if the operation succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the specified parameters is invalid. |
| **PEER_E_GROUP_NOT_READY** | The peer group is not in a state where a record can be updated, for example, [PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin) has been called, but synchronization with the peer group database is not complete. |
| **PEER_E_INVALID_GROUP** | The handle to the peer group is invalid. |
| **PEER_E_NOT_AUTHORIZED** | The current peer identity does not have the authorization to delete the record. In this case, the peer identity is not the creator of the record. |
| **PEER_E_RECORD_NOT_FOUND** | The record cannot be located in the data store. |

Cryptography-specific errors can be returned from the [Microsoft RSA Base Provider](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-base-cryptographic-provider). These errors are prefixed with CRYPT_* and defined in Winerror.h.

## See also

 [PEER_RECORD](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_record)

[PeerGroupAddRecord](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupaddrecord)

[PeerGroupCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreate)

[PeerGroupDeleteRecord](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupdeleterecord)

[PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin)

[PeerGroupOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopen)