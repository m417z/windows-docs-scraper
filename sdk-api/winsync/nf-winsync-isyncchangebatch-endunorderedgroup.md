# ISyncChangeBatch::EndUnorderedGroup

## Description

Closes a previously opened unordered group in the change batch.

## Parameters

### `pMadeWithKnowledge` [in]

The made-with knowledge for the changes in the group. Typically, this is the knowledge of the replica that made this group.

### `fAllChangesForKnowledge` [in]

**TRUE** when all the changes contained in *pMadeWithKnowledge* are included in this change batch; otherwise, **FALSE**.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **SYNC_E_INVALID_OPERATION** | No group is open or an ordered group is open. |
| **SYNC_E_CHANGE_BATCH_IS_READ_ONLY** |  |

## See also

[ISyncChangeBatch Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncchangebatch)

[ISyncKnowledge Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge)