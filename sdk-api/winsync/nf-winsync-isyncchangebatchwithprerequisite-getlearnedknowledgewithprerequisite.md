# ISyncChangeBatchWithPrerequisite::GetLearnedKnowledgeWithPrerequisite

## Description

Gets the knowledge that the destination replica learns when the destination provider applies all the changes in this change batch, based on the prerequisite knowledge of the change batch.

## Parameters

### `pDestinationKnowledge` [in]

A knowledge fragment is added to the returned learned knowledge only if *pDestinationKnowledge* contains the prerequisite knowledge for that fragment.

### `ppLearnedWithPrerequisiteKnowledge` [out]

The knowledge that the destination replica learns when the destination provider applies all the changes in this change batch, based on the prerequisite knowledge of the change batch.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |

## Remarks

The knowledge that is returned in *ppLearnedWithPrerequisiteKnowledge* is computed by calling the [ISyncKnowledge2::ProjectOntoKnowledgeWithPrerequisite](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-isyncknowledge2-projectontoknowledgewithprerequisite) method of the learned knowledge of the change batch, passing *pDestinationKnowledge* as the template knowledge.

## See also

[ISyncChangeBatchWithPrerequisite Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncchangebatchwithprerequisite)

[ISyncKnowledge Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge)

[ISyncKnowledge2 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge2)