# IUpdateSearcher::EscapeString

## Description

Converts a string into a string that can be used as a literal value in a search criteria string.

## Parameters

### `unescaped` [in]

A string to be escaped.

### `retval` [out]

The resulting escaped string.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

This method can also return the following error codes.

| Return code | Description |
| --- | --- |
| **E_POINTER** | A parameter value is invalid or **NULL**. |

## See also

[IUpdateSearcher](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatesearcher)