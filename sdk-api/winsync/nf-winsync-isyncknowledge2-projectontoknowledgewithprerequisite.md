# ISyncKnowledge2::ProjectOntoKnowledgeWithPrerequisite

## Description

Returns knowledge about the knowledge fragments that are specified by the template knowledge, when the template knowledge contains the prerequisite knowledge for the specified fragments.

## Parameters

### `pPrerequisiteKnowledge` [in]

Specifies the knowledge that *pTemplateKnowledge* must contain for knowledge to be added to *ppProjectedKnowledge*.

### `pTemplateKnowledge` [in]

 Specifies the set of knowledge fragments to be added to *ppProjectedKnowledge*.

### `ppProjectedKnowledge` [out]

 A knowledge object that contains the knowledge fragments that are specified by *pTemplateKnowledge* when *pTemplateKnowledge* contains the knowledge that is contained in *pPrerequisiteKnowledge* for the specified fragments.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **SYNC_E_ID_FORMAT_MISMATCH** | The ID format schema that is contained in *pPrerequisiteKnowledge* or *pTemplateKnowledge* differs from the ID format schema of this object. |

## Remarks

To calculate the knowledge that is returned in *ppProjectedKnowledge*, this method enumerates the knowledge fragments that are contained in *pTemplateKnowledge*. For each knowledge fragment in *pTemplateKnowledge*, this method checks whether the knowledge known by *pPrerequisiteKnowledge* about the fragment is contained in *pTemplateKnowledge*. If the prerequisite knowledge that is known about a fragment is contained by *pTemplateKnowledge*, the knowledge that is known about that fragment by this object is added to *ppProjectedKnowledge*. If the prerequisite knowledge that is known about a fragment is not contained by *pTemplateKnowledge*, then *ppProjectedKnowledge* contains no knowledge about that fragment.

## See also

[ISyncKnowledge Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge)

[ISyncKnowledge2 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge2)