# ISyncKnowledge::ContainsChange

## Description

Indicates whether the specified item change is known by this knowledge.

## Parameters

### `pbVersionOwnerReplicaId` [in]

The ID of the replica that originated the change.

### `pgidItemId` [in]

The ID of the item that changed.

### `pSyncVersion` [in]

The version of the change.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | The specified change is not contained in the knowledge. |
| **E_INVALIDARG** |  |

## See also

[ISyncKnowledge Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge)

[SYNC_VERSION Structure](https://learn.microsoft.com/windows/desktop/api/winsync/ns-winsync-sync_version)