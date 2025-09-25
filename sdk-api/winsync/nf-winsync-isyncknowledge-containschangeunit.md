# ISyncKnowledge::ContainsChangeUnit

## Description

Indicates whether the specified change unit change is known by this knowledge.

## Parameters

### `pbVersionOwnerReplicaId` [in]

The ID of the replica that originated the change unit change.

### `pbItemId` [in]

The ID of the item that contains the change unit to look up.

### `pbChangeUnitId` [in]

 The ID of the change unit to look up.

### `pSyncVersion` [in]

The version of the change unit change to look up.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The specified change unit change is contained in the knowledge. |
| **S_FALSE** | The specified change unit change is not contained in the knowledge. |
| **E_INVALIDARG** |  |

## See also

[ISyncKnowledge Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge)

[SYNC_VERSION Structure](https://learn.microsoft.com/windows/desktop/api/winsync/ns-winsync-sync_version)