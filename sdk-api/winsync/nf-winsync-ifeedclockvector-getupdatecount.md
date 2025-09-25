# IFeedClockVector::GetUpdateCount

## Description

Gets the number of updates that have been made to the FeedSync item.

## Parameters

### `pdwUpdateCount` [out]

Returns the number of updates that have been made to the FeedSync item. This value corresponds to the **updates** attribute of the FeedSync item.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |

## See also

[IFeedClockVector Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-ifeedclockvector)