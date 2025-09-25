# IXpsOMPartUriCollection::SetAt

## Description

Replaces an [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) interface pointer at a specified location in the collection.

## Parameters

### `index` [in]

The zero-based index of the collection where an [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) interface pointer is to be replaced.

### `partUri` [in]

The [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) interface pointer that will replace current contents at the location specified by *index*.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## Remarks

At the location specified by *index*, this method releases the [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) interface referenced by the existing pointer, then writes the pointer that is passed in *partUri*.

For more information about the collection methods, see [Working with XPS OM Collection Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/dd372931(v=vs.85)).

## See also

[IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi)

[IXpsOMPartUriCollection](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomparturicollection)

[Working with XPS OM Collection Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/dd372931(v=vs.85))

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)