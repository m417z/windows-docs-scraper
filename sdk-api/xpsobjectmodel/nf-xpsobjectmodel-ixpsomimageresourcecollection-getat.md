# IXpsOMImageResourceCollection::GetAt

## Description

Gets an [IXpsOMImageResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomimageresource) interface pointer from a specified location in the collection.

## Parameters

### `index` [in]

The zero-based index of the [IXpsOMImageResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomimageresource) interface pointer to be obtained.

### `object` [out, retval]

The [IXpsOMImageResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomimageresource) interface pointer at the location specified by *index*.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## Remarks

For more information about the collection methods, see [Working with XPS OM Collection Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/dd372931(v=vs.85)).

## See also

[IXpsOMImageResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomimageresource)

[IXpsOMImageResourceCollection](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomimageresourcecollection)

[Working with XPS OM Collection Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/dd372931(v=vs.85))

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)