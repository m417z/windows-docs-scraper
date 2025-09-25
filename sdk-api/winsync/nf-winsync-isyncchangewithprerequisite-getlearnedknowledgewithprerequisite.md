# ISyncChangeWithPrerequisite::GetLearnedKnowledgeWithPrerequisite

## Description

Gets the knowledge that the destination replica learns when the destination provider applies this change, based on the prerequisite knowledge that is associated with the change.

## Parameters

### `pDestinationKnowledge` [in]

The knowledge of a change unit that is contained in this change is not added to the returned learned knowledge when *pDestinationKnowledge* contains the prerequisite knowledge for the change unit.

### `ppLearnedKnowledgeWithPrerequisite` [out]

The knowledge that the destination replica learns when the destination provider applies this change, based on the prerequisite knowledge that is associated with the change.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_OUTOFMEMORY** | There was not enough memory available to return the knowledge. |
| **E_POINTER** | Invalid pointer. |
| **SYNC_E_CHANGE_NEEDS_KNOWLEDGE** | This object does not contain prerequisite knowledge. |

## See also

[ISyncChangeWithPrerequisite Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncchangewithprerequisite)