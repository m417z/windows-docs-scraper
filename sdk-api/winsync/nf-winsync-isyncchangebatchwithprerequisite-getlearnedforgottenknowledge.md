# ISyncChangeBatchWithPrerequisite::GetLearnedForgottenKnowledge

## Description

Gets the forgotten knowledge that the destination replica learns when the destination provider applies all the changes in this change batch during recovery synchronization.

## Parameters

### `ppLearnedForgottenKnowledge` [out]

Returns the forgotten knowledge that the destination replica learns when the destination provider applies all the changes in this change batch during recovery synchronization.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **SYNC_E_INVALID_OPERATION** | The change batch object is not an [ISyncFullEnumerationChangeBatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncfullenumerationchangebatch) object. |

## Remarks

The knowledge returned in *ppLearnedForgottenKnowledge* is the source forgotten knowledge of the change batch projected onto the range contained in the change batch.

## See also

[IForgottenKnowledge Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-iforgottenknowledge)

[ISyncChangeBatchWithPrerequisite Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncchangebatchwithprerequisite)