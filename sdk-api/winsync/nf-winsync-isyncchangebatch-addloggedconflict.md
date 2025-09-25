# ISyncChangeBatch::AddLoggedConflict

## Description

Adds metadata that represents a conflict to the change batch.

## Parameters

### `pbOwnerReplicaId` [in]

The ID of the replica that made the change in conflict.

### `pbItemId` [in]

The ID of the item.

### `pChangeVersion` [in]

The version of the change.

### `pCreationVersion` [in]

The creation version of the item.

### `dwFlags` [in]

Flags that specify the state of the item change. For the SYNC_CHANGE_FLAG values, see the Remarks section of the [ISyncChange::GetFlags](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-isyncchange-getflags) method.

### `dwWorkForChange` [in]

The work estimate for the change. This value is used during change application to report completed work to the application.

### `pConflictKnowledge` [in]

The conflict knowledge that was saved when the conflict was logged.

### `ppChangeBuilder` [out]

Returns an object that can be used to add change unit information to the change.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** |  |
| **SYNC_E_CHANGE_BATCH_IS_READ_ONLY** |  |

## Remarks

Conflicts that are added to the change batch are not added to a group. A group does not have to be opened to add conflicts to the change batch.

## See also

[ISyncChange Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge)

[ISyncChangeBatch Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncchangebatch)

[ISyncChangeBuilder Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncchangebuilder)

[ISyncKnowledge Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge)