# PEER_RECORD structure

## Description

The **PEER_RECORD** structure contains the record object that an application uses.

## Members

### `dwSize`

Specifies the size of a structure. Set the value to sizeof(**PEER_RECORD**).

### `type`

Specifies the type of record. The type is a **GUID** that an application must specify. The **GUID** represents a unique record type, for example, a chat record.

### `id`

Specifies the unique ID of a record. The Peer Infrastructure supplies this ID. This parameter is ignored in calls to [PeerGroupAddRecord](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupaddrecord). An application cannot modify this member.

### `dwVersion`

Specifies the version of a record that the Peer Infrastructure supplies when an application calls [PeerGraphAddRecord](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphaddrecord) or [PeerGraphUpdateRecord](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphupdaterecord). An application cannot modify this member.

### `dwFlags`

Specifies the flags that indicate special processing, which must be applied to a record. The following table identifies the valid values.

| Value | Description |
| --- | --- |
| **PEER_RECORD_FLAG_AUTOREFRESH** | Indicates that a record is automatically refreshed when it is ready to expire. |
| **PEER_RECORD_FLAG_DELETED** | Indicates that a record is marked as deleted. |

**Note** An application cannot set these flags.

### `pwzCreatorId`

Pointer to the unique ID of a record creator. This member is set to **NULL** for calls to [PeerGraphAddRecord](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphaddrecord) and [PeerGraphUpdateRecord](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphupdaterecord). An application cannot set this member.

### `pwzModifiedById`

Specifies the unique ID of the last person who changes a record. An application cannot set this member.

### `pwzAttributes`

Pointer to the set of attribute name and value pairs that are associated with a record. This member points to an XML string. Record attributes are specified as an XML string, and they must be consistent with the Peer Infrastructure record attribute schema. For a complete explanation of the XML schema, see [Record Attribute Schema](https://learn.microsoft.com/windows/desktop/P2PSdk/record-attribute-schema).

The Peer Infrastructure reserves several attribute names that a user cannot set. The following list identifies the reserved attribute names:

* **peerlastmodifiedby**
* **peercreatorid**
* **peerlastmodificationtime**
* **peerrecordid**
* **peerrecordtype**
* **peercreationtime**
* **peerlastmodificationtime**

### `ftCreation`

Specifies the Coordinated Universal Time (UTC) that a record is created. The Peer Infrastructure supplies this value, and the value is set to zero (0) in calls to [PeerGroupAddRecord](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupaddrecord). An application cannot set this member.

### `ftExpiration`

The UTC time that a record expires. This member is required. It can be updated to a time value greater than the originally specified time value, but it cannot be less than the originally specified value.

**Note** If **dwFlags** is set to **PEER_RECORD_FLAG_AUTOREFRESH**, do not set the value of **ftExpiration** to less than four (4) minutes. If this member is set to less than four (4) minutes, undefined behavior can occur.

### `ftLastModified`

The UTC time that a record is modified. The Peer Infrastructure supplies this value. Set this member to **NULL** when calling [PeerGraphAddRecord](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphaddrecord), [PeerGraphUpdateRecord](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphupdaterecord), [PeerGroupAddRecord](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupaddrecord), and [PeerGroupUpdateRecord](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupupdaterecord). An application cannot set this member.

### `securityData`

Specifies the security data contained in a [PEER_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_data) structure. The Graphing API uses this member, and provides the security provider with a place to store security data, for example, a signature. The Grouping API cannot modify this member.

### `data`

Specifies the actual data that this record contains.

## See also

[PEER_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_data)

[PFNPEER_SECURE_RECORD](https://learn.microsoft.com/windows/desktop/api/p2p/nc-p2p-pfnpeer_secure_record)

[PFNPEER_VALIDATE_RECORD](https://learn.microsoft.com/windows/desktop/api/p2p/nc-p2p-pfnpeer_validate_record)

[PeerGraphAddRecord](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphaddrecord)

[PeerGraphDeleteRecord](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphdeleterecord)

[PeerGraphGetRecord](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphgetrecord)

[PeerGraphUpdateRecord](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphupdaterecord)

[PeerGroupAddRecord](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupaddrecord)

[PeerGroupDeleteRecord](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupdeleterecord)

[PeerGroupGetRecord](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupgetrecord)

[PeerGroupUpdateRecord](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupupdaterecord)