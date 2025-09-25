# IStringCollection::Insert

## Description

Inserts an item into the collection at the specified position.

## Parameters

### `index` [in]

The position at which a new string is inserted.

### `value` [in]

The string to be inserted.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

This method can also return the following error codes.

| Return code | Description |
| --- | --- |
| **WU_E_NOT_SUPPORTED** | The collection is read-only. |
| **WU_E_INVALIDINDEX** | An index is invalid. |

## See also

[IStringCollection](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-istringcollection)