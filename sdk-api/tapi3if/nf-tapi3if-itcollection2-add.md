# ITCollection2::Add

## Description

The
**Add** method inserts a new item into the collection at the specified index.

## Parameters

### `Index` [in]

Specifies the location in the collection where the item should be added.

### `pVariant` [in]

Pointer to a **VARIANT** containing the item to add.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pVariant* parameter is not a valid pointer. |
| **E_INVALIDARG** | The *Index* parameter does not specify a valid index. |
| **E_OUTOFMEMORY** | There is not enough memory to reallocate the collection. |

## See also

[ITCollection2](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection2)

[Remove](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcollection2-remove)