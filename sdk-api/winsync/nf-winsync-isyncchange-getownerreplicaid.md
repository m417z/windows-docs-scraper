# ISyncChange::GetOwnerReplicaId

## Description

Gets the ID of the replica that originated this change.

## Parameters

### `pbReplicaId` [in, out]

Returns the ID of the replica that originated this change.

### `pcbIdSize` [in, out]

Specifies the number of bytes in *pbReplicaId*. Returns the number of bytes required to retrieve the ID when *pbReplicaId* is too small, or returns the number of bytes written.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **HRESULT_FROM_WIN32(ERROR_MORE_DATA)** | *pbReplicaId* is too small. In this case, the required number of bytes is returned in *pcbIdSize*. |

## See also

[ISyncChange Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncchange)