# IUpdateSearcher::QueryHistory

## Description

Synchronously queries the computer for the history of the update events.

## Parameters

### `startIndex` [in]

The index of the first event to retrieve.

### `count` [in]

The number of events to retrieve.

### `retval` [out]

A pointer to an [IUpdateHistoryEntryCollection](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatehistoryentrycollection) interface that contains matching event records on the computer in descending chronological order.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

This method can also return the following error codes.

| Return code | Description |
| --- | --- |
| **E_POINTER** | A parameter value is invalid or **NULL**. |
| **WU_E_INVALIDINDEX** | An index is invalid. |

## Remarks

This method returns **WU_E_INVALIDINDEX** if the *startIndex* parameter is less than 0 (zero) or if the *Count* parameter is less than or equal to 0 (zero).

## See also

[IUpdateSearcher](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatesearcher)