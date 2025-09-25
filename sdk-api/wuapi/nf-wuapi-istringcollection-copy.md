# IStringCollection::Copy

## Description

Creates a deep read/write copy of the collection.

## Parameters

### `retval` [out]

A deep read/write copy of the collection.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

This method can also return the following error codes.

| Return code | Description |
| --- | --- |
| **E_POINTER** | A parameter value is invalid or **NULL**. |

## See also

[IStringCollection](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-istringcollection)