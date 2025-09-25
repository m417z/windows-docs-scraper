# IUpdateSession3::QueryHistory

## Description

Synchronously queries the computer for the history of update events. This method returns a pointer to an [IUpdateHistoryEntryCollection](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatehistoryentrycollection) interface that contains matching event records on the computer.

## Parameters

### `criteria` [in]

A string that specifies the search criteria.

### `startIndex` [in]

The index of the first event to retrieve.

### `count` [in]

The number of events to retrieve.

### `retval` [out]

A pointer to an [IUpdateHistoryEntryCollection](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatehistoryentrycollection) interface that contains the matching event records on the computer in descending chronological order.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

This method can also return the following error codes.

| Return code | Description |
| --- | --- |
| **E_POINTER** | A parameter value is invalid or **NULL**. |
| **WU_E_INVALID_CRITERIA** | There is an invalid search criteria. |

## Remarks

The collection of events that is returned is sorted by the date in descending order.

The string that is used for the *criteria* parameter must match the custom search language for **QueryHistory**. The string contains criteria that are evaluated to determine which history events to return.

Note that **QueryHistory** supports per-machine updates only.

For a complete description of search criteria syntax, see [Search](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatesearcher-search).

The following table identifies all the public support criteria, in the order of evaluation precedence. More criteria may be added to this list in the future.

| Criterion | Type | Allowed operators | Description |
| --- | --- | --- | --- |
| UpdateID | **string(UUID)** | **=** | Finds updates that have an [UpdateIdentity.UpdateID](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateidentity-get_updateid) of the specified value. <br><br>For example, "UpdateID='12345678-9abc-def0-1234-56789abcdef0'" finds updates for [UpdateIdentity.UpdateID](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateidentity-get_updateid) that equal 12345678-9abc-def0-1234-56789abcdef0. |

## See also

[IUpdateSession3](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatesession3)