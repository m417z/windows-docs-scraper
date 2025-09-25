# IXpsOMPageReferenceCollection::InsertAt

## Description

Inserts an [IXpsOMPageReference](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompagereference) interface pointer at a specified location in the collection.

## Parameters

### `index` [in]

The zero-based index in the collection where the interface pointer that is passed in *pageReference* is to be inserted.

### `pageReference` [in]

The [IXpsOMPageReference](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompagereference) interface pointer that is to be inserted at the location specified by *index*.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## Remarks

At the location specified by *index*, this method inserts the [IXpsOMPageReference](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompagereference) interface pointer that is passed in *pageReference*. Prior to the insertion, the pointer in this and all subsequent locations is moved up by one index.

For more information about the collection methods, see [Working with XPS OM Collection Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/dd372931(v=vs.85)).

## See also

[IXpsOMPageReference](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompagereference)

[IXpsOMPageReferenceCollection](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompagereferencecollection)

[Working with XPS OM Collection Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/dd372931(v=vs.85))

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)