# ISyncChangeBatchBase::GetPrerequisiteKnowledge

## Description

Gets the minimum knowledge that a destination provider is required to have to process this change batch.

## Parameters

### `ppPrerequisteKnowledge` [out]

Returns the minimum knowledge that a destination provider is required to have to process this change batch.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |

## See also

[ISyncChangeBatchBase Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncchangebatchbase)

[ISyncKnowledge Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge)