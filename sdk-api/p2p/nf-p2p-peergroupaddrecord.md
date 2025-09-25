# PeerGroupAddRecord function

## Description

The **PeerGroupAddRecord** function adds a new record to the peer group, which is propagated to all participating peers.

## Parameters

### `hGroup` [in]

Handle to the peer group. This handle is returned by the [PeerGroupCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreate), [PeerGroupOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopen), or [PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin) function. This parameter is required.

### `pRecord` [in]

Pointer to a [PEER_RECORD](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_record) structure that is added to the peer group specified in *hGroup*. This parameter is required.

The following members in [PEER_RECORD](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_record) must be populated.

* **dwSize**
* **type**
* **ftExpiration**

**ftExpiration** must be expressed as peer time (see [PeerGroupUniversalTimeToPeerTime](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupuniversaltimetopeertime)).

The following members are ignored and overwritten if populated.

* **id**
* **pwzCreatorId**
* **pwzLastModifiedById**
* **ftCreation**
* **ftLastModified**
* **securityData**

The remaining fields are optional.

### `pRecordId` [out]

Pointer to a GUID that identifies the record. This parameter is required.

## Return value

Returns S_OK if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform the specified operation. |
| **PEER_E_GROUP_NOT_READY** | The peer group is not in a state where records can be added. For example, [PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin) is called, but synchronization with the peer group database has not completed. |
| **PEER_E_INVALID_ATTRIBUTES** | The XML string that contains the record attributes in the **pwzAttributes** member of the [PEER_RECORD](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_record) structure does not comply with the [schema specification](https://learn.microsoft.com/windows/desktop/P2PSdk/record-attribute-schema). |
| **PEER_E_INVALID_GROUP** | The handle to the peer group is invalid. |
| **PEER_E_INVALID_PEER_NAME** | The supplied peer name is invalid. |
| **PEER_E_INVALID_RECORD** | One or more fields in [PEER_RECORD](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_record) are invalid. |
| **PEER_E_MAX_RECORD_SIZE_EXCEEDED** | The record has exceeded the maximum size allowed by the peer group properties. |
| **PEER_E_NOT_AUTHORIZED** | The identity is not authorized to publish a record of that type. |

Cryptography-specific errors can be returned from the [Microsoft RSA Base Provider](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-base-cryptographic-provider). These errors are prefixed with CRYPT_* and defined in Winerror.h.

## See also

 [PEER_RECORD](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_record)

[PeerGroupDeleteRecord](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupdeleterecord)

[PeerGroupEnumRecords](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupenumrecords)

[PeerGroupUpdateRecord](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupupdaterecord)