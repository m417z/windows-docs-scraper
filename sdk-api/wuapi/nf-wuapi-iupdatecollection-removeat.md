# IUpdateCollection::RemoveAt

## Description

Removes the item at the specified index from the collection.

## Parameters

### `index` [in]

The index of the interface to be removed.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

This method can also return the following error codes.

| Return code | Description |
| --- | --- |
| **WU_E_NOT_SUPPORTED** | The collection is read-only. |
| **WU_E_INVALIDINDEX** | An index is invalid. |

## See also

[IUpdateCollection](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatecollection)