# IUpdateSearcher::GetTotalHistoryCount

## Description

Returns the number of update events on the computer.

## Parameters

### `retval` [out]

The number of update events on the computer.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

This method can also return the following error codes.

| Return code | Description |
| --- | --- |
| **E_POINTER** | A parameter value is invalid or **NULL**. |

## See also

[IUpdateSearcher](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatesearcher)