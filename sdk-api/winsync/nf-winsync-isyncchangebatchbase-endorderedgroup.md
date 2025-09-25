# ISyncChangeBatchBase::EndOrderedGroup

## Description

Closes a previously opened ordered group in the change batch.

## Parameters

### `pbUpperBound` [in]

The closed upper bound of item IDs for this ordered group. To specify an upper bound of infinity, use **NULL**.

### `pMadeWithKnowledge` [in]

The knowledge of the replica that made this group.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **SYNC_E_INVALID_OPERATION** | No group is open or an unordered group is open. |
| **SYNC_E_RANGE_OUT_OF_ORDER** | *pbUpperBound* is less than the ID of the last item that was added to the group. |
| **SYNC_E_CHANGE_BATCH_IS_READ_ONLY** | The object is an **ISyncFullEnumerationChangeBatch** object and a group has already been added to the batch. |

## See also

[ISyncChangeBatchBase Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncchangebatchbase)

[ISyncKnowledge Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge)