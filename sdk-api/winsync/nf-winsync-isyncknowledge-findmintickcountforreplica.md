# ISyncKnowledge::FindMinTickCountForReplica

## Description

Finds the minimum tick count in the knowledge for the specified replica.

## Parameters

### `pbReplicaId` [in]

The ID of the replica to look up.

### `pullReplicaTickCount` [out]

Returns the minimum tick count in the knowledge for *pbReplicaId*.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** |  |

## See also

[ISyncKnowledge Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge)