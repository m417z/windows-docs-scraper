# ISyncFullEnumerationChange::GetLearnedForgottenKnowledge

## Description

Gets the forgotten knowledge that the destination replica learns when the destination provider applies this change during recovery synchronization.

## Parameters

### `ppLearnedForgottenKnowledge` [out]

The forgotten knowledge that the destination replica learns when the destination provider applies this change during recovery synchronization.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | This object does not contain source forgotten knowledge. In this case, *ppLearnedForgottenKnowledge* will return **NULL**. |
| **E_POINTER** | Invalid pointer. |

## Remarks

The knowledge returned in *ppLearnedForgottenKnowledge* is the source forgotten knowledge of the change batch projected onto the item that is associated with this change.

## See also

[ISyncFullEnumerationChange Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncfullenumerationchange)