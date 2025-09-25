# ISyncKnowledge2::IntersectsWithKnowledge

## Description

Indicates whether the specified knowledge intersects with this knowledge.

## Parameters

### `pSyncKnowledge` [in]

The knowledge that is checked against this object to determine whether there is an intersection.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The specified knowledge intersects with this knowledge. |
| **S_FALSE** | The specified knowledge does not intersect with this knowledge. |
| **E_POINTER** | Invalid pointer. |

## See also

[ISyncKnowledge Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge)

[ISyncKnowledge2 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge2)