# ISyncChangeBatchBase::GetLearnedKnowledge

## Description

Gets the knowledge that the destination replica learns when the destination provider applies all the changes in this change batch.

## Parameters

### `ppLearnedKnowledge` [out]

Returns the knowledge that a replica will learn when a provider applies all the changes in this change batch to the replica. This knowledge is valid only when the current knowledge of the replica contains the prerequisite knowledge of the change batch. The prerequisite knowledge can be obtained by calling [ISyncChangeBatchBase::GetPrerequisiteKnowledge](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-isyncchangebatchbase-getprerequisiteknowledge).

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **SYNC_E_INVALID_OPERATION** | The last group added to the batch was not ended. |

## Remarks

**GetLearnedKnowledge** can be used by a provider that uses a custom change applier.

## See also

[ISyncChangeBatchBase Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncchangebatchbase)

[ISyncKnowledge Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge)