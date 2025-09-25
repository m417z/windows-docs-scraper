# IValueMap::Add

## Description

Adds an item to the collection.

## Parameters

### `value` [in]

An **IDispatch** interface of the [IValueMapItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-ivaluemapitem) interface to add to the collection. The variant type is VT_DISPATCH.

You can also add a string or integer value. If the value is an integer (the variant type is VT_I4, VT_UI4, VT_I8, or VT_UI8), PLA adds an item with the specified value.

If the value is a string (the variant type is VT_BSTR), PLA tries to convert the string to an integer. If successful, PLA adds an item with the specified integer value. If PLA cannot convert the string, PLA searches the collection for a key that matches the string. If found, PLA enables the item; otherwise, the add fails.

## Return value

Returns S_OK if successful.

## See also

[IValueMap](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-ivaluemap)

[IValueMap::AddRange](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemap-addrange)

[IValueMap::Remove](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemap-remove)