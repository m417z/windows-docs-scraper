# ISyncKnowledge::ContainsKnowledge

## Description

Indicates whether the specified knowledge is known by this knowledge.

## Parameters

### `pKnowledge` [in]

The knowledge to look up.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | *pSyncKnowledge* is known. |
| **S_FALSE** | *pSyncKnowledge* is not known. |
| **E_INVALIDARG** |  |

## See also

[ISyncKnowledge Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge)