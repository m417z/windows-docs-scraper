# ISyncFullEnumerationChangeBatch::GetLearnedKnowledgeAfterRecoveryComplete

## Description

Gets the knowledge the destination replica will learn after it applies all the changes in the recovery synchronization.

## Parameters

### `ppLearnedKnowledgeAfterRecoveryComplete` [out]

Returns the knowledge that the destination replica will learn after it applies all the changes in the recovery synchronization.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **SYNC_E_INVALID_OPERATION** | No group was added to the batch, or a group was opened but not ended. |

## See also

[ISyncFullEnumerationChangeBatch Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncfullenumerationchangebatch)

[ISyncKnowledge Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge)