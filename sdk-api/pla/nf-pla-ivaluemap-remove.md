# IValueMap::Remove

## Description

Removes an item from the collection.

## Parameters

### `value` [in]

The zero-based index of the item to remove from the collection. The variant type can be VT_I4, VT_UI4, or VT_DISPATCH.

## Return value

Returns S_OK if successful.

## Remarks

If the variant type is VT_DISPATCH, pass the **IDispatch** interface of the [IValueMapItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-ivaluemapitem) interface to be removed.

## See also

[IValueMap](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-ivaluemap)

[IValueMap::Add](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemap-add)

[IValueMap::Clear](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemap-clear)