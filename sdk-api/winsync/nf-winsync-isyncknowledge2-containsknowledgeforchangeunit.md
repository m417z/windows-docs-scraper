# ISyncKnowledge2::ContainsKnowledgeForChangeUnit

## Description

Indicates whether the specified knowledge of the specified change unit is known by this knowledge.

## Parameters

### `pKnowledge` [in]

The knowledge object that contains knowledge about *pbChangeUnitId*.

### `pbItemId` [in]

The ID of the item that contains the change unit to look up.

### `pbChangeUnitId` [in]

The ID of the change unit to look up.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | This object contains the knowledge known by *pKnowledge* about *pbChangeUnitId*. |
| **S_FALSE** | This object does not contain the knowledge known by *pKnowledge* about *pbChangeUnitId*. |
| **E_POINTER** | Invalid pointer. |
| **SYNC_E_ID_FORMAT_MISMATCH** | *pbChangeUnitId* is not of the format specified by the provider. |

## Remarks

Another way to obtain the same result is to pass *pbItemId* and *pbChangeUnitId* to the [ISyncKnowledge::ContainsChangeUnit](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-isyncknowledge-containschangeunit) method of *pKnowledge*, and then take the resulting projected knowledge and pass it to the [ISyncKnowledge::ContainsKnowledge](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-isyncknowledge-containsknowledge) method of this object.

## See also

[ISyncKnowledge Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge)

[ISyncKnowledge2 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge2)