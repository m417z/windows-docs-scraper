# IUpdateCollection::Copy

## Description

Creates a shallow read/write copy of the collection.

## Parameters

### `retval` [out]

A shallow read/write copy of the collection.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

This method can also return the following error codes.

| Return code | Description |
| --- | --- |
| **E_POINTER** | A parameter value is invalid or **NULL**. |
| **E_ACCESSDENIED** | This method cannot be called from a remote computer. |

## See also

[IUpdateCollection](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatecollection)