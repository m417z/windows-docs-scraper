# IReplicaKeyMap::Serialize

## Description

Serializes the replica key map data to a byte array.

## Parameters

### `pbReplicaKeyMap` [in, out]

The byte array that receives the serialized data.

### `pcbReplicaKeyMap` [in, out]

Specifies the number of bytes in *pbReplicaKeyMap*. Returns the number of bytes required to serialize the replica key map data when *pbReplicaKeyMap* is too small, or returns the number of bytes written.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | A replica ID or replica key stored in the map is not valid. |
| **E_POINTER** | Invalid pointer. |
| **E_OUTOFMEMORY** |  |
| **HRESULT_FROM_WIN32(ERROR_MORE_DATA)** | *pbReplicaKeyMap* is too small. In this case, the required number of bytes is returned in *pcbReplicaKeyMap*. |

## See also

[IReplicaKeyMap Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-ireplicakeymap)