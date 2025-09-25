# IXpsOMImageResourceCollection::GetByPartName

## Description

Gets an [IXpsOMImageResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomimageresource) interface pointer from the collection by matching the interface's part name.

## Parameters

### `partName` [in]

The part name of the interface that is to be found in the collection.

### `part` [out, retval]

The [IXpsOMImageResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomimageresource) interface whose part name matches *partName*. If a matching interface is not found in the collection, a **NULL** pointer is returned.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## See also

[IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi)

[IXpsOMImageResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomimageresource)

[IXpsOMImageResourceCollection](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomimageresourcecollection)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)