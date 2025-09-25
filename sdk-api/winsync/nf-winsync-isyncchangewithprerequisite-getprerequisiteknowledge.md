# ISyncChangeWithPrerequisite::GetPrerequisiteKnowledge

## Description

Gets the minimum knowledge that a destination provider is required to have to process this change.

## Parameters

### `ppPrerequisiteKnowledge` [out]

The minimum knowledge that a destination provider is required to have to process this change.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | This object contains no prerequisite knowledge. |
| **E_POINTER** | Invalid pointer. |

## See also

[ISyncChangeWithPrerequisite Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncchangewithprerequisite)