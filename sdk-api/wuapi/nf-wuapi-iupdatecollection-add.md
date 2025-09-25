# IUpdateCollection::Add

## Description

Adds an item to the collection.

## Parameters

### `value` [in]

An [IUpdate](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdate) interface to be added to the collection.

### `retval` [out]

The index of the added interface in the collection.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

This method can also return the following error codes.

| Return code | Description |
| --- | --- |
| **E_POINTER** | A parameter value is invalid or **NULL**. |
| **WU_E_NOT_SUPPORTED** | The collection is read-only. |

## See also

[IUpdateCollection](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatecollection)