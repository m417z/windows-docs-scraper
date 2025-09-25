# IFeedClockVectorElement::GetSyncTime

## Description

Gets a [SYNC_TIME](https://learn.microsoft.com/windows/desktop/api/winsync/ns-winsync-sync_time) value that corresponds to the **when** value for the item.

## Parameters

### `pSyncTime` [out]

Returns a [SYNC_TIME](https://learn.microsoft.com/windows/desktop/api/winsync/ns-winsync-sync_time) value that corresponds to the **when** value for the item.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** |  |

## Remarks

The [SYNC_TIME](https://learn.microsoft.com/windows/desktop/api/winsync/ns-winsync-sync_time) structure is a packed date-and-time value that can store years between 1601 and 67136 and times that are accurate to the millisecond.

## See also

[IFeedClockVectorElement Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-ifeedclockvectorelement)

[SYNC_TIME Structure](https://learn.microsoft.com/windows/desktop/api/winsync/ns-winsync-sync_time)