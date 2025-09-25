# ISyncChangeBatchBase::BeginOrderedGroup

## Description

Opens an ordered group in the change batch. This group is ordered by item ID.

## Parameters

### `pbLowerBound` [in]

The closed lower bound of item IDs for this ordered group. To specify a lower bound of zero, use **NULL**.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **SYNC_E_INVALID_OPERATION** | A group is already open or an empty group was previously added to the batch. |
| **SYNC_E_CHANGE_BATCH_IS_READ_ONLY** | The object is an **ISyncFullEnumerationChangeBatch** object and a group has already been added to the batch. |
| **SYNC_E_RANGE_OUT_OF_ORDER** | The object is an **ISyncFullEnumerationChangeBatch** object and *pbLowerBound* is greater than the lower bound ID that was used to create the batch. |

## Remarks

Item changes that are added to the change batch after this method is called are added to the open group. Item changes that are added to an ordered group must be added in increasing order by item ID.

Item changes cannot be added to the change batch until a group is opened.

## See also

[ISyncChangeBatchBase Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncchangebatchbase)