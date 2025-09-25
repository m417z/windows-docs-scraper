# ISyncKnowledge2::Complement

## Description

Returns the knowledge that is contained in this object but that is not contained in the specified knowledge.

## Parameters

### `pSyncKnowledge` [in]

The knowledge to remove from this object to calculate the result of the complement operation.

### `ppComplementedKnowledge` [out]

The knowledge that is contained in this object but that is not contained in the specified knowledge.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |

## Remarks

The complement operation can be thought of conceptually as a subtraction operation. The specified knowledge is subtracted from the knowledge in this object, and the result is returned.

## See also

[ISyncKnowledge Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge)

[ISyncKnowledge2 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge2)