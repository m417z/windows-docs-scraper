# ISyncChangeBatchAdvanced::GetBatchLevelKnowledgeShouldBeApplied

## Description

Gets a value that indicates whether the learned knowledge for the batch must be saved after the batch is applied to the destination replica.

## Parameters

### `pfBatchKnowledgeShouldBeApplied` [out]

Returns a value that indicates whether the learned knowledge for the batch must be saved after the batch is applied to the destination replica.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **SYNC_E_BATCH_NEEDS_KNOWLEDGE** | The change batch contains no changes and no knowledge. |

## Remarks

Typically, the destination provider saves the learned knowledge for each item change as it is applied to the destination replica. The value that is returned by **GetBatchLevelKnowledgeShouldBeApplied** indicates whether it is also necessary to save the learned knowledge of the change batch after the entire change batch has been applied. The learned knowledge of the change batch can be obtained by calling [ISyncChangeBatchBase::GetLearnedKnowledge](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-isyncchangebatchbase-getlearnedknowledge).

## See also

[ISyncChangeBatchAdvanced Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncchangebatchadvanced)

[ISyncChangeBatchBase Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncchangebatchbase)