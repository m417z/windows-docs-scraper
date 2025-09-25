# ISyncFullEnumerationChange::GetLearnedKnowledgeAfterRecoveryComplete

## Description

Gets the knowledge the destination replica will learn after it applies the changes in the full enumeration.

## Parameters

### `ppLearnedKnowledge` [out]

The knowledge that the destination replica will learn after it applies this change during recovery synchronization.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **SYNC_E_CHANGE_NEEDS_KNOWLEDGE** | This change does not contain made-with knowledge. |
| **SYNC_E_INVALID_OPERATION** | Recovery synchronization is not in process. |

## See also

[ISyncFullEnumerationChange](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncfullenumerationchange)