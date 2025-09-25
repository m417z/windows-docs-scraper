# ISyncKnowledge2::ContainsKnowledgeForItem

## Description

Indicates whether the specified knowledge of the specified item is known by this knowledge.

## Parameters

### `pKnowledge` [in]

The knowledge object that contains knowledge about *pbItemId*.

### `pbItemId` [in]

The ID of the item to look up.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | This object contains the knowledge known by *pKnowledge* about *pbItemId*. |
| **S_FALSE** | This object does not contain the knowledge known by *pKnowledge* about *pbItemId*. |
| **E_POINTER** | Invalid pointer. |
| **SYNC_E_ID_FORMAT_MISMATCH** | *pbItemId* is not of the format specified by the provider. |

## Remarks

Another way to obtain the same result is to pass *pbItemId* to the [ISyncKnowledge::ProjectOntoItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-isyncknowledge-projectontoitem) method of *pKnowledge*, and then take the resulting projected knowledge and pass it to the [ISyncKnowledge::ContainsKnowledge](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-isyncknowledge-containsknowledge) method of this object.

## See also

[ISyncKnowledge Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge)

[ISyncKnowledge2 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge2)