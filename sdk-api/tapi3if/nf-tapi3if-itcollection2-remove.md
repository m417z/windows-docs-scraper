# ITCollection2::Remove

## Description

The
**Remove** method deletes an item from the collection at the specified index.

## Parameters

### `Index` [in]

Specifies the location in the collection of the item to remove.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The *Index* parameter does not specify a valid index. |
| **E_OUTOFMEMORY** | There is not enough memory to reallocate the collection. |

## See also

[Add](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcollection2-add)

[ITCollection2](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection2)