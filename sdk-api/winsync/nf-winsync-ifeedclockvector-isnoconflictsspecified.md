# IFeedClockVector::IsNoConflictsSpecified

## Description

Gets a value that indicates whether conflicts are preserved for the FeedSync item.

## Parameters

### `pfIsNoConflictsSpecified` [out]

TRUE if conflicts are not preserved for the item; otherwise, **FALSE**. This value corresponds to the **noconflicts** attribute of the FeedSync item.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |

## See also

[IFeedClockVector Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-ifeedclockvector)