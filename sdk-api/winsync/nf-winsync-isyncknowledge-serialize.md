# ISyncKnowledge::Serialize

## Description

Serializes the knowledge object data to a byte array.

## Parameters

### `fSerializeReplicaKeyMap` [in]

**TRUE** to serialize the **IReplicaKeyMap** object that is contained in the knowledge; otherwise, **FALSE**.

### `pbKnowledge` [in, out]

The byte array that receives the serialized knowledge data.

### `pcbKnowledge` [in, out]

Specifies the number of bytes in *pbKnowledge*. Returns the number of bytes required to serialize the replica key map data when *pbKnowledge* is too small, or returns the number of bytes written.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **E_INVALIDARG** |  |
| **E_OUTOFMEMORY** |  |
| **HRESULT_FROM_WIN32(ERROR_MORE_DATA)** | *pbKnowledge* is too small. In this case, the required number of bytes is returned in *pbKnowledge*. |

## See also

[IReplicaKeyMap Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-ireplicakeymap)

[ISyncKnowledge Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge)