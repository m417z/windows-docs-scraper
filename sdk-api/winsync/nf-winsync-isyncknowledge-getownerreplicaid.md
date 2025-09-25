# ISyncKnowledge::GetOwnerReplicaId

## Description

Gets the ID of the replica that owns this knowledge.

## Parameters

### `pbReplicaId` [in, out]

Returns the ID of the replica that owns this knowledge.

### `pcbIdSize` [in, out]

Specifies the number of bytes in *pbReplicaId*. Returns the number of bytes required to retrieve the ID when *pbReplicaId* is too small, or returns the number of bytes written.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** |  |
| **HRESULT_FROM_WIN32(ERROR_MORE_DATA)** | *pbReplicaId* is too small. In this case, the required number of bytes is returned in *pcbIdSize*. |

## Remarks

Knowledge is valid only to the replica that owns it. To use knowledge from a replica that differs from the owning replica, the knowledge must first be converted by using [ISyncKnowledge::MapRemoteToLocal](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-isyncknowledge-mapremotetolocal).

## See also

[ISyncKnowledge Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge)