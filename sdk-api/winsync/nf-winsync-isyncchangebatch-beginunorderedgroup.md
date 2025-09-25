# ISyncChangeBatch::BeginUnorderedGroup

## Description

Opens an unordered group in the change batch. Item changes in this group can be in any order.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **SYNC_E_INVALID_OPERATION** | A group is already open or an empty group was previously added to the batch. |
| **SYNC_E_CHANGE_BATCH_IS_READ_ONLY** |  |

## Remarks

Item changes that are added to the change batch after this method is called are added to the open group.

Item changes cannot be added to the change batch until a group is opened.

## See also

[ISyncChangeBatch Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncchangebatch)