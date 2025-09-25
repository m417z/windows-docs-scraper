# ISyncKnowledge2::SerializeWithOptions

## Description

Serializes the knowledge object data to a byte array based on the specified version and serialization options.

## Parameters

### `targetFormatVersion` [in]

The serialized knowledge is compatible with this version.

### `dwFlags` [in]

Options that specify additional information about how to serialize the object. Must be zero or a combination of the values specified by the **SYNC_SERIALIZE** flags (see Remarks). When zero is specified, the replica key map is not included as part of the serialized knowledge data.

### `pbBuffer` [in, out]

The serialized knowledge object data is serialized to this buffer.

### `pdwSerializedSize` [in, out]

Specifies the number of bytes in *pBuffer*. Returns either the number of bytes that are required to serialize the knowledge data when *pBuffer* is too small, or the number of bytes written.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **HRESULT_FROM_WIN32(ERROR_MORE_DATA)** | *pBuffer* is too small. In this situation, the required number of bytes is returned in *pdwSerializedSize*. |
| **SYNC_E_INVALID_VERSION** | The value of *targetFormatVersion* is higher than the version of the object, or the object contains elements that are not compatible with *targetFormatVersion*. |

## Remarks

**Note** The **SYNC_SERIALIZE** flags are defined as follows:`#define SYNC_SERIALIZE_REPLICA_KEY_MAP 0x00000001`

The value **SYNC_SERIALIZE_REPLICA_KEY_MAP** indicates that the replica key map is included in the serialized knowledge data.

 When **SYNC_SERIALIZE_REPLICA_KEY_MAP** is specified for flags, the **IReplicaKeyMap** object is serialized along with the knowledge data. When this flag is not specified, the **IReplicaKeyMap** data must be stored in some other way so that the knowledge object can be deserialized.

The value of *targetFormatVersion* determines the format of the serialized knowledge data and refers to the version of [Microsoft Sync Framework](https://www.microsoft.com/downloads/details.aspx?familyid=A3EE7BC5-A823-4FB4-B152-9E8CE9D5546F&displaylang=en). For an overview of what is involved in building synchronization providers using [Microsoft Sync Framework](https://www.microsoft.com/downloads/details.aspx?familyid=A3EE7BC5-A823-4FB4-B152-9E8CE9D5546F&displaylang=en), see [Options for Building a Synchronization Provider](https://learn.microsoft.com/previous-versions/windows/desktop/winsync/options-for-building-a-synchronization-provider).

## See also

[IReplicaKeyMap Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-ireplicakeymap)

[ISyncKnowledge Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge)

[ISyncKnowledge2 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge2)

[Options for Building a Synchronization Provider](https://learn.microsoft.com/previous-versions/windows/desktop/winsync/options-for-building-a-synchronization-provider)