# ITCollection::get_Item

## Description

The
**get_Item** method, given an index, returns an item in the collection.

## Parameters

### `Index` [in]

Index of item to be retrieved.

### `pVariant` [out]

Pointer to item returned.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## See also

[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection)