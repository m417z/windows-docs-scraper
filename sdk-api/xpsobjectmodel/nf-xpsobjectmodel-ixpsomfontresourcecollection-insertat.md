# IXpsOMFontResourceCollection::InsertAt

## Description

Inserts an [IXpsOMFontResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomfontresource) interface pointer at a specified location in the collection.

## Parameters

### `index` [in]

The zero-based index in the collection where the interface pointer that is passed in *value* is to be inserted.

### `value` [in]

The [IXpsOMFontResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomfontresource) interface pointer that is to be inserted at the location specified by *index*.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## Remarks

At the location specified by *index*, this method inserts the [IXpsOMFontResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomfontresource) interface pointer that is passed in *value*. Prior to the insertion, the pointer in this and all subsequent locations is moved up by one index.

For more information about the collection methods, see [Working with XPS OM Collection Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/dd372931(v=vs.85)).

## See also

[IXpsOMFontResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomfontresource)

[IXpsOMFontResourceCollection](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomfontresourcecollection)

[Working with XPS OM Collection Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/dd372931(v=vs.85))

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)